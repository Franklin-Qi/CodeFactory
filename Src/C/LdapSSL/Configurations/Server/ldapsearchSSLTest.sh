#!/usr/bin/bash

ldapsearch -x -D "cn=ldapadm,dc=itzgeek,dc=local" -w 123456 -b "dc=itzgeek,dc=local" -H ldaps://10.10.1.61:636 -d127 -ZZ
