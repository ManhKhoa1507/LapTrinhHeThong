.section .data
thuong:
    .string "Chu thuong"
hoa: 
    .string "Chu hoa"

.section bss
    .lcomm input, 1
    .lcomm temp, 1

.section .text
    .globl _start

_start: 
    movl $2, %edx           # Lay input
    movl $input, %ecx
    movl $1, %ebx
    movl $3, %eax
    int $0x80

    movl $input, %eax       # Di chuyen input den thanh ghi %eax
    mov 0(%eax),%bl        
   
    movl $97, temp          # Tao 1 bien temp voi gia tri 97 vao so sanh voi gia tri nay

    cmp temp, %bl
    jge _InThuong           # Neu ma ASCII hien tai >= 97

    movl $8, %edx           # In hoa
    movl $hoa, %ecx
    movl $1, %ebx
    movl $4, %eax
    int $0x80
    jmp _Done

_InThuong:                  # In thuong
    movl $10, %edx
    movl $thuong, %ecx
    movl $1, %ebx
    movl $4, %eax
    int $0x80
    jmp _Done

_Done:                      # Ket thuc chuong trinh 
    movl $1, %eax
    int $0x80
