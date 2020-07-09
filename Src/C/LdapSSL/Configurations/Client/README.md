Add follow contents to /etc/nslcd.conf:

tls_reqcert allow
ssl start_tls
tls_cacertdir /etc/openldap/cacerts
