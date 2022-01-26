.data
	.align 2
	s: .space 20 # 0x1001 0000
	ch_ok: .asciiz "bien parenthésé\n" # 0x1001 0014
	### ch_nok: .asciiz "mal parenthésé" # 0x1001 0025
	ch_nok: .asciiz "mal parenthésé\n" # 0x1001 0025
	### for a clearer view, add \n at the end
.text
	main:
		# prologue nv = 1, na = 2
		addiu $29, $29, -12
		
		# $16 : ok
		
		# scanf
		ori $2, $0, 8
		lui $4, 0x1001
		ori $5, $0, 20
		syscall
		
		# printf
		ori $2, $0, 4
		ori $4, $0, 0
		lui $4, 0x1001
		syscall
		
		# appel
		ori $4, $0, 0
		lui $4, 0x1001
		jal bon_parenthesage
		ori $16, $2, 0
		
		# condition
		bne $16, $0, no_ok1
		ori $4, $0, 0
		lui $4, 0x1001
		ori $4, $4, 0x14
		ori $2, $0, 4
		syscall
		j fin_ok1
	no_ok1:
		ori $4, $0, 0
		lui $4, 0x1001
		ori $4, $4, 0x25
		ori $2, $0, 4
		syscall
	fin_ok1:
		# appel de fonction récursive
		ori $4, $0, 0
		lui $4, 0x1001
		ori $5, $0, 0
		jal bon_parenthesage_rec
		ori $16, $2, 0
	ok2:
		bne $16, $0, no_ok2
		ori $4, $0, 0
		lui $4, 0x1001
		ori $4, $4, 0x14
		ori $2, $0, 4
		syscall
		j fin_ok2
	no_ok2:
		ori $4, $0, 0
		lui $4, 0x1001
		ori $4, $4, 0x25
		ori $2, $0, 4
		syscall
	fin_ok2:
		# épilogue
		addiu $29, $29, 12
		ori $2, $0, 10
		syscall

	bon_parenthesage:
		# prologue nr = 5, nv = 2, na = 0
		addiu $29, $29, -28
		sw $31, 24($29)
		sw $16, 20($29)
		sw $17, 16($29)
		sw $18, 12($29)
		sw $19, 8($29)
		# $16: d, 	$17 : i
		# $18 : ch + i,	 $19: ch[i]
		ori $16, $0, 0
		ori $17, $0, 0
		
		# $8 : '('
		addiu $8, $0, '('
		addiu $9, $0, ')'
	while:
		addu $18, $4, $17
		lbu $19, 0($18) 
		beq $19, $0, fin_while
	if_1:
		bne $19, $8, if_2
		addiu $16, $16, 1
	if_2:
		bne $19, $9, if_3
		addiu $16, $16, -1
	if_3:
		bltz $16, fin_while
		addiu $17, $17, 1
		j while
		
	fin_while:
		ori $2, $16, 0
		# épilogue
		lw $31, 24($29)
		lw $16, 20($29)
		lw $17, 16($29)
		lw $18, 12($29)
		lw $19, 8($29)
		### addiu $29, $29, -28
		addiu $29, $29, 28 ### if -28, we will return to 0
		jr $31
		
	bon_parenthesage_rec:
		# prologue nr = 4, nv = 1, na = 2
		addiu $29, $29, -28
		sw $31, 24($29)
		sw $16, 20($29)
		sw $17, 16($29)
		sw $18, 12($29)
		sw $4, 28($29)
		sw $5, 32($29)
		# $16: d, 	$17 : ch + index
		# $18 : ch[i]
		ori $16, $0, 0
		addu $17, $4, $5
		lbu $18, 0($17)
		
	base:	beq $18, $0, fin_rec
		
		lw $4, 28($29)
		lw $5, 32($29)
		addiu $5, $5, 1
		jal bon_parenthesage_rec
		ori $16, $2, 0
		# $8 : '(', $9: ')'
		addiu $8, $0, '('
		addiu $9, $0, ')'
	if1_rec:
		bgtz $16, fin_rec
	if2_rec:
		bne $18, $9, if3_rec
		addiu $16, $16, -1
		j fin_rec
	if3_rec:
		bne $18, $8, fin_rec
		addiu $16, $16, 1
		j fin_rec
	fin_rec:
		ori $2, $16, 0
		# épilogue
		lw $31, 24($29)
		lw $16, 20($29)
		lw $17, 16($29)
		lw $18, 12($29)
		### addiu $29, $29, -28
		addiu $29, $29, 28 ### if -28, we will return to 0
		jr $31