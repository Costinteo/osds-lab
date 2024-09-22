#!/usr/bin/env python3

from pwn import *

# you have to set this before using asm()
context.update(arch='amd64', os='linux')

target = process("./bin/ex4")

payload = shellcraft.amd64.linux.echo("shellcraft is powerful!")

print(f"Dissassembly: {payload}")

payload = asm(payload)
print(f"Bytecode: {payload}")

# get the leak here by parsing from target.recvline()

# craft your payload
# payload = ...

#target.send(payload)
#target.interactive()


# you can also do it by hand, with asm()
# u64() unpacks bytestrings to numbers

craft_payload = asm(shellcraft.amd64.mov("rdi", u64(b"/bin/cat")))
hand_payload = asm(f"mov rdi, {u64(b'/bin/cat')}")

print(f"AUTO-CRAFTED:\n{disasm(craft_payload)}")
print(f"HAND-CRAFTED:\n{disasm(hand_payload)}")

# They are the same in this case
# but sometimes you want more control over your payloads

# Chain the manual assembly:

manual = asm("mov rdi, 10")
manual += asm("xor rdi, 1")

print(f"MANUAL:\n{disasm(manual)}")
