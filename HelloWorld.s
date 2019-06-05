#Assembly Hello World
#Gordon Stangler
#Yeah, this is about as basic as possible, but it works as filler for a portfolio until I can get better stuff in.
#This runs on 64 bit Linux, only
#Compile and run with gcc -c HelloWorld.s && ld HelloWorld.o && ./a.out

global _start

section .text
_start:	mov	rax, 1
	mov	rdi, 1
	mov	rsi, message
	mov	rdx, 13
	syscall
	mov	rax, 60
	xor	rdi, rdi
	syscall

section .data
message	db	"Hello World", 10
