	.file	"main.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "\12Too many arguments\0"
.LC1:
	.ascii "rb\0"
.LC2:
	.ascii "\12\12Error with %s\0"
.LC3:
	.ascii "%d\0"
.LC4:
	.ascii "\12\12%X %X\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$136, %rsp
	.seh_stackalloc	136
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movl	%ecx, 80(%rbp)
	movq	%rdx, 88(%rbp)
	call	__main
	movq	%rsp, %rax
	movq	%rax, %rdi
	movl	$1080, -12(%rbp)
	movl	$1080, -8(%rbp)
	movl	$8, -4(%rbp)
	movl	-12(%rbp), %eax
	cltd
	idivl	-4(%rbp)
	movl	%eax, %ecx
	movl	-8(%rbp), %eax
	cltd
	idivl	-4(%rbp)
	imull	%ecx, %eax
	movl	%eax, -20(%rbp)
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -32(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, -96(%rbp)
	movq	$0, -88(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, %r14
	movl	$0, %r15d
	cltq
	addq	$15, %rax
	shrq	$4, %rax
	salq	$4, %rax
	call	___chkstk_ms
	subq	%rax, %rsp
	leaq	32(%rsp), %rax
	addq	$0, %rax
	movq	%rax, -40(%rbp)
	cmpl	$3, 80(%rbp)
	jle	.L2
	leaq	.LC0(%rip), %rcx
	call	printf
	movl	$-1, %eax
	jmp	.L3
.L2:
	movq	88(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	leaq	.LC1(%rip), %rdx
	movq	%rax, %rcx
	call	fopen
	movq	%rax, -48(%rbp)
	cmpq	$0, -48(%rbp)
	jne	.L4
	movq	88(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdx
	leaq	.LC2(%rip), %rcx
	call	printf
	movq	88(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rcx
	call	perror
	movl	$1, %eax
	jmp	.L3
.L4:
	movq	88(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rcx
	call	size
	movl	%eax, -52(%rbp)
	movl	-52(%rbp), %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -64(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, %r12
	movl	$0, %r13d
	movslq	%eax, %rdx
	movq	%rdx, %rbx
	movl	$0, %esi
	cltq
	addq	$15, %rax
	shrq	$4, %rax
	salq	$4, %rax
	call	___chkstk_ms
	subq	%rax, %rsp
	leaq	32(%rsp), %rax
	addq	$0, %rax
	movq	%rax, -72(%rbp)
	movl	$0, -16(%rbp)
	jmp	.L5
.L6:
	movl	-16(%rbp), %eax
	cltq
	movq	-40(%rbp), %rdx
	addq	%rdx, %rax
	movq	-48(%rbp), %rdx
	movq	%rdx, %r9
	movl	$1, %r8d
	movl	$1, %edx
	movq	%rax, %rcx
	call	fread
	movq	%rax, %rdx
	leaq	.LC3(%rip), %rcx
	call	printf
	movq	-40(%rbp), %rdx
	movl	-16(%rbp), %eax
	cltq
	movzbl	(%rdx,%rax), %eax
	movzbl	%al, %eax
	movq	-72(%rbp), %rsi
	movl	-16(%rbp), %edx
	movslq	%edx, %rbx
	movl	%eax, %ecx
	call	translate
	movb	%al, (%rsi,%rbx)
	movq	-40(%rbp), %rdx
	movl	-16(%rbp), %eax
	cltq
	movzbl	(%rdx,%rax), %eax
	movzbl	%al, %eax
	movl	%eax, %ecx
	call	translate
	movl	%eax, %ecx
	movq	-40(%rbp), %rdx
	movl	-16(%rbp), %eax
	cltq
	movzbl	(%rdx,%rax), %eax
	movzbl	%al, %eax
	movl	%ecx, %r8d
	movl	%eax, %edx
	leaq	.LC4(%rip), %rcx
	call	printf
	addl	$1, -16(%rbp)
.L5:
	movl	-16(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jl	.L6
	movq	-48(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	movl	$0, %eax
.L3:
	movq	%rdi, %rsp
	leaq	8(%rbp), %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	fopen;	.scl	2;	.type	32;	.endef
	.def	perror;	.scl	2;	.type	32;	.endef
	.def	size;	.scl	2;	.type	32;	.endef
	.def	fread;	.scl	2;	.type	32;	.endef
	.def	translate;	.scl	2;	.type	32;	.endef
	.def	fclose;	.scl	2;	.type	32;	.endef
