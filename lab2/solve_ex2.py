#!/usr/bin/env python3

from pwn import *

target = process("./bin/ex2")

payload = b"" # craft the payload

target.send(payload) # notice how we're not using 'sendline' so it does not add a newline

target.interactive()
