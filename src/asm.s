.data
format_print_str: .asciz "%s\n"
format_print_int: .asciz "%ld\n"
format_print_true: .asciz "True\n"
format_print_false: .asciz "False\n"
.text
.globl main
add:
pushq %rbp
movq %rsp, %rbp
subq $32, %rsp
movq 16(%rbp), %rdx
movq %rdx, -8(%rbp)
movq 24(%rbp), %rdx
movq %rdx, -16(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -24(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -32(%rbp)
movq -24(%rbp), %rcx
movq -32(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -24(%rbp)
movq -24(%rbp), %rax
leave
ret
main:
pushq %rbp
movq %rsp, %rbp
subq $56, %rsp
movq $1078, %rdx
movq %rdx, -8(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -16(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -24(%rbp)
movq $9, %rdx
movq %rdx, -32(%rbp)
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
movq -24(%rbp), %rdx
pushq %rdx
movq -32(%rbp), %rdx
pushq %rdx
call add
movq %rax, -40(%rbp)
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
movq -40(%rbp), %rdx
movq %rdx, -48(%rbp)
movq -48(%rbp), %rdx
movq %rdx, -56(%rbp)
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
movq -56(%rbp), %rdx
pushq %rdx
call print_int
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
