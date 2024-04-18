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
subq $160, %rsp
movq $2, %rdx
movq %rdx, -8(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -16(%rbp)
movq $4, %rdx
movq %rdx, -24(%rbp)
movq -24(%rbp), %rdx
movq %rdx, -32(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -40(%rbp)
movq $2, %rdx
movq %rdx, -48(%rbp)
movq -40(%rbp), %rax
cdq
idivq -48(%rbp)
movq %rax, -40(%rbp)
movq -40(%rbp), %rdx
movq %rdx, -56(%rbp)
movq -56(%rbp), %rdx
movq %rdx, -64(%rbp)
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
movq -64(%rbp), %rdx
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
movq $158, %rdx
movq %rdx, -72(%rbp)
movq -72(%rbp), %rdx
movq %rdx, -80(%rbp)
movq $34, %rdx
movq %rdx, -88(%rbp)
movq -88(%rbp), %rdx
movq %rdx, -96(%rbp)
movq -80(%rbp), %rdx
movq %rdx, -104(%rbp)
movq -96(%rbp), %rdx
movq %rdx, -112(%rbp)
movq -104(%rbp), %rax
cdq
idivq -112(%rbp)
movq %rax, -104(%rbp)
movq -104(%rbp), %rdx
movq %rdx, -120(%rbp)
movq -80(%rbp), %rdx
movq %rdx, -128(%rbp)
movq -96(%rbp), %rdx
movq %rdx, -136(%rbp)
movq -128(%rbp), %rax
cdq
idivq -136(%rbp)
movq %rdx, -128(%rbp)
movq -128(%rbp), %rdx
movq %rdx, -144(%rbp)
movq -120(%rbp), %rdx
movq %rdx, -152(%rbp)
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
movq -152(%rbp), %rdx
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
movq -144(%rbp), %rdx
movq %rdx, -160(%rbp)
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
movq -160(%rbp), %rdx
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
mem_alloc:
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
