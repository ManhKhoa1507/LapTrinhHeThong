.section .data
rs:
    .string "Love UIT"      ;define the string
rs_len = . -rs              ;get the string length

len:
    .int (rs_len + 48) - 1  ;convert the int to string

.section .text
    .globl _start

_start:
    movl $1, %edx           ;system call sys_write 
    movl $len, %ecx
    movl $1, %ebx
    movl $4, %eax
    int $0x80
    movl $1, %eax           ; system exit
    int $0x80
