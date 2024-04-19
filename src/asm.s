.data
format_print_str: .asciz "%s\n"
format_print_int: .asciz "%ld\n"
format_print_true: .asciz "True\n"
format_print_false: .asciz "False\n"
string1: .asciz "hello"
string2: .asciz "x is greater than 10"
string3: .asciz "x is less than 5"
string4: .asciz "x is between 5 and 10"
string5: .asciz "Toyota"
string6: .asciz "Camry"
string7: .asciz "__main__"
.text
.globl main
factorial:
pushq %rbp
movq %rsp, %rbp
subq $80, %rsp
movq 16(%rbp), %rdx
movq %rdx, -8(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -16(%rbp)
movq $0, %rdx
movq %rdx, -24(%rbp)
movq -16(%rbp), %rdx
movq -24(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
setle %dl
movq %rdx, -16(%rbp)
movq -16(%rbp), %rdx
cmp $0, %rdx
jg .L4
jmp .L5
.L4:
movq $1, %rdx
movq %rdx, -48(%rbp)
movq -48(%rbp), %rax
leave
ret
jmp .L6
.L5:
movq -8(%rbp), %rdx
movq %rdx, -56(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -64(%rbp)
movq $1, %rdx
movq %rdx, -72(%rbp)
movq -64(%rbp), %rcx
movq -72(%rbp), %rdx
subq %rdx, %rcx
movq %rcx, -64(%rbp)
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
call factorial
movq %rax, -80(%rbp)
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
movq -56(%rbp), %rcx
movq -80(%rbp), %rdx
imulq %rdx, %rcx
movq %rcx, -56(%rbp)
movq -56(%rbp), %rax
leave
ret
.L6:
leave
ret
area:
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
imulq %rdx, %rcx
movq %rcx, -24(%rbp)
movq -24(%rbp), %rax
leave
ret
leave
ret
Vehicle.__init__:
pushq %rbp
movq %rsp, %rbp
subq $40, %rsp
movq 16(%rbp), %rdx
movq %rdx, -8(%rbp)
movq 24(%rbp), %rdx
movq %rdx, -16(%rbp)
movq 32(%rbp), %rdx
movq %rdx, -24(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -32(%rbp)
movq -8(%rbp), %rcx
movq $0, %rdx
addq %rdx, %rcx
movq -32(%rbp), %rdx
movq %rdx, (%rcx)
movq -24(%rbp), %rdx
movq %rdx, -40(%rbp)
movq -8(%rbp), %rcx
movq $8, %rdx
addq %rdx, %rcx
movq -40(%rbp), %rdx
movq %rdx, (%rcx)
leave
ret
Vehicle.start:
pushq %rbp
movq %rsp, %rbp
subq $24, %rsp
movq 16(%rbp), %rdx
movq %rdx, -8(%rbp)
movq -8(%rbp), %rcx
movq $0, %rdx
addq %rdx, %rcx
movq (%rcx), %rdx
movq %rdx, -16(%rbp)
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
movq -16(%rbp), %rdx
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
movq -8(%rbp), %rcx
movq $8, %rdx
addq %rdx, %rcx
movq (%rcx), %rdx
movq %rdx, -24(%rbp)
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
leave
ret
Car.__init__:
pushq %rbp
movq %rsp, %rbp
subq $56, %rsp
movq 16(%rbp), %rdx
movq %rdx, -8(%rbp)
movq 24(%rbp), %rdx
movq %rdx, -16(%rbp)
movq 32(%rbp), %rdx
movq %rdx, -24(%rbp)
movq 40(%rbp), %rdx
movq %rdx, -32(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -40(%rbp)
movq -8(%rbp), %rcx
movq $0, %rdx
addq %rdx, %rcx
movq -40(%rbp), %rdx
movq %rdx, (%rcx)
movq -24(%rbp), %rdx
movq %rdx, -48(%rbp)
movq -8(%rbp), %rcx
movq $8, %rdx
addq %rdx, %rcx
movq -48(%rbp), %rdx
movq %rdx, (%rcx)
movq -32(%rbp), %rdx
movq %rdx, -56(%rbp)
movq -8(%rbp), %rcx
movq $16, %rdx
addq %rdx, %rcx
movq -56(%rbp), %rdx
movq %rdx, (%rcx)
leave
ret
Car.start:
pushq %rbp
movq %rsp, %rbp
subq $32, %rsp
movq 16(%rbp), %rdx
movq %rdx, -8(%rbp)
movq -8(%rbp), %rcx
movq $16, %rdx
addq %rdx, %rcx
movq (%rcx), %rdx
movq %rdx, -16(%rbp)
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
movq -16(%rbp), %rdx
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
movq -8(%rbp), %rcx
movq $0, %rdx
addq %rdx, %rcx
movq (%rcx), %rdx
movq %rdx, -24(%rbp)
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
movq -8(%rbp), %rcx
movq $8, %rdx
addq %rdx, %rcx
movq (%rcx), %rdx
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
movq -32(%rbp), %rdx
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
subq $1040, %rsp
movq $42, %rdx
movq %rdx, -8(%rbp)
movq -8(%rbp), %rdx
movq %rdx, -16(%rbp)
movq $3, %rdx
movq %rdx, -24(%rbp)
movq -24(%rbp), %rdx
movq %rdx, -32(%rbp)
lea string1(%rip), %rdx
movq %rdx, -40(%rbp)
movq -40(%rbp), %rdx
movq %rdx, -48(%rbp)
movq $1, %rdx
movq %rdx, -56(%rbp)
movq -56(%rbp), %rdx
movq %rdx, -64(%rbp)
movq $1, %rdx
movq %rdx, -72(%rbp)
movq $2, %rdx
movq %rdx, -80(%rbp)
movq $3, %rdx
movq %rdx, -88(%rbp)
movq $4, %rdx
movq %rdx, -96(%rbp)
movq $5, %rdx
movq %rdx, -104(%rbp)
movq $48, %rdx
movq %rdx, -112(%rbp)
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
call mem_alloc
movq %rax, -120(%rbp)
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
movq -120(%rbp), %rdx
movq %rdx, -128(%rbp)
movq -128(%rbp), %rdx
movq $5, %rcx
movq %rcx, (%rdx)
movq -128(%rbp), %rcx
movq $8, %rdx
addq %rdx, %rcx
movq %rcx, -128(%rbp)
movq -128(%rbp), %rdx
movq -72(%rbp), %rcx
movq %rcx, (%rdx)
movq -128(%rbp), %rcx
movq $8, %rdx
addq %rdx, %rcx
movq %rcx, -128(%rbp)
movq -128(%rbp), %rdx
movq -80(%rbp), %rcx
movq %rcx, (%rdx)
movq -128(%rbp), %rcx
movq $8, %rdx
addq %rdx, %rcx
movq %rcx, -128(%rbp)
movq -128(%rbp), %rdx
movq -88(%rbp), %rcx
movq %rcx, (%rdx)
movq -128(%rbp), %rcx
movq $8, %rdx
addq %rdx, %rcx
movq %rcx, -128(%rbp)
movq -128(%rbp), %rdx
movq -96(%rbp), %rcx
movq %rcx, (%rdx)
movq -128(%rbp), %rcx
movq $8, %rdx
addq %rdx, %rcx
movq %rcx, -128(%rbp)
movq -128(%rbp), %rdx
movq -104(%rbp), %rcx
movq %rcx, (%rdx)
movq -120(%rbp), %rdx
movq %rdx, -136(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -144(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -152(%rbp)
movq -144(%rbp), %rcx
movq -152(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -144(%rbp)
movq -144(%rbp), %rdx
movq %rdx, -160(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -168(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -176(%rbp)
movq -168(%rbp), %rcx
movq -176(%rbp), %rdx
subq %rdx, %rcx
movq %rcx, -168(%rbp)
movq -168(%rbp), %rdx
movq %rdx, -64(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -184(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -192(%rbp)
movq -184(%rbp), %rcx
movq -192(%rbp), %rdx
imulq %rdx, %rcx
movq %rcx, -184(%rbp)
movq -184(%rbp), %rdx
movq %rdx, -200(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -208(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -216(%rbp)
movq -208(%rbp), %rax
cdq
idivq -216(%rbp)
movq %rax, -208(%rbp)
movq -208(%rbp), %rdx
movq %rdx, -224(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -232(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -240(%rbp)
movq -232(%rbp), %rax
cdq
idivq -240(%rbp)
movq %rax, -232(%rbp)
movq -232(%rbp), %rdx
movq %rdx, -248(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -256(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -264(%rbp)
movq -256(%rbp), %rax
cdq
idivq -264(%rbp)
movq %rdx, -256(%rbp)
movq -256(%rbp), %rdx
movq %rdx, -272(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -280(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -288(%rbp)
movq -280(%rbp), %rdx
movq -288(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
sete %dl
movq %rdx, -280(%rbp)
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
movq -280(%rbp), %rdx
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
movq -16(%rbp), %rdx
movq %rdx, -296(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -304(%rbp)
movq -296(%rbp), %rdx
movq -304(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
setne %dl
movq %rdx, -296(%rbp)
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
movq -296(%rbp), %rdx
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
movq -16(%rbp), %rdx
movq %rdx, -312(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -320(%rbp)
movq -312(%rbp), %rdx
movq -320(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
setg %dl
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
movq -16(%rbp), %rdx
movq %rdx, -328(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -336(%rbp)
movq -328(%rbp), %rdx
movq -336(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
setl %dl
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
movq -16(%rbp), %rdx
movq %rdx, -344(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -352(%rbp)
movq -344(%rbp), %rdx
movq -352(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
setge %dl
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
movq -16(%rbp), %rdx
movq %rdx, -360(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -368(%rbp)
movq -360(%rbp), %rdx
movq -368(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
setle %dl
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
movq $1, %rdx
movq %rdx, -376(%rbp)
movq $0, %rdx
movq %rdx, -384(%rbp)
movq -376(%rbp), %rcx
movq -384(%rbp), %rdx
andq %rdx, %rcx
movq %rcx, -376(%rbp)
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
movq $1, %rdx
movq %rdx, -400(%rbp)
movq $0, %rdx
movq %rdx, -408(%rbp)
movq -400(%rbp), %rcx
movq -408(%rbp), %rdx
orq %rdx, %rcx
movq %rcx, -400(%rbp)
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
movq -400(%rbp), %rdx
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
movq -424(%rbp), %rcx
cmp $0, %rcx
movq $0, %rcx
sete %cl
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
movq $10, %rdx
movq %rdx, -440(%rbp)
movq -440(%rbp), %rdx
movq %rdx, -448(%rbp)
movq $11, %rdx
movq %rdx, -456(%rbp)
movq -456(%rbp), %rdx
movq %rdx, -464(%rbp)
movq -448(%rbp), %rdx
movq %rdx, -472(%rbp)
movq -464(%rbp), %rdx
movq %rdx, -480(%rbp)
movq -472(%rbp), %rcx
movq -480(%rbp), %rdx
andq %rdx, %rcx
movq %rcx, -472(%rbp)
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
movq -472(%rbp), %rdx
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
movq -448(%rbp), %rdx
movq %rdx, -488(%rbp)
movq -464(%rbp), %rdx
movq %rdx, -496(%rbp)
movq -488(%rbp), %rcx
movq -496(%rbp), %rdx
orq %rdx, %rcx
movq %rcx, -488(%rbp)
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
movq -488(%rbp), %rdx
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
movq -448(%rbp), %rdx
movq %rdx, -504(%rbp)
movq -464(%rbp), %rdx
movq %rdx, -512(%rbp)
movq -504(%rbp), %rcx
movq -512(%rbp), %rdx
xorq %rdx, %rcx
movq %rcx, -504(%rbp)
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
movq -504(%rbp), %rdx
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
movq -448(%rbp), %rdx
movq %rdx, -520(%rbp)
movq -520(%rbp), %rcx
not %rcx
movq %rcx, -520(%rbp)
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
movq -520(%rbp), %rdx
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
movq %rdx, -528(%rbp)
movq -528(%rbp), %rdx
movq %rdx, -16(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -536(%rbp)
movq $3, %rdx
movq %rdx, -544(%rbp)
movq -536(%rbp), %rcx
movq -544(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -16(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -552(%rbp)
movq $2, %rdx
movq %rdx, -560(%rbp)
movq -552(%rbp), %rcx
movq -560(%rbp), %rdx
subq %rdx, %rcx
movq %rcx, -16(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -568(%rbp)
movq $4, %rdx
movq %rdx, -576(%rbp)
movq -568(%rbp), %rcx
movq -576(%rbp), %rdx
imulq %rdx, %rcx
movq %rcx, -16(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -584(%rbp)
movq $3, %rdx
movq %rdx, -592(%rbp)
movq -584(%rbp), %rax
cdq
idivq -592(%rbp)
movq %rax, -16(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -600(%rbp)
movq $2, %rdx
movq %rdx, -608(%rbp)
movq -600(%rbp), %rax
cdq
idivq -608(%rbp)
movq %rax, -16(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -616(%rbp)
movq $3, %rdx
movq %rdx, -624(%rbp)
movq -616(%rbp), %rax
cdq
idivq -624(%rbp)
movq %rdx, -16(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -632(%rbp)
movq $2, %rdx
movq %rdx, -640(%rbp)
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
movq -632(%rbp), %rcx
movq -640(%rbp), %rdx
pushq %rdx
pushq %rcx
call .power
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
movq $2, %rdx
movq %rdx, -648(%rbp)
movq -648(%rbp), %rdx
movq %rdx, -32(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -656(%rbp)
movq $7, %rdx
movq %rdx, -664(%rbp)
movq -656(%rbp), %rcx
movq -664(%rbp), %rdx
andq %rdx, %rcx
movq %rcx, -32(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -672(%rbp)
movq $8, %rdx
movq %rdx, -680(%rbp)
movq -672(%rbp), %rcx
movq -680(%rbp), %rdx
orq %rdx, %rcx
movq %rcx, -32(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -688(%rbp)
movq $18, %rdx
movq %rdx, -696(%rbp)
movq -688(%rbp), %rcx
movq -696(%rbp), %rdx
xorq %rdx, %rcx
movq %rcx, -32(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -704(%rbp)
movq $2, %rdx
movq %rdx, -712(%rbp)
movq -704(%rbp), %rax
movq -712(%rbp), %rcx
sal %cl, %rax
movq %rax, -32(%rbp)
movq -32(%rbp), %rdx
movq %rdx, -720(%rbp)
movq $2, %rdx
movq %rdx, -728(%rbp)
movq -720(%rbp), %rax
movq -728(%rbp), %rcx
sar %cl, %rax
movq %rax, -32(%rbp)
movq -16(%rbp), %rdx
movq %rdx, -736(%rbp)
movq $10, %rdx
movq %rdx, -744(%rbp)
movq -736(%rbp), %rdx
movq -744(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
setg %dl
movq %rdx, -736(%rbp)
movq -736(%rbp), %rdx
cmp $0, %rdx
jg .L7
jmp .L8
.L7:
lea string2(%rip), %rdx
movq %rdx, -768(%rbp)
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
movq -768(%rbp), %rdx
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
jmp .L11
.L8:
movq -16(%rbp), %rdx
movq %rdx, -776(%rbp)
movq $5, %rdx
movq %rdx, -784(%rbp)
movq -776(%rbp), %rdx
movq -784(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
setl %dl
movq %rdx, -776(%rbp)
movq -776(%rbp), %rdx
cmp $0, %rdx
jg .L9
jmp .L10
.L9:
lea string3(%rip), %rdx
movq %rdx, -792(%rbp)
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
movq -792(%rbp), %rdx
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
jmp .L11
.L10:
lea string4(%rip), %rdx
movq %rdx, -800(%rbp)
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
movq -800(%rbp), %rdx
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
.L11:
movq $0, %rdx
movq %rdx, -808(%rbp)
movq -808(%rbp), %rdx
movq %rdx, -816(%rbp)
movq $1, %rdx
movq %rdx, -824(%rbp)
movq $5, %rdx
movq %rdx, -832(%rbp)
movq $1, %rdx
movq %rdx, -840(%rbp)
movq -824(%rbp), %rcx
movq -840(%rbp), %rdx
subq %rdx, %rcx
movq %rcx, -848(%rbp)
movq -848(%rbp), %rdx
movq %rdx, -816(%rbp)
.L12:
movq -816(%rbp), %rdx
movq %rdx, -856(%rbp)
movq -856(%rbp), %rcx
movq -840(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -856(%rbp)
movq -856(%rbp), %rdx
movq %rdx, -816(%rbp)
movq -856(%rbp), %rdx
movq -832(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
setl %dl
movq %rdx, -856(%rbp)
movq -856(%rbp), %rdx
cmp $0, %rdx
jg .L13
jmp .L14
.L13:
movq -816(%rbp), %rdx
movq %rdx, -864(%rbp)
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
movq -864(%rbp), %rdx
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
jmp .L12
.L14:
movq $0, %rdx
movq %rdx, -872(%rbp)
movq -872(%rbp), %rdx
movq %rdx, -816(%rbp)
.L15:
movq -816(%rbp), %rdx
movq %rdx, -880(%rbp)
movq $5, %rdx
movq %rdx, -888(%rbp)
movq -880(%rbp), %rdx
movq -888(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
setl %dl
movq %rdx, -880(%rbp)
movq -880(%rbp), %rdx
cmp $0, %rdx
jg .L16
jmp .L19
.L16:
movq -816(%rbp), %rdx
movq %rdx, -896(%rbp)
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
movq -896(%rbp), %rdx
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
movq -816(%rbp), %rdx
movq %rdx, -904(%rbp)
movq $1, %rdx
movq %rdx, -912(%rbp)
movq -904(%rbp), %rcx
movq -912(%rbp), %rdx
addq %rdx, %rcx
movq %rcx, -816(%rbp)
movq -816(%rbp), %rdx
movq %rdx, -920(%rbp)
movq $3, %rdx
movq %rdx, -928(%rbp)
movq -920(%rbp), %rdx
movq -928(%rbp), %rcx
cmp %rcx, %rdx
movq $0, %rdx
sete %dl
movq %rdx, -920(%rbp)
movq -920(%rbp), %rdx
cmp $0, %rdx
jg .L17
jmp .L18
.L17:
jmp .L19
jmp .L18
.L18:
jmp .L15
.L19:
movq $5, %rdx
movq %rdx, -936(%rbp)
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
movq -936(%rbp), %rdx
pushq %rdx
call factorial
movq %rax, -944(%rbp)
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
movq -944(%rbp), %rdx
movq %rdx, -952(%rbp)
movq -952(%rbp), %rdx
movq %rdx, -960(%rbp)
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
movq -960(%rbp), %rdx
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
movq %rdx, -968(%rbp)
movq $3, %rdx
movq %rdx, -976(%rbp)
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
movq -976(%rbp), %rdx
pushq %rdx
movq -968(%rbp), %rdx
pushq %rdx
call area
movq %rax, -984(%rbp)
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
movq -984(%rbp), %rdx
movq %rdx, -992(%rbp)
movq -992(%rbp), %rdx
movq %rdx, -1000(%rbp)
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
movq -1000(%rbp), %rdx
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
lea string5(%rip), %rdx
movq %rdx, -1008(%rbp)
lea string6(%rip), %rdx
movq %rdx, -1016(%rbp)
movq $2020, %rdx
movq %rdx, -1024(%rbp)
movq $24, %rdx
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
call mem_alloc
movq %rax, -1032(%rbp)
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
addq $-8, %rcx
andq $15, %rcx
subq %rcx, %rsp
movq -1024(%rbp), %rdx
pushq %rdx
movq -1016(%rbp), %rdx
pushq %rdx
movq -1008(%rbp), %rdx
pushq %rdx
movq -1032(%rbp), %rdx
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
movq -1032(%rbp), %rdx
movq %rdx, -1040(%rbp)
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
movq -1040(%rbp), %rdx
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
