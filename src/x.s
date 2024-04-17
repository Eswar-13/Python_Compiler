.data
format_print_str: .asciz "%s\n"
format_print_int: .asciz "%ld\n"
format_print_true: .asciz "True\n"
format_print_false: .asciz "False\n"
.text
.globl main
main:
pushq %rbp
movq %rsp, %rbp
subq $16, %rsp
movq $1, %rdx
movq %rdx, -16(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -8(%rbp)
leave
ret
print_int:
pushq %rbp
movq %rsp, %rbp
movq 16(%rbp), %rsi
lea format_print_int(%rip), %rdi
xorq %rax, %rax
callq printf@plt
leave
ret
print_bool:
pushq %rbp
movq %rsp, %rbp
movq 16(%rbp), %rcx
cmp $0, %rcx
jne print_true_label
lea format_print_false(%rip), %rdi
jmp print_false_exit
print_true_label:
lea format_print_true(%rip), %rdi
print_false_exit:
xorq %rax, %rax
callq printf@plt
leave
ret
print_str:
pushq %rbp
movq %rsp, %rbp
movq 16(%rbp), %rsi
lea format_print_str(%rip), %rdi
xorq %rax, %rax
callq printf@plt
leave
ret
allocmem:
pushq %rbp
movq %rsp, %rbp
movq 16(%rbp), %rdi
callq malloc
leave
ret
strcmpl:
pushq %rbp
movq %rsp, %rbp
movq 16(%rbp), %rdi
movq 24(%rbp), %rsi
callq strcmp
cmp $0, %eax
movq $0, %rdx
setl %dl
movq %rdx, %rax
leave
ret
strcmpg:
pushq %rbp
movq %rsp, %rbp
movq 16(%rbp), %rdi
movq 24(%rbp), %rsi
callq strcmp
cmp $0, %eax
movq $0, %rdx
setg %dl
movq %rdx, %rax
leave
ret
strcmpe:
pushq %rbp
movq %rsp, %rbp
movq 16(%rbp), %rdi
movq 24(%rbp), %rsi
callq strcmp
cmp $0, %eax
movq $0, %rdx
sete %dl
movq %rdx, %rax
leave
ret
strcmpne:
pushq %rbp
movq %rsp, %rbp
movq 16(%rbp), %rdi
movq 24(%rbp), %rsi
callq strcmp
cmp $0, %eax
movq $0, %rdx
setne %dl
movq %rdx, %rax
leave
ret
strcmple:
pushq %rbp
movq %rsp, %rbp
movq 16(%rbp), %rdi
movq 24(%rbp), %rsi
callq strcmp
cmp $0, %eax
movq $0, %rdx
setle %dl
movq %rdx, %rax
leave
ret
strcmpge:
pushq %rbp
movq %rsp, %rbp
movq 16(%rbp), %rdi
movq 24(%rbp), %rsi
callq strcmp
cmp $0, %eax
movq $0, %rdx
setge %dl
movq %rdx, %rax
leave
ret
.power:
pushq %rbp
movq %rsp, %rbp
subq $-32, %rsp
movq    $0, -24(%rbp)
movq    $1, -32(%rbp)
        jmp     .L2
.L3:
        movq    -32(%rbp), %rax
        imulq   16(%rbp), %rax
        movq    %rax, -32(%rbp)
        addq    $1, -24(%rbp)
.L2:
        movq    -24(%rbp), %rax
        cmpq    24(%rbp), %rax
        jl      .L3
        movq    -32(%rbp), %rax
leave
ret