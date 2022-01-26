.data
	recette_depense : .word 200, 150, 20, 30, 1100, 1000, 110
	# 0x1001 0000
	chaine_rd : .asciiz "RDDDRDD" # 0x1001 001C
	ch_ok : .asciiz "bilan juste\n" # 0x1001 0024
	ck_nok : .asciiz "passage à decouvert ou mauvais calcul\n"
	# 0x1001 0031
	
.text
	main:
		# prologue nv = 1, na = 2
		addiu $29, $29, -12
		
		# $16 : ok
		ori $16, $0, 0
		
		# appel de fonction
		lui $4, 0x1001
		lui $5, 0x1001
		addiu $5, $5, 0x1c
		jal bon_budget
		ori $16, $2, 0 
		
		# condition
	if_nok:
		beq $16, $0, else_
		ori $4, $0, 0
		lui $4, 0x1001
		ori $4, $4, 0x31
		ori $2, $0, 4
		syscall
		j fin_if
	else_:
		ori $4, $0, 0
		lui $4, 0x1001
		ori $4, $4, 0x24
		ori $2, $0, 4
		syscall
		j fin_if
	fin_if:
		# appel de fonction récursive
		ori $4, $0, 0
		lui $4, 0x1001
		addiu $5, $4, 0x1c
		ori $6, $0, 0
		jal bon_budget_rec
		ori $16, $2, 0
	ok_rec:
		bne $16, $0, nok_rec
		ori $4, $0, 0
		lui $4, 0x1001
		ori $4, $4, 0x24
		syscall
		j fin_ok_rec
	nok_rec:
		ori $4, $0, 0
		lui $4, 0x1001
		ori $4, $4, 0x31
		syscall

	fin_ok_rec:
		# épilogue 
		addiu $29, $29, 12
		ori $2, $0, 10
		syscall

	bon_budget:
		# $4 : t, $5 : s
		# prologue : nr = 5, nv = 2, na = 0
		addiu $29, $29, -28
		sw $31, 24($29)
		sw $16, 20($29)
		sw $17, 16($29)
		sw $18, 12($29)
		sw $19, 8($29)
		
		# $16 : d, 	$17: i
		ori $16, $0, 0
		ori $17, $0, 0
		# $18 : s[i],	$19 : t[i]
		# $8 : 'R', $9 : 'D'
		ori $8, $0, 'R'
		ori $9, $0, 'D'
	while :
		addu $10, $5, $17
		lb $18, 0($10) # s[i]
		beq $18, $0, fin_while
		sll $11, $17, 2
		addu $11, $11, $4
		lw $19, 0($11) # t[i] 
	if_r:
		bne $18, $8, else_r
		addu $16, $16, $19
		j iflt
	else_r:
		subu $16, $16, $19
	iflt:
		bltz $16, fin_while
	fin_if_lt:
		addiu $17, $17, 1
		j while
	fin_while:

		### ori $16, $2, 0
		### which will make result to be the same evertime
		ori $2, $16, 0
		# épilogue
		lw $31, 24($29)
		lw $16, 20($29)
		lw $17, 16($29)
		lw $18, 12($29)
		lw $19, 8($29)
		addiu $29, $29, 28
		jr $31
		
	bon_budget_rec:
		# prologue nr = 4, nv = 1, na = 3
		addiu $29, $29, -32
		sw $31, 28($29)
		sw $16, 24($29)
		sw $17, 20($29)
		sw $18, 16($29)
		sw $4, 32($29)
		sw $5, 36($29)
		sw $6, 40($29)
		
		# init
		# $16 : d, 	$17 : tab[i], 	$18 : ch[i]
		ori $16, $0, 0
		sll $8, $6, 2
		addu $8, $4, $8
		lw $17, 0($8)
		addu $9, $5, $6
		lbu $18, 0($9)
		
		# rec_fin
		beq $16, $0, fin_if_rec ### if absent, dead loop
		
		# appel de fonction recursive
		lw $4, 32($29)
		lw $5, 36($29)
		lw $6, 40($29)
		addiu $6, $6, 1
		jal bon_budget_rec
		ori $16, $2, 0
	if_d:
		bgtz $16, fin_if_rec
	if_r_rec:
		addu $16, $16, $17
		j fin_if_rec
	else_r_rec:
		subu $16, $16, $17
	fin_if_rec:	
		# épilogue
		lw $31, 28($29)
		lw $16, 24($29)
		lw $17, 20($29)
		lw $18, 16($29)
		addiu $29, $29, 32
		jr $31