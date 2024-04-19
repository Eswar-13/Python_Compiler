.data
format_print_str: .asciz "%s\n"
format_print_int: .asciz "%ld\n"
format_print_true: .asciz "True\n"
format_print_false: .asciz "False\n"
str0: .asciz "hello"
str1: .asciz "x is greater than 10"
str2: .asciz "x is less than 5"
str3: .asciz "x is between 5 and 10"
str4: .asciz "Toyota"
str5: .asciz "Camry"
.text
.globl main
factorial:
pushq %rbp
movq %rsp, %rbp
subq $64, %rsp
movq 16(%rbp), %rdx
movq %rdx, -8(%rbp)
movq $0, %rdx
movq %rdx, -16(%rbp)
movq -8(%rbp), %rdx
movq -16(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
setle %dl
movq %rdx, -8(%rbp)
movq -8(%rbp), %rdx
cmpq $0, %rdx
je L0
movq $1, %rdx
movq %rdx, -24(%rbp)
movq -24(%rbp), %rax
leave
ret
jmp L1
L0:
movq 16(%rbp), %rdx
movq %rdx, -32(%rbp)
movq 16(%rbp), %rdx
movq %rdx, -40(%rbp)
movq $1, %rdx
movq %rdx, -48(%rbp)
movq -40(%rbp), %rcx
movq -48(%rbp), %rdx
subq %rdx, %rcx
movq %rcx, -40(%rbp)
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
call factorial
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
movq -32(%rbp), %rcx
movq -56(%rbp), %rdx
imulq %rdx, %rcx
movq %rcx, -32(%rbp)
movq -32(%rbp), %rax
leave
ret
L1:
movq $1, %rdx
movq %rdx, -64(%rbp)
movq -64(%rbp), %rdx
neg %rdx
movq %rdx, -64(%rbp)
movq -64(%rbp), %rax
leave
ret
area:
pushq %rbp
movq %rsp, %rbp
subq $24, %rsp
movq $0, %rdx
movq %rdx, -16(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -8(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -24(%rbp)
movq -24(%rbp), %rax
leave
ret
Vehicle.__init__:
pushq %rbp
movq %rsp, %rbp
subq $48, %rsp
movq 16(%rbp), %rdx
movq %rdx, -8(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -16(%rbp)
movq $0, %rcx
movq -16(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -16(%rbp)
movq 24(%rbp), %rdx
movq %rdx, -24(%rbp)
movq -16(%rbp), %rdx
movq -24(%rbp), %rcx
movq %rcx, (%rdx)
movq 16(%rbp), %rdx
movq %rdx, -32(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -40(%rbp)
movq $8, %rcx
movq -40(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -40(%rbp)
movq 32(%rbp), %rdx
movq %rdx, -48(%rbp)
movq -40(%rbp), %rdx
movq -48(%rbp), %rcx
movq %rcx, (%rdx)
leave
ret
Vehicle.start:
pushq %rbp
movq %rsp, %rbp
subq $48, %rsp
movq 16(%rbp), %rdx
movq %rdx, -8(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -16(%rbp)
movq $0, %rcx
movq -16(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -16(%rbp)
movq -16(%rbp), %rdx
movq (%rdx), %rcx
movq %rcx, -24(%rbp)
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
movq 16(%rbp), %rdx
movq %rdx, -32(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -40(%rbp)
movq $8, %rcx
movq -40(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -40(%rbp)
movq -40(%rbp), %rdx
movq (%rdx), %rcx
movq %rcx, -48(%rbp)
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
movq -48(%rbp), %rdx
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
leave
ret
Car.__init__:
pushq %rbp
movq %rsp, %rbp
subq $72, %rsp
movq 16(%rbp), %rdx
movq %rdx, -8(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -16(%rbp)
movq $0, %rcx
movq -16(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -16(%rbp)
movq 24(%rbp), %rdx
movq %rdx, -24(%rbp)
movq -16(%rbp), %rdx
movq -24(%rbp), %rcx
movq %rcx, (%rdx)
movq 16(%rbp), %rdx
movq %rdx, -32(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -40(%rbp)
movq $8, %rcx
movq -40(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -40(%rbp)
movq 32(%rbp), %rdx
movq %rdx, -48(%rbp)
movq -40(%rbp), %rdx
movq -48(%rbp), %rcx
movq %rcx, (%rdx)
movq 16(%rbp), %rdx
movq %rdx, -56(%rbp)
movq -56(%rbp), %rdx
movq %rdx, -64(%rbp)
movq $16, %rcx
movq -64(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -64(%rbp)
movq 40(%rbp), %rdx
movq %rdx, -72(%rbp)
movq -64(%rbp), %rdx
movq -72(%rbp), %rcx
movq %rcx, (%rdx)
leave
ret
Car.start:
pushq %rbp
movq %rsp, %rbp
subq $72, %rsp
movq 16(%rbp), %rdx
movq %rdx, -8(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -16(%rbp)
movq $16, %rcx
movq -16(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -16(%rbp)
movq -16(%rbp), %rdx
movq (%rdx), %rcx
movq %rcx, -24(%rbp)
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
movq 16(%rbp), %rdx
movq %rdx, -32(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -40(%rbp)
movq $0, %rcx
movq -40(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -40(%rbp)
movq -40(%rbp), %rdx
movq (%rdx), %rcx
movq %rcx, -48(%rbp)
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
movq -48(%rbp), %rdx
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
movq 16(%rbp), %rdx
movq %rdx, -56(%rbp)
movq -56(%rbp), %rdx
movq %rdx, -64(%rbp)
movq $8, %rcx
movq -64(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -64(%rbp)
movq -64(%rbp), %rdx
movq (%rdx), %rcx
movq %rcx, -72(%rbp)
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
movq -72(%rbp), %rdx
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
leave
ret
main:
pushq %rbp
movq %rsp, %rbp
subq $1120, %rsp
movq $42, %rdx
movq %rdx, -136(%rbp)
movq -136(%rbp), %rdx
movq %rdx, -8(%rbp)
movq $3.14, %rdx
movq %rdx, -144(%rbp)
movq -144(%rbp), %rdx
movq %rdx, -16(%rbp)
lea str0(%rip), %rdx
movq %rdx, -152(%rbp)
movq -152(%rbp), %rdx
movq %rdx, -24(%rbp)
movq $1, %rdx
movq %rdx, -160(%rbp)
movq $2, %rdx
movq %rdx, -168(%rbp)
movq $3, %rdx
movq %rdx, -176(%rbp)
movq $4, %rdx
movq %rdx, -184(%rbp)
movq $5, %rdx
movq %rdx, -192(%rbp)
movq $48, %rdx
movq %rdx, -200(%rbp)
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
movq -200(%rbp), %rdx
pushq %rdx
call allocmem
movq %rax, -200(%rbp)
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
movq -200(%rbp), %rdx
movq %rdx, -208(%rbp)
movq -208(%rbp), %rdx
movq $5, %rcx
movq %rcx, (%rdx)
movq $8, %rcx
movq -208(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -208(%rbp)
movq -208(%rbp), %rdx
movq -160(%rbp), %rcx
movq %rcx, (%rdx)
movq $8, %rcx
movq -208(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -208(%rbp)
movq -208(%rbp), %rdx
movq -168(%rbp), %rcx
movq %rcx, (%rdx)
movq $8, %rcx
movq -208(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -208(%rbp)
movq -208(%rbp), %rdx
movq -176(%rbp), %rcx
movq %rcx, (%rdx)
movq $8, %rcx
movq -208(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -208(%rbp)
movq -208(%rbp), %rdx
movq -184(%rbp), %rcx
movq %rcx, (%rdx)
movq $8, %rcx
movq -208(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -208(%rbp)
movq -208(%rbp), %rdx
movq -192(%rbp), %rcx
movq %rcx, (%rdx)
movq -200(%rbp), %rdx
movq %rdx, -32(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -216(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -224(%rbp)
movq -216(%rbp), %rcx
movq -224(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -216(%rbp)
movq -216(%rbp), %rdx
movq %rdx, -40(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -232(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -240(%rbp)
movq -232(%rbp), %rcx
movq -240(%rbp), %rdx
subq %rdx, %rcx
movq %rcx, -232(%rbp)
movq -232(%rbp), %rdx
movq %rdx, -48(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -248(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -256(%rbp)
movq -248(%rbp), %rcx
movq -256(%rbp), %rdx
imulq %rdx, %rcx
movq %rcx, -248(%rbp)
movq -248(%rbp), %rdx
movq %rdx, -56(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -264(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -272(%rbp)
movq -272(%rbp), %rcx
movq -264(%rbp), %rax
cqto
idivq %rcx
movq %rax, -264(%rbp)
movq -264(%rbp), %rdx
movq %rdx, -64(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -280(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -288(%rbp)
movq -288(%rbp), %rcx
movq -280(%rbp), %rax
cqto
idivq %rcx
movq %rax, -280(%rbp)
movq -280(%rbp), %rdx
movq %rdx, -72(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -296(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -304(%rbp)
movq -304(%rbp), %rcx
movq -296(%rbp), %rax
cqto
idivq %rcx
movq %rdx, -296(%rbp)
movq -296(%rbp), %rdx
movq %rdx, -80(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -312(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -320(%rbp)
movq -312(%rbp), %rdx
movq -320(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
sete %dl
movq %rdx, -312(%rbp)
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
movq -312(%rbp), %rdx
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
movq -8(%rbp), %rdx
movq %rdx, -328(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -336(%rbp)
movq -328(%rbp), %rdx
movq -336(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
setne %dl
movq %rdx, -328(%rbp)
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
movq -328(%rbp), %rdx
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
movq -8(%rbp), %rdx
movq %rdx, -344(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -352(%rbp)
movq -344(%rbp), %rdx
movq -352(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
setg %dl
movq %rdx, -344(%rbp)
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
movq -344(%rbp), %rdx
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
movq -8(%rbp), %rdx
movq %rdx, -360(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -368(%rbp)
movq -360(%rbp), %rdx
movq -368(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
setl %dl
movq %rdx, -360(%rbp)
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
movq -360(%rbp), %rdx
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
movq -8(%rbp), %rdx
movq %rdx, -376(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -384(%rbp)
movq -376(%rbp), %rdx
movq -384(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
setge %dl
movq %rdx, -376(%rbp)
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
movq -376(%rbp), %rdx
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
movq -8(%rbp), %rdx
movq %rdx, -392(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -400(%rbp)
movq -392(%rbp), %rdx
movq -400(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
setle %dl
movq %rdx, -392(%rbp)
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
movq -392(%rbp), %rdx
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
movq $1, %rdx
movq %rdx, -408(%rbp)
movq $0, %rdx
movq %rdx, -416(%rbp)
movq -408(%rbp), %rcx
movq -416(%rbp), %rdx
andq %rdx, %rcx
movq %rcx, -408(%rbp)
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
movq -408(%rbp), %rdx
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
movq $1, %rdx
movq %rdx, -424(%rbp)
movq $0, %rdx
movq %rdx, -432(%rbp)
movq -424(%rbp), %rcx
movq -432(%rbp), %rdx
orq %rdx, %rcx
movq %rcx, -424(%rbp)
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
movq -424(%rbp), %rdx
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
movq $1, %rdx
movq %rdx, -440(%rbp)
movq -440(%rbp), %rcx
movq $1, %rdx
xorq %rdx, %rcx
movq %rcx, -440(%rbp)
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
movq -440(%rbp), %rdx
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
movq $10, %rdx
movq %rdx, -448(%rbp)
movq -448(%rbp), %rdx
movq %rdx, -88(%rbp)
movq $11, %rdx
movq %rdx, -456(%rbp)
movq -456(%rbp), %rdx
movq %rdx, -96(%rbp)
movq -88(%rbp), %rdx
movq %rdx, -464(%rbp)
movq -96(%rbp), %rdx
movq %rdx, -472(%rbp)
movq -464(%rbp), %rcx
movq -472(%rbp), %rdx
andq %rdx, %rcx
movq %rcx, -464(%rbp)
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
movq -464(%rbp), %rdx
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
movq -88(%rbp), %rdx
movq %rdx, -480(%rbp)
movq -96(%rbp), %rdx
movq %rdx, -488(%rbp)
movq -480(%rbp), %rcx
movq -488(%rbp), %rdx
orq %rdx, %rcx
movq %rcx, -480(%rbp)
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
movq -480(%rbp), %rdx
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
movq -88(%rbp), %rdx
movq %rdx, -496(%rbp)
movq -96(%rbp), %rdx
movq %rdx, -504(%rbp)
movq -496(%rbp), %rcx
movq -504(%rbp), %rdx
xorq %rdx, %rcx
movq %rcx, -496(%rbp)
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
movq -496(%rbp), %rdx
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
movq -88(%rbp), %rdx
movq %rdx, -512(%rbp)
movq -512(%rbp), %rdx
not %rdx
movq %rdx, -512(%rbp)
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
movq -512(%rbp), %rdx
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
movq -8(%rbp), %rdx
movq %rdx, -520(%rbp)
movq $5, %rdx
movq %rdx, -528(%rbp)
movq -528(%rbp), %rdx
movq %rdx, -8(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -536(%rbp)
movq $3, %rdx
movq %rdx, -544(%rbp)
movq -536(%rbp), %rcx
movq -544(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -552(%rbp)
movq -552(%rbp), %rdx
movq %rdx, -8(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -560(%rbp)
movq $2, %rdx
movq %rdx, -568(%rbp)
movq -560(%rbp), %rcx
movq -568(%rbp), %rdx
subq %rdx, %rcx
movq %rcx, -576(%rbp)
movq -576(%rbp), %rdx
movq %rdx, -8(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -584(%rbp)
movq $4, %rdx
movq %rdx, -592(%rbp)
movq -584(%rbp), %rcx
movq -592(%rbp), %rdx
imulq %rdx, %rcx
movq %rcx, -600(%rbp)
movq -600(%rbp), %rdx
movq %rdx, -8(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -608(%rbp)
movq $3, %rdx
movq %rdx, -616(%rbp)
movq -616(%rbp), %rcx
movq -608(%rbp), %rax
cqto
idivq %rcx
movq %rax, -624(%rbp)
movq -624(%rbp), %rdx
movq %rdx, -8(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -632(%rbp)
movq $2, %rdx
movq %rdx, -640(%rbp)
movq -640(%rbp), %rcx
movq -632(%rbp), %rax
cqto
idivq %rcx
movq %rax, -648(%rbp)
movq -648(%rbp), %rdx
movq %rdx, -8(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -656(%rbp)
movq $3, %rdx
movq %rdx, -664(%rbp)
movq -664(%rbp), %rcx
movq -656(%rbp), %rax
cqto
idivq %rcx
movq %rdx, -672(%rbp)
movq -672(%rbp), %rdx
movq %rdx, -8(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -680(%rbp)
movq $2, %rdx
movq %rdx, -688(%rbp)
pushq %rax
pushq %rdx
movq %rsp, %rbx
movq %rsp, %rcx
addq $-16, %rcx
andq $15, %rcx
subq %rcx, %rsp
movq -680(%rbp),  %rdx
movq -688(%rbp),  %rcx
pushq %rcx
pushq %rdx
call .power
movq %rax, -696(%rbp)
movq %rbx, %rsp
popq %rax
popq %rdx
movq -696(%rbp), %rdx
movq %rdx, -8(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -704(%rbp)
movq $2, %rdx
movq %rdx, -712(%rbp)
movq -712(%rbp), %rdx
movq %rdx, -16(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -720(%rbp)
movq $7, %rdx
movq %rdx, -728(%rbp)
movq -720(%rbp), %rcx
movq -728(%rbp), %rdx
andq %rdx, %rcx
movq %rcx, -736(%rbp)
movq -736(%rbp), %rdx
movq %rdx, -16(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -744(%rbp)
movq $8, %rdx
movq %rdx, -752(%rbp)
movq -744(%rbp), %rcx
movq -752(%rbp), %rdx
orq %rdx, %rcx
movq %rcx, -760(%rbp)
movq -760(%rbp), %rdx
movq %rdx, -16(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -768(%rbp)
movq $18, %rdx
movq %rdx, -776(%rbp)
movq -768(%rbp), %rcx
movq -776(%rbp), %rdx
xorq %rdx, %rcx
movq %rcx, -784(%rbp)
movq -784(%rbp), %rdx
movq %rdx, -16(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -792(%rbp)
movq $2, %rdx
movq %rdx, -800(%rbp)
movq -800(%rbp), %rcx
movq -792(%rbp), %rax
sal %cl, %rax
movq %rax, -808(%rbp)
movq -808(%rbp), %rdx
movq %rdx, -16(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -816(%rbp)
movq $2, %rdx
movq %rdx, -824(%rbp)
movq -824(%rbp), %rcx
movq -816(%rbp), %rax
sar %cl, %rax
movq %rax, -832(%rbp)
movq -832(%rbp), %rdx
movq %rdx, -16(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -840(%rbp)
movq $10, %rdx
movq %rdx, -848(%rbp)
movq -840(%rbp), %rdx
movq -848(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
setg %dl
movq %rdx, -840(%rbp)
movq -840(%rbp), %rdx
cmpq $0, %rdx
je L2
lea str1(%rip), %rdx
movq %rdx, -856(%rbp)
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
movq -856(%rbp), %rdx
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
jmp L4
L2:
movq -8(%rbp), %rdx
movq %rdx, -864(%rbp)
movq $5, %rdx
movq %rdx, -872(%rbp)
movq -864(%rbp), %rdx
movq -872(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
setl %dl
movq %rdx, -864(%rbp)
movq -864(%rbp), %rdx
cmpq $0, %rdx
je L3
lea str2(%rip), %rdx
movq %rdx, -880(%rbp)
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
movq -880(%rbp), %rdx
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
jmp L4
L3:
lea str3(%rip), %rdx
movq %rdx, -888(%rbp)
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
movq -888(%rbp), %rdx
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
L4:
movq $0, %rdx
movq %rdx, -896(%rbp)
movq -896(%rbp), %rdx
movq %rdx, -104(%rbp)
movq -104(%rbp), %rdx
movq %rdx, -904(%rbp)
movq $1, %rdx
movq %rdx, -912(%rbp)
movq $5, %rdx
movq %rdx, -920(%rbp)
movq -912(%rbp), %rdx
movq %rdx, -104(%rbp)
movq -104(%rbp), %rdx
movq %rdx, -928(%rbp)
jmp L6
L5:
movq -928(%rbp), %rcx
movq $1, %rdx
addq %rdx, %rcx
movq %rcx, -928(%rbp)
movq -928(%rbp), %rdx
movq %rdx, -104(%rbp)
L6:
movq -928(%rbp), %rdx
movq -920(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
setl %dl
movq %rdx, -936(%rbp)
movq -936(%rbp), %rdx
cmpq $0, %rdx
je L7
movq -104(%rbp), %rdx
movq %rdx, -944(%rbp)
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
movq -944(%rbp), %rdx
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
jmp L5
L7:
movq -104(%rbp), %rdx
movq %rdx, -952(%rbp)
movq $0, %rdx
movq %rdx, -960(%rbp)
movq -960(%rbp), %rdx
movq %rdx, -104(%rbp)
L8:
movq -104(%rbp), %rdx
movq %rdx, -968(%rbp)
movq $5, %rdx
movq %rdx, -976(%rbp)
movq -968(%rbp), %rdx
movq -976(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
setl %dl
movq %rdx, -968(%rbp)
movq -968(%rbp), %rdx
cmpq $0, %rdx
je L10
movq -104(%rbp), %rdx
movq %rdx, -984(%rbp)
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
movq -984(%rbp), %rdx
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
movq -104(%rbp), %rdx
movq %rdx, -992(%rbp)
movq $1, %rdx
movq %rdx, -1000(%rbp)
movq -992(%rbp), %rcx
movq -1000(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -1008(%rbp)
movq -1008(%rbp), %rdx
movq %rdx, -104(%rbp)
movq -104(%rbp), %rdx
movq %rdx, -1016(%rbp)
movq $3, %rdx
movq %rdx, -1024(%rbp)
movq -1016(%rbp), %rdx
movq -1024(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
sete %dl
movq %rdx, -1016(%rbp)
movq -1016(%rbp), %rdx
cmpq $0, %rdx
je L9
jmp L10
jmp L9
L9:
jmp L8
L10:
movq $5, %rdx
movq %rdx, -1032(%rbp)
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
movq -1032(%rbp), %rdx
pushq %rdx
call factorial
movq %rax, -1040(%rbp)
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
movq -1040(%rbp), %rdx
movq %rdx, -112(%rbp)
movq -112(%rbp), %rdx
movq %rdx, -1048(%rbp)
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
movq -1048(%rbp), %rdx
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
movq $5, %rdx
movq %rdx, -1056(%rbp)
movq $3, %rdx
movq %rdx, -1064(%rbp)
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
addq $-16, %rcx
andq $15, %rcx
subq %rcx, %rsp
movq -1064(%rbp), %rdx
pushq %rdx
movq -1056(%rbp), %rdx
pushq %rdx
call area
movq %rax, -1072(%rbp)
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
movq -1072(%rbp), %rdx
movq %rdx, -120(%rbp)
movq -120(%rbp), %rdx
movq %rdx, -1080(%rbp)
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
movq -1080(%rbp), %rdx
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
lea str4(%rip), %rdx
movq %rdx, -1088(%rbp)
lea str5(%rip), %rdx
movq %rdx, -1096(%rbp)
movq $2020, %rdx
movq %rdx, -1104(%rbp)
movq $24, %rdx
movq %rdx, -1112(%rbp)
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
movq -1112(%rbp), %rdx
pushq %rdx
call allocmem
movq %rax, -1112(%rbp)
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
addq $-32, %rcx
andq $15, %rcx
subq %rcx, %rsp
movq -1104(%rbp), %rdx
pushq %rdx
movq -1096(%rbp), %rdx
pushq %rdx
movq -1088(%rbp), %rdx
pushq %rdx
movq -1112(%rbp), %rdx
pushq %rdx
call Car.__init__
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
movq -1112(%rbp), %rdx
movq %rdx, -128(%rbp)
movq -128(%rbp), %rdx
movq %rdx, -1120(%rbp)
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
movq -1120(%rbp), %rdx
pushq %rdx
call Car.start
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
movq	$0, -24(%rbp)
movq	$1, -32(%rbp)
	jmp	.L2
.L3:
	movq	-32(%rbp), %rax
	imulq	16(%rbp), %rax
	movq	%rax, -32(%rbp)
	addq	$1, -24(%rbp)
.L2:
	movq	-24(%rbp), %rax
	cmpq	24(%rbp), %rax
	jl	.L3
	movq	-32(%rbp), %rax
leave
ret