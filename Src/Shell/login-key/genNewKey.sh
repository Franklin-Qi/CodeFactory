#!/bin/bash

key_timeStamp=$1
authKeyLen=$2
homedir=$3

expect <<- EOF
	spawn ssh-keygen -b $authKeyLen
	expect "ssh/id_rsa):"
	send "$homedir/.ssh/id_rsa$key_timeStamp\r"

	expect {
		"Overwrite (y/n)?" { send "y\r";exp_continue }
		"passphrase):" { send "\r" }
	}
	expect "passphrase again:"
	send "\r"
	expect eof

EOF
chmod 600 $homedir/.ssh/id_rsa$key_timeStamp
