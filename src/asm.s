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
subq $136, %rsp
movq $6, %rdx
movq %rdx, -8(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -16(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -24(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -40(%rbp)
movq $9, %rdx
movq %rdx, -48(%rbp)
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
movq -40(%rbp), %rdx
pushq %rdx
movq -48(%rbp), %rdx
pushq %rdx
call add
movq %rax, -56(%rbp)
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
movq -56(%rbp), %rdx
movq %rdx, -64(%rbp)
movq $0, %rdx
movq %rdx, -72(%rbp)
movq -72(%rbp), %rdx
movq %rdx, -80(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -88(%rbp)
movq $1, %rdx
movq %rdx, -96(%rbp)
movq $2, %rdx
movq %rdx, -104(%rbp)
movq -96(%rbp), %rcx
movq -104(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -96(%rbp)
movq $3, %rdx
movq %rdx, -112(%rbp)
movq -96(%rbp), %rcx
movq -112(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -96(%rbp)
movq $4, %rdx
movq %rdx, -120(%rbp)
movq -96(%rbp), %rcx
movq -120(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -96(%rbp)
movq -96(%rbp), %rdx
movq %rdx, -16(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -128(%rbp)
movq $1, %rdx
movq %rdx, -136(%rbp)
movq -128(%rbp), %rdx
movq -136(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
setg %dl
movq %rdx, -128(%rbp)
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
movq -128(%rbp), %rdx
pushq %rdx
call print_bool
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
