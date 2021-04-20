.section .data
rs:
    .string "Love UIT"      # Dinh nghia 1 string
rs_len = . -rs              # Lay chieu dai cua string

len:
    .int (rs_len + 48) - 1  # Chuyen doi do dai string hien tai (Kieu ASCII) sang string

.section .text
    .globl _start

_start:
    movl $1, %edx           # In do dai cua string 
    movl $len, %ecx
    movl $1, %ebx
    movl $4, %eax
    int $0x80
    movl $1, %eax           
    int $0x80
