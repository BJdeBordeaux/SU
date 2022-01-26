.data
	p : .word 3
	m: .word 5
	
.text
	main: 
		# prologue nr = 0, nv = 0, na = 2
		addiu $29, $29, -8

		# fact(p)
		lui $8, 0x1001
		lw $4, 0($8)
		lw $5, 4($8)
		jal puissance
		
		#affichage
		ori $4, $2, 0
		ori $2, $0, 1
		syscall
		
		# épilogue
		addiu $29, $29, 8
		
		#exit()
		ori $2, $0, 10
		syscall
		
	puissance:
		#prologue  nr = 1, nv = 1, na = 2
		addiu $29, $29, -16
		sw $31, 12($29)
		sw $4, 16($29) # x
		sw $5, 20($29) # n
		beq $5, $0, base1
		ori $8, $0, 1
		beq $5, $1, base2
	else_case:
		# res = puissance(x, n/2)
		# lw $4, 16($29)
		# lw $5, 20($29)
		ori $8, $0, 2
		div $5, $8
		mflo $5 # $5 = n/2
		jal puissance
		sw $2, 8($29)
		lw $9, 20($29) # 	$9 : n
		andi $8, $9, 0x01 # 	$8 : parité
		ori $10, $0, 1
		bne $8, $10, pair
	impair:
		mult $2, $2
		mflo $2 # 	$2 : res * res
		lw $8, 16($29) #	$8 : x
		mult $2, $8
		mflo $2 # 	$2 : res * res * x
		j fin_if
	pair:
		mult $2, $2
		mflo $2 # 	$2 : res * res
		j fin_if
	base1:
		ori $2, $0, 1
		j fin_if
	base2:
		lw $2, 16($29)
	fin_if:
		#épilogue
		lw $31, 12($29)
		addiu $29, $29, 16
		jr $31
