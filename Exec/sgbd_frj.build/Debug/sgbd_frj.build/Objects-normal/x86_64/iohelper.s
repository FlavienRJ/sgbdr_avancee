	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.file	1 "/Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj" "/Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/sgbd.h"
	.file	2 "/Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj" "/Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c"
	.globl	_newBDD
	.p2align	4, 0x90
_newBDD:                                ## @newBDD
Lfunc_begin0:
	.loc	2 4 0                   ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:4:0
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$24, %eax
	movl	%eax, %edi
Ltmp0:
	.loc	2 5 19 prologue_end     ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:5:19
	callq	_malloc
	leaq	L_.str(%rip), %rdi
	.loc	2 5 7 is_stmt 0         ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:5:7
	movq	%rax, -8(%rbp)
	.loc	2 6 2 is_stmt 1         ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:6:2
	movq	-8(%rbp), %rax
	.loc	2 6 12 is_stmt 0        ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:6:12
	movq	%rdi, (%rax)
	.loc	2 7 2 is_stmt 1         ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:7:2
	movq	-8(%rbp), %rax
	.loc	2 7 12 is_stmt 0        ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:7:12
	movq	$0, 8(%rax)
	.loc	2 8 2 is_stmt 1         ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:8:2
	movq	-8(%rbp), %rax
	.loc	2 8 13 is_stmt 0        ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:8:13
	movl	$0, 16(%rax)
	.loc	2 9 9 is_stmt 1         ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:9:9
	movq	-8(%rbp), %rax
	.loc	2 9 2 is_stmt 0         ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:9:2
	addq	$16, %rsp
	popq	%rbp
	retq
Ltmp1:
Lfunc_end0:
	.cfi_endproc

	.globl	_openBDD
	.p2align	4, 0x90
_openBDD:                               ## @openBDD
Lfunc_begin1:
	.loc	2 13 0 is_stmt 1        ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:13:0
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi3:
	.cfi_def_cfa_offset 16
Lcfi4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi5:
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	leaq	L_.str.1(%rip), %rax
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
Ltmp2:
	.loc	2 15 18 prologue_end    ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:15:18
	movq	-16(%rbp), %rdi
	.loc	2 15 12 is_stmt 0       ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:15:12
	movq	%rax, %rsi
	callq	_fopen
	.loc	2 15 10                 ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:15:10
	movq	%rax, -32(%rbp)
	.loc	2 15 34                 ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:15:34
	cmpq	$0, %rax
Ltmp3:
	.loc	2 15 6                  ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:15:6
	jne	LBB1_2
## BB#1:
Ltmp4:
	.loc	2 17 3 is_stmt 1        ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:17:3
	movl	$-1, -4(%rbp)
	jmp	LBB1_11
Ltmp5:
LBB1_2:
	.loc	2 19 17                 ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:19:17
	movq	-16(%rbp), %rax
	.loc	2 19 2 is_stmt 0        ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:19:2
	movq	-24(%rbp), %rcx
	.loc	2 19 15                 ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:19:15
	movq	%rax, (%rcx)
	.loc	2 20 2 is_stmt 1        ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:20:2
	movq	-24(%rbp), %rax
	.loc	2 20 16 is_stmt 0       ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:20:16
	movl	$1, 16(%rax)
LBB1_3:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_7 Depth 2
	.loc	2 0 16                  ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:0:16
	leaq	L_.str.2(%rip), %rsi
	.loc	2 23 24 is_stmt 1 discriminator 1 ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:23:24
	movq	-32(%rbp), %rdi
	.loc	2 23 33 is_stmt 0 discriminator 1 ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:23:33
	movq	-40(%rbp), %rdx
	.loc	2 23 16 discriminator 1 ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:23:16
	movb	$0, %al
	callq	_fscanf
	xorl	%ecx, %ecx
	movb	%cl, %r8b
	.loc	2 23 14 discriminator 1 ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:23:14
	movl	%eax, -44(%rbp)
	.loc	2 23 39 discriminator 1 ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:23:39
	cmpl	$-1, %eax
	.loc	2 23 46 discriminator 1 ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:23:46
	movb	%r8b, -45(%rbp)         ## 1-byte Spill
	je	LBB1_5
## BB#4:                                ##   in Loop: Header=BB1_3 Depth=1
	.loc	2 23 53 discriminator 2 ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:23:53
	cmpl	$0, -44(%rbp)
	setne	%al
	movb	%al, -45(%rbp)          ## 1-byte Spill
LBB1_5:                                 ##   in Loop: Header=BB1_3 Depth=1
	.loc	2 0 53 discriminator 2  ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:0:53
	movb	-45(%rbp), %al          ## 1-byte Reload
	.loc	2 23 2 discriminator 3  ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:23:2
	testb	$1, %al
	jne	LBB1_6
	jmp	LBB1_10
LBB1_6:                                 ##   in Loop: Header=BB1_3 Depth=1
Ltmp6:
	.loc	2 26 3 is_stmt 1        ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:26:3
	jmp	LBB1_7
LBB1_7:                                 ##   Parent Loop BB1_3 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	.loc	2 0 3 is_stmt 0         ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:0:3
	leaq	-40(%rbp), %rdi
	leaq	L_.str.3(%rip), %rsi
	.loc	2 26 10 discriminator 1 ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:26:10
	callq	_strsep
	.loc	2 26 3 discriminator 1  ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:26:3
	cmpq	$0, %rax
	je	LBB1_9
## BB#8:                                ##   in Loop: Header=BB1_7 Depth=2
	.loc	2 26 3 discriminator 2  ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:26:3
	jmp	LBB1_7
LBB1_9:                                 ##   in Loop: Header=BB1_3 Depth=1
	.loc	2 0 3 discriminator 2   ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:0:3
	leaq	L_.str.4(%rip), %rdi
	.loc	2 30 16 is_stmt 1       ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:30:16
	movq	-40(%rbp), %rsi
	.loc	2 30 3 is_stmt 0        ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:30:3
	movb	$0, %al
	callq	_printf
Ltmp7:
	.loc	2 23 2 is_stmt 1 discriminator 4 ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:23:2
	movl	%eax, -52(%rbp)         ## 4-byte Spill
	jmp	LBB1_3
LBB1_10:
	.loc	2 33 2                  ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:33:2
	movl	$0, -4(%rbp)
LBB1_11:
	.loc	2 34 1                  ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:34:1
	movl	-4(%rbp), %eax
	addq	$64, %rsp
	popq	%rbp
	retq
Ltmp8:
Lfunc_end1:
	.cfi_endproc

	.globl	_closeBDD
	.p2align	4, 0x90
_closeBDD:                              ## @closeBDD
Lfunc_begin2:
	.loc	2 37 0                  ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:37:0
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi6:
	.cfi_def_cfa_offset 16
Lcfi7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi8:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
Ltmp9:
	.loc	2 39 1 prologue_end     ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:39:1
	popq	%rbp
	retq
Ltmp10:
Lfunc_end2:
	.cfi_endproc

	.globl	_store
	.p2align	4, 0x90
_store:                                 ## @store
Lfunc_begin3:
	.loc	2 42 0                  ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:42:0
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi9:
	.cfi_def_cfa_offset 16
Lcfi10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi11:
	.cfi_def_cfa_register %rbp
	movq	%rdx, -16(%rbp)
	movl	%ecx, -8(%rbp)
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
Ltmp11:
	.loc	2 44 1 prologue_end     ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:44:1
	popq	%rbp
	retq
Ltmp12:
Lfunc_end3:
	.cfi_endproc

	.globl	_getNupletBdd
	.p2align	4, 0x90
_getNupletBdd:                          ## @getNupletBdd
Lfunc_begin4:
	.loc	2 47 0                  ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:47:0
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi12:
	.cfi_def_cfa_offset 16
Lcfi13:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi14:
	.cfi_def_cfa_register %rbp
	##DEBUG_VALUE: getNupletBdd:parBdd <- [%RBP+16]
	##DEBUG_VALUE: getNupletBdd:parPos <- [%RBP+-20]
	movl	%edi, -20(%rbp)
Ltmp13:
	.loc	2 49 10 prologue_end    ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:49:10
	movl	$0, -32(%rbp)
	.loc	2 50 9                  ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:50:9
	movq	-40(%rbp), %rax
	movq	-32(%rbp), %rcx
	movq	%rcx, -8(%rbp)
	movq	%rax, -16(%rbp)
	.loc	2 50 2 is_stmt 0        ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:50:2
	movq	-16(%rbp), %rax
	movl	-8(%rbp), %edx
	popq	%rbp
	retq
Ltmp14:
Lfunc_end4:
	.cfi_endproc

	.globl	_size
	.p2align	4, 0x90
_size:                                  ## @size
Lfunc_begin5:
	.loc	2 54 0 is_stmt 1        ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:54:0
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi15:
	.cfi_def_cfa_offset 16
Lcfi16:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi17:
	.cfi_def_cfa_register %rbp
	xorl	%eax, %eax
	##DEBUG_VALUE: size:parBdd <- [%RBP+16]
Ltmp15:
	.loc	2 55 2 prologue_end     ## /Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c:55:2
	popq	%rbp
	retq
Ltmp16:
Lfunc_end5:
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.space	1

L_.str.1:                               ## @.str.1
	.asciz	"w+"

L_.str.2:                               ## @.str.2
	.asciz	"%s "

L_.str.3:                               ## @.str.3
	.asciz	";"

L_.str.4:                               ## @.str.4
	.asciz	"%s"

	.file	3 "/Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj" "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/usr/include/stdio.h"
	.section	__DWARF,__debug_str,regular,debug
Linfo_string:
	.asciz	"Apple LLVM version 9.0.0 (clang-900.0.39.2)" ## string offset=0
	.asciz	"/Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj/sgbd_frj/iohelper.c" ## string offset=44
	.asciz	"/Users/frj/Dropbox/Ecole/4A/SGBDR_avancee/sgbd_frj" ## string offset=115
	.asciz	"BDD"                   ## string offset=166
	.asciz	"bdd"                   ## string offset=170
	.asciz	"path"                  ## string offset=174
	.asciz	"char"                  ## string offset=179
	.asciz	"data"                  ## string offset=184
	.asciz	"NUPLET"                ## string offset=189
	.asciz	"nuplet"                ## string offset=196
	.asciz	"val"                   ## string offset=203
	.asciz	"int"                   ## string offset=207
	.asciz	"size"                  ## string offset=211
	.asciz	"state"                 ## string offset=216
	.asciz	"Darwin"                ## string offset=222
	.asciz	"\"-DDEBUG=1\""         ## string offset=229
	.asciz	"/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/usr/include" ## string offset=241
	.asciz	"/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk" ## string offset=353
	.asciz	"C"                     ## string offset=453
	.asciz	"stdio"                 ## string offset=455
	.asciz	"stdlib"                ## string offset=461
	.asciz	"string"                ## string offset=468
	.asciz	"/Users/frj/Library/Developer/Xcode/DerivedData/ModuleCache/VOGA4BT7ZMIW/Darwin-1IVCWVLR6MT9T.pcm" ## string offset=475
	.asciz	"newBDD"                ## string offset=572
	.asciz	"openBDD"               ## string offset=579
	.asciz	"closeBDD"              ## string offset=587
	.asciz	"store"                 ## string offset=596
	.asciz	"getNupletBdd"          ## string offset=602
	.asciz	"res"                   ## string offset=615
	.asciz	"parPath"               ## string offset=619
	.asciz	"parBdd"                ## string offset=627
	.asciz	"fp"                    ## string offset=634
	.asciz	"FILE"                  ## string offset=637
	.asciz	"__sFILE"               ## string offset=642
	.asciz	"row"                   ## string offset=650
	.asciz	"ret"                   ## string offset=654
	.asciz	"parBDD"                ## string offset=658
	.asciz	"parPos"                ## string offset=665
	.asciz	"parVal"                ## string offset=672
	.section	__DWARF,__debug_loc,regular,debug
Lsection_debug_loc:
Ldebug_loc0:
Lset0 = Lfunc_begin4-Lfunc_begin0
	.quad	Lset0
Lset1 = Lfunc_end4-Lfunc_begin0
	.quad	Lset1
	.short	2                       ## Loc expr size
	.byte	118                     ## DW_OP_breg6
	.byte	16                      ## 16
	.quad	0
	.quad	0
Ldebug_loc1:
Lset2 = Lfunc_begin5-Lfunc_begin0
	.quad	Lset2
Lset3 = Lfunc_end5-Lfunc_begin0
	.quad	Lset3
	.short	2                       ## Loc expr size
	.byte	118                     ## DW_OP_breg6
	.byte	16                      ## 16
	.quad	0
	.quad	0
	.section	__DWARF,__debug_abbrev,regular,debug
Lsection_abbrev:
	.byte	1                       ## Abbreviation Code
	.byte	17                      ## DW_TAG_compile_unit
	.byte	1                       ## DW_CHILDREN_yes
	.byte	37                      ## DW_AT_producer
	.byte	14                      ## DW_FORM_strp
	.byte	19                      ## DW_AT_language
	.byte	5                       ## DW_FORM_data2
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	16                      ## DW_AT_stmt_list
	.byte	23                      ## DW_FORM_sec_offset
	.byte	27                      ## DW_AT_comp_dir
	.byte	14                      ## DW_FORM_strp
	.byte	17                      ## DW_AT_low_pc
	.byte	1                       ## DW_FORM_addr
	.byte	18                      ## DW_AT_high_pc
	.byte	6                       ## DW_FORM_data4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	2                       ## Abbreviation Code
	.byte	15                      ## DW_TAG_pointer_type
	.byte	0                       ## DW_CHILDREN_no
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	3                       ## Abbreviation Code
	.byte	22                      ## DW_TAG_typedef
	.byte	0                       ## DW_CHILDREN_no
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	4                       ## Abbreviation Code
	.byte	19                      ## DW_TAG_structure_type
	.byte	1                       ## DW_CHILDREN_yes
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	11                      ## DW_AT_byte_size
	.byte	11                      ## DW_FORM_data1
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	5                       ## Abbreviation Code
	.byte	13                      ## DW_TAG_member
	.byte	0                       ## DW_CHILDREN_no
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	56                      ## DW_AT_data_member_location
	.byte	11                      ## DW_FORM_data1
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	6                       ## Abbreviation Code
	.byte	36                      ## DW_TAG_base_type
	.byte	0                       ## DW_CHILDREN_no
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	62                      ## DW_AT_encoding
	.byte	11                      ## DW_FORM_data1
	.byte	11                      ## DW_AT_byte_size
	.byte	11                      ## DW_FORM_data1
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	7                       ## Abbreviation Code
	.byte	15                      ## DW_TAG_pointer_type
	.byte	0                       ## DW_CHILDREN_no
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	8                       ## Abbreviation Code
	.byte	30                      ## DW_TAG_module
	.byte	1                       ## DW_CHILDREN_yes
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.ascii	"\201|"                 ## DW_AT_LLVM_config_macros
	.byte	14                      ## DW_FORM_strp
	.ascii	"\200|"                 ## DW_AT_LLVM_include_path
	.byte	14                      ## DW_FORM_strp
	.ascii	"\202|"                 ## DW_AT_LLVM_isysroot
	.byte	14                      ## DW_FORM_strp
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	9                       ## Abbreviation Code
	.byte	19                      ## DW_TAG_structure_type
	.byte	0                       ## DW_CHILDREN_no
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	60                      ## DW_AT_declaration
	.byte	25                      ## DW_FORM_flag_present
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	10                      ## Abbreviation Code
	.byte	30                      ## DW_TAG_module
	.byte	0                       ## DW_CHILDREN_no
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.ascii	"\201|"                 ## DW_AT_LLVM_config_macros
	.byte	14                      ## DW_FORM_strp
	.ascii	"\200|"                 ## DW_AT_LLVM_include_path
	.byte	14                      ## DW_FORM_strp
	.ascii	"\202|"                 ## DW_AT_LLVM_isysroot
	.byte	14                      ## DW_FORM_strp
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	11                      ## Abbreviation Code
	.byte	8                       ## DW_TAG_imported_declaration
	.byte	0                       ## DW_CHILDREN_no
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	24                      ## DW_AT_import
	.byte	19                      ## DW_FORM_ref4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	12                      ## Abbreviation Code
	.byte	46                      ## DW_TAG_subprogram
	.byte	1                       ## DW_CHILDREN_yes
	.byte	17                      ## DW_AT_low_pc
	.byte	1                       ## DW_FORM_addr
	.byte	18                      ## DW_AT_high_pc
	.byte	6                       ## DW_FORM_data4
	.byte	64                      ## DW_AT_frame_base
	.byte	24                      ## DW_FORM_exprloc
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	39                      ## DW_AT_prototyped
	.byte	25                      ## DW_FORM_flag_present
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	63                      ## DW_AT_external
	.byte	25                      ## DW_FORM_flag_present
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	13                      ## Abbreviation Code
	.byte	52                      ## DW_TAG_variable
	.byte	0                       ## DW_CHILDREN_no
	.byte	2                       ## DW_AT_location
	.byte	24                      ## DW_FORM_exprloc
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	14                      ## Abbreviation Code
	.byte	5                       ## DW_TAG_formal_parameter
	.byte	0                       ## DW_CHILDREN_no
	.byte	2                       ## DW_AT_location
	.byte	24                      ## DW_FORM_exprloc
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	15                      ## Abbreviation Code
	.byte	46                      ## DW_TAG_subprogram
	.byte	1                       ## DW_CHILDREN_yes
	.byte	17                      ## DW_AT_low_pc
	.byte	1                       ## DW_FORM_addr
	.byte	18                      ## DW_AT_high_pc
	.byte	6                       ## DW_FORM_data4
	.byte	64                      ## DW_AT_frame_base
	.byte	24                      ## DW_FORM_exprloc
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	39                      ## DW_AT_prototyped
	.byte	25                      ## DW_FORM_flag_present
	.byte	63                      ## DW_AT_external
	.byte	25                      ## DW_FORM_flag_present
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	16                      ## Abbreviation Code
	.byte	5                       ## DW_TAG_formal_parameter
	.byte	0                       ## DW_CHILDREN_no
	.byte	2                       ## DW_AT_location
	.byte	23                      ## DW_FORM_sec_offset
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	17                      ## Abbreviation Code
	.byte	17                      ## DW_TAG_compile_unit
	.byte	0                       ## DW_CHILDREN_no
	.byte	37                      ## DW_AT_producer
	.byte	14                      ## DW_FORM_strp
	.byte	19                      ## DW_AT_language
	.byte	5                       ## DW_FORM_data2
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	16                      ## DW_AT_stmt_list
	.byte	23                      ## DW_FORM_sec_offset
	.byte	27                      ## DW_AT_comp_dir
	.byte	14                      ## DW_FORM_strp
	.ascii	"\341\177"              ## DW_AT_APPLE_optimized
	.byte	25                      ## DW_FORM_flag_present
	.ascii	"\261B"                 ## DW_AT_GNU_dwo_id
	.byte	7                       ## DW_FORM_data8
	.ascii	"\260B"                 ## DW_AT_GNU_dwo_name
	.byte	14                      ## DW_FORM_strp
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	0                       ## EOM(3)
	.section	__DWARF,__debug_info,regular,debug
Lsection_info:
Lcu_begin0:
	.long	650                     ## Length of Unit
	.short	4                       ## DWARF version number
Lset4 = Lsection_abbrev-Lsection_abbrev ## Offset Into Abbrev. Section
	.long	Lset4
	.byte	8                       ## Address Size (in bytes)
	.byte	1                       ## Abbrev [1] 0xb:0x283 DW_TAG_compile_unit
	.long	0                       ## DW_AT_producer
	.short	12                      ## DW_AT_language
	.long	44                      ## DW_AT_name
Lset5 = Lline_table_start0-Lsection_line ## DW_AT_stmt_list
	.long	Lset5
	.long	115                     ## DW_AT_comp_dir
	.quad	Lfunc_begin0            ## DW_AT_low_pc
Lset6 = Lfunc_end5-Lfunc_begin0         ## DW_AT_high_pc
	.long	Lset6
	.byte	2                       ## Abbrev [2] 0x2a:0x5 DW_TAG_pointer_type
	.long	47                      ## DW_AT_type
	.byte	3                       ## Abbrev [3] 0x2f:0xb DW_TAG_typedef
	.long	58                      ## DW_AT_type
	.long	166                     ## DW_AT_name
	.byte	1                       ## DW_AT_decl_file
	.byte	33                      ## DW_AT_decl_line
	.byte	4                       ## Abbrev [4] 0x3a:0x2d DW_TAG_structure_type
	.long	170                     ## DW_AT_name
	.byte	24                      ## DW_AT_byte_size
	.byte	1                       ## DW_AT_decl_file
	.byte	27                      ## DW_AT_decl_line
	.byte	5                       ## Abbrev [5] 0x42:0xc DW_TAG_member
	.long	174                     ## DW_AT_name
	.long	103                     ## DW_AT_type
	.byte	1                       ## DW_AT_decl_file
	.byte	29                      ## DW_AT_decl_line
	.byte	0                       ## DW_AT_data_member_location
	.byte	5                       ## Abbrev [5] 0x4e:0xc DW_TAG_member
	.long	184                     ## DW_AT_name
	.long	115                     ## DW_AT_type
	.byte	1                       ## DW_AT_decl_file
	.byte	30                      ## DW_AT_decl_line
	.byte	8                       ## DW_AT_data_member_location
	.byte	5                       ## Abbrev [5] 0x5a:0xc DW_TAG_member
	.long	216                     ## DW_AT_name
	.long	169                     ## DW_AT_type
	.byte	1                       ## DW_AT_decl_file
	.byte	31                      ## DW_AT_decl_line
	.byte	16                      ## DW_AT_data_member_location
	.byte	0                       ## End Of Children Mark
	.byte	2                       ## Abbrev [2] 0x67:0x5 DW_TAG_pointer_type
	.long	108                     ## DW_AT_type
	.byte	6                       ## Abbrev [6] 0x6c:0x7 DW_TAG_base_type
	.long	179                     ## DW_AT_name
	.byte	6                       ## DW_AT_encoding
	.byte	1                       ## DW_AT_byte_size
	.byte	2                       ## Abbrev [2] 0x73:0x5 DW_TAG_pointer_type
	.long	120                     ## DW_AT_type
	.byte	3                       ## Abbrev [3] 0x78:0xb DW_TAG_typedef
	.long	131                     ## DW_AT_type
	.long	189                     ## DW_AT_name
	.byte	1                       ## DW_AT_decl_file
	.byte	16                      ## DW_AT_decl_line
	.byte	4                       ## Abbrev [4] 0x83:0x21 DW_TAG_structure_type
	.long	196                     ## DW_AT_name
	.byte	16                      ## DW_AT_byte_size
	.byte	1                       ## DW_AT_decl_file
	.byte	11                      ## DW_AT_decl_line
	.byte	5                       ## Abbrev [5] 0x8b:0xc DW_TAG_member
	.long	203                     ## DW_AT_name
	.long	164                     ## DW_AT_type
	.byte	1                       ## DW_AT_decl_file
	.byte	13                      ## DW_AT_decl_line
	.byte	0                       ## DW_AT_data_member_location
	.byte	5                       ## Abbrev [5] 0x97:0xc DW_TAG_member
	.long	211                     ## DW_AT_name
	.long	169                     ## DW_AT_type
	.byte	1                       ## DW_AT_decl_file
	.byte	14                      ## DW_AT_decl_line
	.byte	8                       ## DW_AT_data_member_location
	.byte	0                       ## End Of Children Mark
	.byte	2                       ## Abbrev [2] 0xa4:0x5 DW_TAG_pointer_type
	.long	169                     ## DW_AT_type
	.byte	6                       ## Abbrev [6] 0xa9:0x7 DW_TAG_base_type
	.long	207                     ## DW_AT_name
	.byte	5                       ## DW_AT_encoding
	.byte	4                       ## DW_AT_byte_size
	.byte	7                       ## Abbrev [7] 0xb0:0x1 DW_TAG_pointer_type
	.byte	8                       ## Abbrev [8] 0xb1:0x68 DW_TAG_module
	.long	222                     ## DW_AT_name
	.long	229                     ## DW_AT_LLVM_config_macros
	.long	241                     ## DW_AT_LLVM_include_path
	.long	353                     ## DW_AT_LLVM_isysroot
	.byte	8                       ## Abbrev [8] 0xc2:0x56 DW_TAG_module
	.long	453                     ## DW_AT_name
	.long	229                     ## DW_AT_LLVM_config_macros
	.long	241                     ## DW_AT_LLVM_include_path
	.long	353                     ## DW_AT_LLVM_isysroot
	.byte	8                       ## Abbrev [8] 0xd3:0x22 DW_TAG_module
	.long	455                     ## DW_AT_name
	.long	229                     ## DW_AT_LLVM_config_macros
	.long	241                     ## DW_AT_LLVM_include_path
	.long	353                     ## DW_AT_LLVM_isysroot
	.byte	3                       ## Abbrev [3] 0xe4:0xb DW_TAG_typedef
	.long	239                     ## DW_AT_type
	.long	637                     ## DW_AT_name
	.byte	3                       ## DW_AT_decl_file
	.byte	153                     ## DW_AT_decl_line
	.byte	9                       ## Abbrev [9] 0xef:0x5 DW_TAG_structure_type
	.long	642                     ## DW_AT_name
                                        ## DW_AT_declaration
	.byte	0                       ## End Of Children Mark
	.byte	10                      ## Abbrev [10] 0xf5:0x11 DW_TAG_module
	.long	461                     ## DW_AT_name
	.long	229                     ## DW_AT_LLVM_config_macros
	.long	241                     ## DW_AT_LLVM_include_path
	.long	353                     ## DW_AT_LLVM_isysroot
	.byte	10                      ## Abbrev [10] 0x106:0x11 DW_TAG_module
	.long	468                     ## DW_AT_name
	.long	229                     ## DW_AT_LLVM_config_macros
	.long	241                     ## DW_AT_LLVM_include_path
	.long	353                     ## DW_AT_LLVM_isysroot
	.byte	0                       ## End Of Children Mark
	.byte	0                       ## End Of Children Mark
	.byte	11                      ## Abbrev [11] 0x119:0x7 DW_TAG_imported_declaration
	.byte	2                       ## DW_AT_decl_file
	.byte	10                      ## DW_AT_decl_line
	.long	211                     ## DW_AT_import
	.byte	11                      ## Abbrev [11] 0x120:0x7 DW_TAG_imported_declaration
	.byte	2                       ## DW_AT_decl_file
	.byte	11                      ## DW_AT_decl_line
	.long	245                     ## DW_AT_import
	.byte	11                      ## Abbrev [11] 0x127:0x7 DW_TAG_imported_declaration
	.byte	2                       ## DW_AT_decl_file
	.byte	12                      ## DW_AT_decl_line
	.long	262                     ## DW_AT_import
	.byte	12                      ## Abbrev [12] 0x12e:0x28 DW_TAG_subprogram
	.quad	Lfunc_begin0            ## DW_AT_low_pc
Lset7 = Lfunc_end0-Lfunc_begin0         ## DW_AT_high_pc
	.long	Lset7
	.byte	1                       ## DW_AT_frame_base
	.byte	86
	.long	572                     ## DW_AT_name
	.byte	2                       ## DW_AT_decl_file
	.byte	3                       ## DW_AT_decl_line
                                        ## DW_AT_prototyped
	.long	42                      ## DW_AT_type
                                        ## DW_AT_external
	.byte	13                      ## Abbrev [13] 0x147:0xe DW_TAG_variable
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	120
	.long	615                     ## DW_AT_name
	.byte	2                       ## DW_AT_decl_file
	.byte	5                       ## DW_AT_decl_line
	.long	42                      ## DW_AT_type
	.byte	0                       ## End Of Children Mark
	.byte	12                      ## Abbrev [12] 0x156:0x60 DW_TAG_subprogram
	.quad	Lfunc_begin1            ## DW_AT_low_pc
Lset8 = Lfunc_end1-Lfunc_begin1         ## DW_AT_high_pc
	.long	Lset8
	.byte	1                       ## DW_AT_frame_base
	.byte	86
	.long	579                     ## DW_AT_name
	.byte	2                       ## DW_AT_decl_file
	.byte	12                      ## DW_AT_decl_line
                                        ## DW_AT_prototyped
	.long	169                     ## DW_AT_type
                                        ## DW_AT_external
	.byte	14                      ## Abbrev [14] 0x16f:0xe DW_TAG_formal_parameter
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	112
	.long	619                     ## DW_AT_name
	.byte	2                       ## DW_AT_decl_file
	.byte	12                      ## DW_AT_decl_line
	.long	103                     ## DW_AT_type
	.byte	14                      ## Abbrev [14] 0x17d:0xe DW_TAG_formal_parameter
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	104
	.long	627                     ## DW_AT_name
	.byte	2                       ## DW_AT_decl_file
	.byte	12                      ## DW_AT_decl_line
	.long	42                      ## DW_AT_type
	.byte	13                      ## Abbrev [13] 0x18b:0xe DW_TAG_variable
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	96
	.long	634                     ## DW_AT_name
	.byte	2                       ## DW_AT_decl_file
	.byte	14                      ## DW_AT_decl_line
	.long	648                     ## DW_AT_type
	.byte	13                      ## Abbrev [13] 0x199:0xe DW_TAG_variable
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	88
	.long	650                     ## DW_AT_name
	.byte	2                       ## DW_AT_decl_file
	.byte	21                      ## DW_AT_decl_line
	.long	103                     ## DW_AT_type
	.byte	13                      ## Abbrev [13] 0x1a7:0xe DW_TAG_variable
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	84
	.long	654                     ## DW_AT_name
	.byte	2                       ## DW_AT_decl_file
	.byte	22                      ## DW_AT_decl_line
	.long	169                     ## DW_AT_type
	.byte	0                       ## End Of Children Mark
	.byte	15                      ## Abbrev [15] 0x1b6:0x24 DW_TAG_subprogram
	.quad	Lfunc_begin2            ## DW_AT_low_pc
Lset9 = Lfunc_end2-Lfunc_begin2         ## DW_AT_high_pc
	.long	Lset9
	.byte	1                       ## DW_AT_frame_base
	.byte	86
	.long	587                     ## DW_AT_name
	.byte	2                       ## DW_AT_decl_file
	.byte	36                      ## DW_AT_decl_line
                                        ## DW_AT_prototyped
                                        ## DW_AT_external
	.byte	14                      ## Abbrev [14] 0x1cb:0xe DW_TAG_formal_parameter
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	120
	.long	658                     ## DW_AT_name
	.byte	2                       ## DW_AT_decl_file
	.byte	36                      ## DW_AT_decl_line
	.long	42                      ## DW_AT_type
	.byte	0                       ## End Of Children Mark
	.byte	15                      ## Abbrev [15] 0x1da:0x40 DW_TAG_subprogram
	.quad	Lfunc_begin3            ## DW_AT_low_pc
Lset10 = Lfunc_end3-Lfunc_begin3        ## DW_AT_high_pc
	.long	Lset10
	.byte	1                       ## DW_AT_frame_base
	.byte	86
	.long	596                     ## DW_AT_name
	.byte	2                       ## DW_AT_decl_file
	.byte	41                      ## DW_AT_decl_line
                                        ## DW_AT_prototyped
                                        ## DW_AT_external
	.byte	14                      ## Abbrev [14] 0x1ef:0xe DW_TAG_formal_parameter
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	104
	.long	627                     ## DW_AT_name
	.byte	2                       ## DW_AT_decl_file
	.byte	41                      ## DW_AT_decl_line
	.long	42                      ## DW_AT_type
	.byte	14                      ## Abbrev [14] 0x1fd:0xe DW_TAG_formal_parameter
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	100
	.long	665                     ## DW_AT_name
	.byte	2                       ## DW_AT_decl_file
	.byte	41                      ## DW_AT_decl_line
	.long	169                     ## DW_AT_type
	.byte	14                      ## Abbrev [14] 0x20b:0xe DW_TAG_formal_parameter
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	112
	.long	672                     ## DW_AT_name
	.byte	2                       ## DW_AT_decl_file
	.byte	41                      ## DW_AT_decl_line
	.long	120                     ## DW_AT_type
	.byte	0                       ## End Of Children Mark
	.byte	12                      ## Abbrev [12] 0x21a:0x45 DW_TAG_subprogram
	.quad	Lfunc_begin4            ## DW_AT_low_pc
Lset11 = Lfunc_end4-Lfunc_begin4        ## DW_AT_high_pc
	.long	Lset11
	.byte	1                       ## DW_AT_frame_base
	.byte	86
	.long	602                     ## DW_AT_name
	.byte	2                       ## DW_AT_decl_file
	.byte	46                      ## DW_AT_decl_line
                                        ## DW_AT_prototyped
	.long	120                     ## DW_AT_type
                                        ## DW_AT_external
	.byte	16                      ## Abbrev [16] 0x233:0xf DW_TAG_formal_parameter
Lset12 = Ldebug_loc0-Lsection_debug_loc ## DW_AT_location
	.long	Lset12
	.long	627                     ## DW_AT_name
	.byte	2                       ## DW_AT_decl_file
	.byte	46                      ## DW_AT_decl_line
	.long	47                      ## DW_AT_type
	.byte	14                      ## Abbrev [14] 0x242:0xe DW_TAG_formal_parameter
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	108
	.long	665                     ## DW_AT_name
	.byte	2                       ## DW_AT_decl_file
	.byte	46                      ## DW_AT_decl_line
	.long	169                     ## DW_AT_type
	.byte	13                      ## Abbrev [13] 0x250:0xe DW_TAG_variable
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	88
	.long	615                     ## DW_AT_name
	.byte	2                       ## DW_AT_decl_file
	.byte	48                      ## DW_AT_decl_line
	.long	120                     ## DW_AT_type
	.byte	0                       ## End Of Children Mark
	.byte	12                      ## Abbrev [12] 0x25f:0x29 DW_TAG_subprogram
	.quad	Lfunc_begin5            ## DW_AT_low_pc
Lset13 = Lfunc_end5-Lfunc_begin5        ## DW_AT_high_pc
	.long	Lset13
	.byte	1                       ## DW_AT_frame_base
	.byte	86
	.long	211                     ## DW_AT_name
	.byte	2                       ## DW_AT_decl_file
	.byte	53                      ## DW_AT_decl_line
                                        ## DW_AT_prototyped
	.long	169                     ## DW_AT_type
                                        ## DW_AT_external
	.byte	16                      ## Abbrev [16] 0x278:0xf DW_TAG_formal_parameter
Lset14 = Ldebug_loc1-Lsection_debug_loc ## DW_AT_location
	.long	Lset14
	.long	627                     ## DW_AT_name
	.byte	2                       ## DW_AT_decl_file
	.byte	53                      ## DW_AT_decl_line
	.long	47                      ## DW_AT_type
	.byte	0                       ## End Of Children Mark
	.byte	2                       ## Abbrev [2] 0x288:0x5 DW_TAG_pointer_type
	.long	228                     ## DW_AT_type
	.byte	0                       ## End Of Children Mark
Lcu_begin1:
	.long	38                      ## Length of Unit
	.short	4                       ## DWARF version number
Lset15 = Lsection_abbrev-Lsection_abbrev ## Offset Into Abbrev. Section
	.long	Lset15
	.byte	8                       ## Address Size (in bytes)
	.byte	17                      ## Abbrev [17] 0xb:0x1f DW_TAG_compile_unit
	.long	0                       ## DW_AT_producer
	.short	12                      ## DW_AT_language
	.long	222                     ## DW_AT_name
Lset16 = Lline_table_start0-Lsection_line ## DW_AT_stmt_list
	.long	Lset16
	.long	241                     ## DW_AT_comp_dir
                                        ## DW_AT_APPLE_optimized
	.quad	6797125944843488503     ## DW_AT_GNU_dwo_id
	.long	475                     ## DW_AT_GNU_dwo_name
	.section	__DWARF,__debug_ranges,regular,debug
Ldebug_range:
	.section	__DWARF,__debug_macinfo,regular,debug
Ldebug_macinfo:
Lcu_macro_begin0:
Lcu_macro_begin1:
	.byte	0                       ## End Of Macro List Mark
	.section	__DWARF,__apple_names,regular,debug
Lnames_begin:
	.long	1212240712              ## Header Magic
	.short	1                       ## Header Version
	.short	0                       ## Header Hash Function
	.long	6                       ## Header Bucket Count
	.long	6                       ## Header Hash Count
	.long	12                      ## Header Data Length
	.long	0                       ## HeaderData Die Offset Base
	.long	1                       ## HeaderData Atom Count
	.short	1                       ## DW_ATOM_die_offset
	.short	6                       ## DW_FORM_data4
	.long	-1                      ## Bucket 0
	.long	-1                      ## Bucket 1
	.long	-1                      ## Bucket 2
	.long	0                       ## Bucket 3
	.long	3                       ## Bucket 4
	.long	5                       ## Bucket 5
	.long	266110905               ## Hash in Bucket 3
	.long	1577083461              ## Hash in Bucket 3
	.long	1893915105              ## Hash in Bucket 3
	.long	274826578               ## Hash in Bucket 4
	.long	2090724832              ## Hash in Bucket 4
	.long	-1514702201             ## Hash in Bucket 5
	.long	LNames2-Lnames_begin    ## Offset in Bucket 3
	.long	LNames0-Lnames_begin    ## Offset in Bucket 3
	.long	LNames4-Lnames_begin    ## Offset in Bucket 3
	.long	LNames5-Lnames_begin    ## Offset in Bucket 4
	.long	LNames3-Lnames_begin    ## Offset in Bucket 4
	.long	LNames1-Lnames_begin    ## Offset in Bucket 5
LNames2:
	.long	572                     ## newBDD
	.long	1                       ## Num DIEs
	.long	302
	.long	0
LNames0:
	.long	587                     ## closeBDD
	.long	1                       ## Num DIEs
	.long	438
	.long	0
LNames4:
	.long	579                     ## openBDD
	.long	1                       ## Num DIEs
	.long	342
	.long	0
LNames5:
	.long	596                     ## store
	.long	1                       ## Num DIEs
	.long	474
	.long	0
LNames3:
	.long	211                     ## size
	.long	1                       ## Num DIEs
	.long	607
	.long	0
LNames1:
	.long	602                     ## getNupletBdd
	.long	1                       ## Num DIEs
	.long	538
	.long	0
	.section	__DWARF,__apple_objc,regular,debug
Lobjc_begin:
	.long	1212240712              ## Header Magic
	.short	1                       ## Header Version
	.short	0                       ## Header Hash Function
	.long	1                       ## Header Bucket Count
	.long	0                       ## Header Hash Count
	.long	12                      ## Header Data Length
	.long	0                       ## HeaderData Die Offset Base
	.long	1                       ## HeaderData Atom Count
	.short	1                       ## DW_ATOM_die_offset
	.short	6                       ## DW_FORM_data4
	.long	-1                      ## Bucket 0
	.section	__DWARF,__apple_namespac,regular,debug
Lnamespac_begin:
	.long	1212240712              ## Header Magic
	.short	1                       ## Header Version
	.short	0                       ## Header Hash Function
	.long	1                       ## Header Bucket Count
	.long	0                       ## Header Hash Count
	.long	12                      ## Header Data Length
	.long	0                       ## HeaderData Die Offset Base
	.long	1                       ## HeaderData Atom Count
	.short	1                       ## DW_ATOM_die_offset
	.short	6                       ## DW_FORM_data4
	.long	-1                      ## Bucket 0
	.section	__DWARF,__apple_types,regular,debug
Ltypes_begin:
	.long	1212240712              ## Header Magic
	.short	1                       ## Header Version
	.short	0                       ## Header Hash Function
	.long	7                       ## Header Bucket Count
	.long	7                       ## Header Hash Count
	.long	20                      ## Header Data Length
	.long	0                       ## HeaderData Die Offset Base
	.long	3                       ## HeaderData Atom Count
	.short	1                       ## DW_ATOM_die_offset
	.short	6                       ## DW_FORM_data4
	.short	3                       ## DW_ATOM_die_tag
	.short	5                       ## DW_FORM_data2
	.short	4                       ## DW_ATOM_type_flags
	.short	11                      ## DW_FORM_data1
	.long	0                       ## Bucket 0
	.long	1                       ## Bucket 1
	.long	2                       ## Bucket 2
	.long	3                       ## Bucket 3
	.long	4                       ## Bucket 4
	.long	5                       ## Bucket 5
	.long	-1                      ## Bucket 6
	.long	193487119               ## Hash in Bucket 0
	.long	-1006587011             ## Hash in Bucket 1
	.long	193451183               ## Hash in Bucket 2
	.long	193495088               ## Hash in Bucket 3
	.long	284880957               ## Hash in Bucket 4
	.long	2089071269              ## Hash in Bucket 5
	.long	2090147939              ## Hash in Bucket 5
	.long	Ltypes4-Ltypes_begin    ## Offset in Bucket 0
	.long	Ltypes1-Ltypes_begin    ## Offset in Bucket 1
	.long	Ltypes3-Ltypes_begin    ## Offset in Bucket 2
	.long	Ltypes5-Ltypes_begin    ## Offset in Bucket 3
	.long	Ltypes2-Ltypes_begin    ## Offset in Bucket 4
	.long	Ltypes0-Ltypes_begin    ## Offset in Bucket 5
	.long	Ltypes6-Ltypes_begin    ## Offset in Bucket 5
Ltypes4:
	.long	170                     ## bdd
	.long	1                       ## Num DIEs
	.long	58
	.short	19
	.byte	0
	.long	0
Ltypes1:
	.long	189                     ## NUPLET
	.long	1                       ## Num DIEs
	.long	120
	.short	22
	.byte	0
	.long	0
Ltypes3:
	.long	166                     ## BDD
	.long	1                       ## Num DIEs
	.long	47
	.short	22
	.byte	0
	.long	0
Ltypes5:
	.long	207                     ## int
	.long	1                       ## Num DIEs
	.long	169
	.short	36
	.byte	0
	.long	0
Ltypes2:
	.long	196                     ## nuplet
	.long	1                       ## Num DIEs
	.long	131
	.short	19
	.byte	0
	.long	0
Ltypes0:
	.long	637                     ## FILE
	.long	1                       ## Num DIEs
	.long	228
	.short	22
	.byte	0
	.long	0
Ltypes6:
	.long	179                     ## char
	.long	1                       ## Num DIEs
	.long	108
	.short	36
	.byte	0
	.long	0

.subsections_via_symbols
	.section	__DWARF,__debug_line,regular,debug
Lsection_line:
Lline_table_start0:
