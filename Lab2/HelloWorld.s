.section .data
output:
    .string "Hello World"
.section .text 
    .globl _start
_start:
    movl $13, %edx
    movl $output, %ecx
    movl $1, %ebx
    movl $4, %eax
    int $0x80
    movl $1,%eax
    int $0x80
