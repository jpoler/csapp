	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_divide_power2
	.align	4, 0x90
_divide_power2:                         ## @divide_power2
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	xorl	%eax, %eax
	movb	%al, %cl
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	movl	-8(%rbp), %esi
	movb	%cl, -13(%rbp)          ## 1-byte Spill
	movl	%esi, %ecx
                                        ## 
	sarl	%cl, %eax
	movl	%eax, -12(%rbp)
	movl	-4(%rbp), %eax
	andl	$-2147483648, %eax      ## imm = 0xFFFFFFFF80000000
	cmpl	$0, %eax
	movb	-13(%rbp), %cl          ## 1-byte Reload
	movb	%cl, -14(%rbp)          ## 1-byte Spill
	je	LBB0_2
## BB#1:
	movl	$1, %eax
	movl	-4(%rbp), %ecx
	movl	-8(%rbp), %edx
	movl	%ecx, -20(%rbp)         ## 4-byte Spill
	movl	%edx, %ecx
                                        ## 
	shll	%cl, %eax
	movl	-20(%rbp), %edx         ## 4-byte Reload
	addl	%eax, %edx
	subl	$1, %edx
	movl	-8(%rbp), %ecx
                                        ## 
	sarl	%cl, %edx
	movl	%edx, -12(%rbp)
	cmpl	$0, %edx
	setne	%cl
	movb	%cl, -14(%rbp)          ## 1-byte Spill
LBB0_2:
	movb	-14(%rbp), %al          ## 1-byte Reload
	movl	-12(%rbp), %ecx
	movb	%al, -21(%rbp)          ## 1-byte Spill
	movl	%ecx, %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$4294967289, %eax       ## imm = 0xFFFFFFF9
	movl	$1, %ecx
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%eax, %edi
	movl	%ecx, %esi
	callq	_divide_power2
	movl	%eax, -20(%rbp)
	movl	-20(%rbp), %edi
	callq	_show_int
	xorl	%eax, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
