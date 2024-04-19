.data
format_print_str: .asciz "%s\n"
format_print_int: .asciz "%ld\n"
format_print_true: .asciz "True\n"
format_print_false: .asciz "False\n"
string1: .asciz "Element is present at index:"
string2: .asciz "Element is not present"
string3: .asciz "__main__"
.text
.globl main
binarySearch:
pushq %rbp
movq %rsp, %rbp
subq $264, %rsp
movq 16(%rbp), %rdx
movq %rdx, -8(%rbp)
movq 24(%rbp), %rdx
movq %rdx, -16(%rbp)
movq 32(%rbp), %rdx
movq %rdx, -24(%rbp)
movq 40(%rbp), %rdx
movq %rdx, -32(%rbp)
movq $0, %rdx
movq %rdx, -40(%rbp)
movq -40(%rbp), %rdx
movq %rdx, -48(%rbp)
movq -48(%rbp), %rdx
movq %rdx, -56(%rbp)
movq -8(%rbp), %rcx
movq -56(%rbp), %rdx
addq $1, %rdx
imulq $8, %rdx
addq %rdx, %rcx
movq (%rcx), %rdx
movq %rdx, -64(%rbp)
movq -64(%rbp), %rdx
movq %rdx, -72(%rbp)
.L4:
movq -24(%rbp), %rdx
movq %rdx, -80(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -88(%rbp)
movq -80(%rbp), %rdx
movq -88(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
setle %dl
movq %rdx, -80(%rbp)
movq -80(%rbp), %rdx
cmp $0, %rdx
jg .L5
jmp .L11
.L5:
movq -24(%rbp), %rdx
movq %rdx, -112(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -120(%rbp)
movq -24(%rbp), %rdx
movq %rdx, -128(%rbp)
movq -120(%rbp), %rcx
movq -128(%rbp), %rdx
subq %rdx, %rcx
movq %rcx, -120(%rbp)
movq $2, %rdx
movq %rdx, -136(%rbp)
movq -120(%rbp), %rax
cdq
idivq -136(%rbp)
movq %rax, -120(%rbp)
movq -112(%rbp), %rcx
movq -120(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -112(%rbp)
movq -112(%rbp), %rdx
movq %rdx, -144(%rbp)
movq -144(%rbp), %rdx
movq %rdx, -152(%rbp)
movq -8(%rbp), %rcx
movq -152(%rbp), %rdx
addq $1, %rdx
imulq $8, %rdx
addq %rdx, %rcx
movq (%rcx), %rdx
movq %rdx, -160(%rbp)
movq -160(%rbp), %rdx
movq %rdx, -168(%rbp)
movq -144(%rbp), %rdx
movq %rdx, -176(%rbp)
movq -8(%rbp), %rcx
movq -176(%rbp), %rdx
addq $1, %rdx
imulq $8, %rdx
addq %rdx, %rcx
movq (%rcx), %rdx
movq %rdx, -184(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -192(%rbp)
movq -184(%rbp), %rdx
movq -192(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
sete %dl
movq %rdx, -184(%rbp)
movq -184(%rbp), %rdx
cmp $0, %rdx
jg .L6
jmp .L7
.L6:
movq -144(%rbp), %rdx
movq %rdx, -200(%rbp)
movq -200(%rbp), %rax
leave
ret
jmp .L10
.L7:
movq -144(%rbp), %rdx
movq %rdx, -208(%rbp)
movq -8(%rbp), %rcx
movq -208(%rbp), %rdx
addq $1, %rdx
imulq $8, %rdx
addq %rdx, %rcx
movq (%rcx), %rdx
movq %rdx, -216(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -224(%rbp)
movq -216(%rbp), %rdx
movq -224(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
setl %dl
movq %rdx, -216(%rbp)
movq -216(%rbp), %rdx
cmp $0, %rdx
jg .L8
jmp .L9
.L8:
movq -144(%rbp), %rdx
movq %rdx, -232(%rbp)
movq $1, %rdx
movq %rdx, -240(%rbp)
movq -232(%rbp), %rcx
movq -240(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -232(%rbp)
movq -232(%rbp), %rdx
movq %rdx, -24(%rbp)
jmp .L10
.L9:
movq -144(%rbp), %rdx
movq %rdx, -248(%rbp)
movq $1, %rdx
movq %rdx, -256(%rbp)
movq -248(%rbp), %rcx
movq -256(%rbp), %rdx
subq %rdx, %rcx
movq %rcx, -248(%rbp)
movq -248(%rbp), %rdx
movq %rdx, -32(%rbp)
.L10:
jmp .L4
.L11:
movq $1, %rdx
movq %rdx, -264(%rbp)
movq -264(%rbp), %rcx
movq $0, %rdx
subq %rcx, %rdx
movq %rdx, -264(%rbp)
movq -264(%rbp), %rax
leave
ret
leave
ret
main:
pushq %rbp
movq %rsp, %rbp
subq $192, %rsp
movq $3, %rdx
movq %rdx, -8(%rbp)
movq $5, %rdx
movq %rdx, -16(%rbp)
movq $6, %rdx
movq %rdx, -24(%rbp)
movq $7, %rdx
movq %rdx, -32(%rbp)
movq $8, %rdx
movq %rdx, -40(%rbp)
movq $9, %rdx
movq %rdx, -48(%rbp)
movq $56, %rdx
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
call mem_alloc
movq %rax, -64(%rbp)
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
movq -64(%rbp), %rdx
movq %rdx, -72(%rbp)
movq -72(%rbp), %rdx
movq $6, %rcx
movq %rcx, (%rdx)
movq -72(%rbp), %rcx
movq $8, %rdx
addq %rdx, %rcx
movq %rcx, -72(%rbp)
movq -72(%rbp), %rdx
movq -8(%rbp), %rcx
movq %rcx, (%rdx)
movq -72(%rbp), %rcx
movq $8, %rdx
addq %rdx, %rcx
movq %rcx, -72(%rbp)
movq -72(%rbp), %rdx
movq -16(%rbp), %rcx
movq %rcx, (%rdx)
movq -72(%rbp), %rcx
movq $8, %rdx
addq %rdx, %rcx
movq %rcx, -72(%rbp)
movq -72(%rbp), %rdx
movq -24(%rbp), %rcx
movq %rcx, (%rdx)
movq -72(%rbp), %rcx
movq $8, %rdx
addq %rdx, %rcx
movq %rcx, -72(%rbp)
movq -72(%rbp), %rdx
movq -32(%rbp), %rcx
movq %rcx, (%rdx)
movq -72(%rbp), %rcx
movq $8, %rdx
addq %rdx, %rcx
movq %rcx, -72(%rbp)
movq -72(%rbp), %rdx
movq -40(%rbp), %rcx
movq %rcx, (%rdx)
movq -72(%rbp), %rcx
movq $8, %rdx
addq %rdx, %rcx
movq %rcx, -72(%rbp)
movq -72(%rbp), %rdx
movq -48(%rbp), %rcx
movq %rcx, (%rdx)
movq -64(%rbp), %rdx
movq %rdx, -80(%rbp)
movq -80(%rbp), %rdx
movq %rdx, -88(%rbp)
movq $6, %rdx
movq %rdx, -96(%rbp)
movq $0, %rdx
movq %rdx, -104(%rbp)
movq -80(%rbp), %rcx
movq (%rcx), %rdx
movq %rdx, -112(%rbp)
movq $1, %rdx
movq %rdx, -120(%rbp)
movq -112(%rbp), %rcx
movq -120(%rbp), %rdx
subq %rdx, %rcx
movq %rcx, -112(%rbp)
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
movq -112(%rbp), %rdx
pushq %rdx
movq -104(%rbp), %rdx
pushq %rdx
movq -96(%rbp), %rdx
pushq %rdx
movq -88(%rbp), %rdx
pushq %rdx
call binarySearch
movq %rax, -128(%rbp)
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
movq -128(%rbp), %rdx
movq %rdx, -136(%rbp)
movq -136(%rbp), %rdx
movq %rdx, -144(%rbp)
movq $1, %rdx
movq %rdx, -152(%rbp)
movq -152(%rbp), %rcx
movq $0, %rdx
subq %rcx, %rdx
movq %rdx, -152(%rbp)
movq -144(%rbp), %rdx
movq -152(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
setne %dl
movq %rdx, -144(%rbp)
movq -144(%rbp), %rdx
cmp $0, %rdx
jg .L12
jmp .L13
.L12:
lea string1(%rip), %rdx
movq %rdx, -176(%rbp)
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
movq -176(%rbp), %rdx
pushq %rdx
call print_str
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
movq -136(%rbp), %rdx
movq %rdx, -184(%rbp)
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
movq -184(%rbp), %rdx
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
jmp .L14
.L13:
lea string2(%rip), %rdx
movq %rdx, -192(%rbp)
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
movq -192(%rbp), %rdx
pushq %rdx
call print_str
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
.L14:
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
