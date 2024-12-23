section .rodata
    gift db '/bin/sh', 0
	msg db 'Hello hacker! Feel free to go insane...', 10, 0

section .text
	global _start

intro:
	mov rax, 1
	mov rdi, 1
	mov rsi, msg
	mov rdx, 40
	syscall
	ret

read_buf:
	sub rsp, 64
	mov rax, 0
	mov rdi, 0
	mov rsi, rsp
	mov rdx, 512
	syscall
	add rsp, 64
	ret

_start:
	call intro
	call read_buf
	mov rax, 60
	xor rdi, rdi
	syscall
