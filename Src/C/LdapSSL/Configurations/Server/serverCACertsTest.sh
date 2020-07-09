#!/usr/bin/bash

openssl s_client -connect 172.16.1.61:636 -showcerts -state -CAfile /etc/openldap/certs/itzgeekrootCA.pem
