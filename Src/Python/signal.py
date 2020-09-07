#! /usr/bin/python
# -*- coding: utf-8 -*-

import signal
import os
import sys

class InputTimeoutError(Exception):
    pass

def interrupted(signum, frame):
    raise InputTimeoutError

signal.signal(signal.SIGALRM, interrupted)
signal.alarm(10)


try:
    name = input('10s 进行输入:')
except InputTimeoutError:
    print ('\ntimeout')
    name = 'noname'

signal.alarm(0)
print('name: %s'%name)
