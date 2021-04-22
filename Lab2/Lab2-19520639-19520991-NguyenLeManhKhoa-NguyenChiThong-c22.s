.section .bss
    .lcomm input, 3
    
.section .text 
    .globl _start

_start :
    movl $4, %edx       # Nhap input
    movl $input, %ecx
    movl $0, %ebx
    movl $3, %eax
    int $0x80
    
    movl $input, %eax   # Chuyen doi chu thuong sang in hoa
    mov 0(%eax), %bh    # Bang cach - 32
    sub $32, %bh
    mov %bh, 0(%eax)

    mov 1(%eax), %bh 
    sub $32, %bh
    mov %bh, 1(%eax)
    
    mov 2(%eax), %bh
    sub $32, %bh
    mov %bh, 2(%eax)

    movl $4, %edx       # In string sau khi duoc chuyen doi 
    movl %eax, %ecx
    movl $4, %eax
    movl $1, %ebx
    int $0x80

    movl $1, %eax
    int $0x80
