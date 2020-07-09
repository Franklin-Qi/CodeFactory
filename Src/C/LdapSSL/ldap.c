/*  Copyright (C) 2019 * Ltd. All rights reserved.
 *      Create date : 2019-03-27 16:50:26
 *================================================*/
#include <stdio.h>
#include <string.h>
#include <lber.h>
#include <ldap.h>


/* Adjust these setting for your own LDAP server */ 
#define LDAP_SERVER "ldaps://172.16.1.61:636" // LDAP Server URL
#define CA_CERTFILE "/etc/openldap/cacerts/ca-bundle.crt"   // LDAP Server CA  
#define BASEDN "dc=itzgeek,dc=local"  // BASEDN
#define FIND_DN "uid=raj,ou=People,dc=itzgeek,dc=local"  // raj DN
#define LDAP_SCOPE_TYPE LDAP_SCOPE_SUBTREE //search type: SUBTREE(search all)


int main( int argc, char **argv )
{ 
    LDAP         *ld; 
    LDAPMessage  *result, *e; 
    BerElement   *ber; 
    char         *a, **vals; 
    int          i, rc; 
    int          i_ret;
    int          require_cert;

    /* get a handle to an ldap connection. create a ldap instant. */ 
    //if ( (ld = ldap_init( HOSTNAME, PORT_NUMBER )) == NULL ) { 
    i_ret = ldap_initialize(&ld, LDAP_SERVER); 
    if(i_ret != LDAP_SUCCESS || ld == NULL)
    {
        perror( "ldap_initialize error\n" ); 
        return -1; 
    } 
    printf("Connecting as %s...\n", LDAP_SERVER);


     /* Set LDAP protocol version used
      * deal with: ldap_simple_bind_s: Protocol error */
    int protocol_version = LDAP_VERSION3;
    rc = ldap_set_option(ld, LDAP_OPT_PROTOCOL_VERSION, &protocol_version);
    if (rc != LDAP_SUCCESS) 
    {
        fprintf(stderr, "ldap_simple_bind_s: %s\n", ldap_err2string(rc));
        return -1;
    }
    printf("Protocol Version: LDAPv3\n");


    /* Set path name of file containing all trusted CA certificates
     * only at GOBAL level, which means the first parameter must be NULL */
    i_ret = ldap_set_option(ld, LDAP_OPT_X_TLS_CACERTFILE, CA_CERTFILE);  
    //i_ret = ldap_set_option(ld, LDAP_OPT_X_TLS_CACERTFILE, CA_CERTFILE);  
    if ( i_ret != LDAP_SUCCESS )   
    {
        fprintf(stderr, "set_option LDAP_OPT_X_TLS_CACERTFILE errno %d : %s\n", i_ret, ldap_err2string( i_ret ));  
        return -1;  
    }  
    printf("LDAP Server CA is successful.\n");

    /* Force cert validation: allow */
    require_cert = LDAP_OPT_X_TLS_ALLOW;
    i_ret = ldap_set_option(ld, LDAP_OPT_X_TLS_REQUIRE_CERT, &require_cert);
    if ( i_ret != LDAP_SUCCESS )
    {
        fprintf(stderr, "set_option LDAP_OPT_X_TLS_REQUIRE_CERT errno %d : %s\n", i_ret, ldap_err2string( i_ret ));
        return -1;    
    }
    printf("TLS_REQCERT allow.\n");

    /* Force libldap to create a new SSL context */
    int am_server = 0;
    i_ret = ldap_set_option(ld, LDAP_OPT_X_TLS_NEWCTX, &am_server);
    if ( i_ret != LDAP_SUCCESS )     
    {    
        fprintf(stderr, "set_option LDAP_OPT_X_TLS_NEWCTX errno %d : %s\n", i_ret, ldap_err2string( i_ret ));
        return -1;
    }
    printf("Create a new SSL context.\n");

    /* Another method: Now try StartTLS extended operation
     * start_tls_s() */
    
    /* Bind anonymously to the LDAP server.  
    rc = ldap_bind_s( ld, NULL, NULL, LDAP_AUTH_SIMPLE ); 
    rc = ldap_simple_bind_s( ld, "uid=raj,ou=People,dc=itzgeek,dc=local", "password123"); 
    rc = ldap_simple_bind_s( ld, "cn=ldapadm,dc=itzgeek,dc=local", "123456"); 
    */
    rc = ldap_simple_bind_s( ld, NULL, NULL ); 
    if ( rc != LDAP_SUCCESS ) 
    { 
        fprintf(stderr, "ldap_simple_bind_s: %s\n", ldap_err2string(rc)); 
        return -1; 
    } 
    printf("ldap_simple_bind_s: bind success.\n");


    /* Search for the entry. */ 
    /*
    if ( ( rc = ldap_search_ext_s( ld, BASEDN, LDAP_SCOPE_BASE, 
    "(objectclass=*)", NULL, 0, NULL, NULL, LDAP_NO_LIMIT, 
    LDAP_NO_LIMIT, &result ) ) != LDAP_SUCCESS ) 
     */
    if ( ( rc = ldap_search_s( ld, FIND_DN, LDAP_SCOPE_TYPE, "(objectclass=*)", NULL, 0,  &result ) ) != LDAP_SUCCESS ) 
    { 
        fprintf(stderr, "ldap_search_s: %s\n", ldap_err2string(rc)); 
        return -1; 
    } 
    printf( "Found DN: %s\n\n", FIND_DN); 

    /* Since we are doing a base search, there should be only one matching entry.  */ 
    e = ldap_first_entry( ld, result ); 
    if ( e != NULL ) 
    { 
        /* Iterate through each attribute in the entry. */ 
        for ( a = ldap_first_attribute( ld, e, &ber ); a != NULL; a = ldap_next_attribute( ld, e, ber ) )
        { 
            /* For each attribute, print the attribute name and values. */ 
            if ((vals = ldap_get_values( ld, e, a)) != NULL ) 
            { 
                for ( i = 0; vals[i] != NULL; i++ ) 
                { 
                    printf( "%s: %s\n", a, vals[i] ); 
                } 
                ldap_value_free( vals ); 
            } 
            ldap_memfree( a ); 
        } 
        if ( ber != NULL ) 
        { 
          ber_free( ber, 0 ); 
        } 
    } 
    ldap_msgfree( result ); 

    /* Close Connection */
    ldap_unbind( ld ); 

    return 0;
}
