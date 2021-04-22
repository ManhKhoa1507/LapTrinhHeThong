.section .data
gradeInput:
    .string "Enter a grade (2-digit) : "
    gradeInput_len = . -gradeInput

good:
    .string "Gioi"
    good_len = . -good

passed:
    .string "Dat"
    passed_len = . -passed

failed:
    .string "Khong Dat"
    failed_len = . -failed 

.section bss
    .lcomm input, 3

.section .text
    .globl _start
 
_start:
    movl $gradeInput_len, %edx          # In ra chuoi Enter a grade(2-digits)
    movl $gradeInput, %ecx             
    movl $1, %ebx
    movl $4, %eax
    int $0x80

    movl $3, %edx                       # Lay input
    movl $input, %ecx
    movl $1, %ebx
    movl $3, %eax
    int $0x80

    movl $input, %eax                   # Chuyen doi input sang kieu int
    mov (%eax), %bl
    sub $48, %bl
    mov 1(%eax), %dl
    sub $48, %dl
    imull $10, %ebx
    addl %ebx, %edx

    cmpl $10, %edx                      # Neu nhap sai input
	jl _Done
	cmpl $99, %edx
	jg _Done
	cmpl $80, %edx                      # Kiem tra loai gioi
	jge _Good
	cmpl $50, %edx                      # Kiem tra loai kha
	jge _Passed
	cmpl $50, %edx                      # Kiem tra loai kem 
	jl _Failed
   

_Good:
    movl $good_len, %edx
    movl $good, %ecx
    movl $1, %ebx
    movl $4, %eax
    int $0x80
    jmp _Done

_Passed:
    movl $passed_len, %edx
    movl $passed, %ecx
    movl $1, %ebx
    movl $4, %eax
    int $0x80
    jmp _Done

_Failed:
    movl $failed_len, %edx
    movl $failed, %ecx
    movl $1, %ebx
    movl $4, %eax
    int $0x80
    jmp _Done

_Done:
    movl $1, %eax
    int $0x80
