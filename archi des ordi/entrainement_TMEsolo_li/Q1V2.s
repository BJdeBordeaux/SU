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