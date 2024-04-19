.data
format_print_str: .asciz "%s\n"
format_print_int: .asciz "%ld\n"
format_print_true: .asciz "True\n"
format_print_false: .asciz "False\n"
string1: .asciz "Shift-Reduce"
.text
.globl main
ShiftReduceParser.__init__:
pushq %rbp
movq %rsp, %rbp
subq $40, %rsp
movq 16(%rbp), %rdx
movq %rdx, -8(%rbp)
movq $1, %rdx
movq %rdx, -16(%rbp)
movq -16(%rbp), %rdx
movq %rdx, 
movq $0, %rdx
movq %rdx, -24(%rbp)
movq -24(%rbp), %rdx
movq %rdx, 
movq $1, %rdx
movq %rdx, -32(%rbp)
movq -40(%rbp), %rcx
movq -32(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -40(%rbp)
movq -40(%rbp), %rdx
movq %rdx, 
leave
ret
main:
pushq %rbp
movq %rsp, %rbp
subq $24, %rsp
lea string1(%rip), %rdx
movq %rdx,-8(%rbp)
pushq %rax
pushq %rcx
pushq %rdx
pushq %rdi
pushq %rsi
pushq %r8
pushq %r9
pushq %r10
pushq %r11
movq %rsp, %rbx
movq %rsp, %rcx
addq $-8, %rcx
andq $15, %rcx
subq %rcx, %rsp
movq -8(%rbp), %rdx
pushq %rdx
call ShiftReduceParser.__init__
movq %rax, -16(%rbp)
movq %rbx, %rsp
popq %r11
popq %r10
popq %r9
popq %r8
popq %rsi
popq %rdi
popq %rdx
popq %rcx
popq %rax
movq -16(%rbp), %rdx
movq %rdx, -24(%rbp)
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
mem_alloc:
pushq %rbp
movq %rsp, %rbp
movq 16(%rbp), %rdi
callq malloc
leave
ret
is_string_less:
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
is_string_greater:
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
is_string_equal:
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
is_string_not_equal:
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
is_string_less_equal:
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
is_string_greater_equal:
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
movq $0, -24(%rbp)
movq $1, -32(%rbp)
jmp .L2
.L3:
movq -32(%rbp), %rax
imulq 16(%rbp), %rax
movq %rax, -32(%rbp)
addq $1, -24(%rbp)
.L2:
movq -24(%rbp), %rax
cmpq 24(%rbp), %rax
jl .L3
movq -32(%rbp), %rax
leave
ret
