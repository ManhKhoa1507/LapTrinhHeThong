.section bss
    .lcomm input, 1

.section .text
    .globl _start

_start: 
    movl $2, %edx           ;Get the input
    movl $input, %ecx
    movl $1, %ebx
    movl $3, %eax
    int $0x80

    movl $input, %eax
    mov 1(%eax), %bl 

    comp %bl, 
