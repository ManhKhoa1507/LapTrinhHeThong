.section .bss
    .lcomm input, 3
    
.section .text 
    .globl _start

_start :
    movl $4, %edx       ;get the input
    movl $input, %ecx
    movl $0, %ebx
    movl $3, %eax
    int $0x80
    
    movl $input, %eax   ; convert to UpperCase
    mov 0(%eax), %bh    ; -32 in ASCII
    sub $32, %bh
    mov %bh, 0(%eax)

    mov 1(%eax), %bh 
    sub $32, %bh
    mov %bh, 1(%eax)
    
    mov 2(%eax), %bh
    sub $32, %bh
    mov %bh, 2(%eax)

    movl $4, %edx       ; Print the result
    movl %eax, %ecx
    movl $4, %eax
    movl $1, %ebx
    int $0x80

    movl $1, %eax
    int $0x80
