.data
	recette_depense : .word 200, 150, 20, 30, 1100, 1000, 100 # 0X1001 0000
	.align 2
	chaine_rd : .asciiz "RDDDRDD" # 0x1001 001c
	ch_ok : .asciiz "bilan juste\n" # 0x1001 0024
	ch_nok : .asciiz "passage à decouvert ou mauvais calcul\n" #0x 1001 0031

.text

### main should be placecd before other functions		
main:
	# prologue nv = 1, na = 3
	addiu $29, $29, -16
	# appel de fonction
	lui $4, 0x1001
	lui $5, 0x1001
	addiu $5, $5, 0x1c
	jal bon_budget
	ori $16, $2, 0
	# printf
nok1:
	beq $16, $0, ok1
	ori $4, $0, 0
	lui $4, 0x1001
	ori $4, 0x31
	ori $2, $0, 4
	syscall
	### j fin_ok
	j fin_ok1###
ok1:	
	ori $4, $0, 0
	lui $4, 0x1001
	ori $4, 0x24
	ori $2, $0, 4
	syscall
fin_ok1:
	# appel de fonction récursive
	ori $4, $0, 0
	ori $5, $0, 0
	lui $4, 0x1001
	lui $5, 0x1001
	addiu $5, $5, 0x1c
	ori $6, $0, 0
	### main should store arguments for recursive functions
	sw $4, 0($29)
	sw $5, 4($29)
	sw $6, 8($29)
	jal bon_budget_rec
	ori $16, $2, 0
	# printf
ok2:
	bne $16, $0, nok2
	ori $4, $0, 0
	lui $4, 0x1001
	ori $4, 0x24
	ori $2, $0, 4
	syscall
	j fin_ok2
nok2:	
	ori $4, $0, 0
	lui $4, 0x1001
	ori $4, 0x31
	ori $2, $0, 4
	syscall
fin_ok2: 
	#épilogue
	addiu $29, $29, 16
	ori $2, $0, 10
	syscall


bon_budget:
		# prologue nr = 5,  nv = 2, na = 0
		addiu $29, $29, -28
		sw $31, 24($29)
		sw $16, 20($29)
		sw $17, 16($29)
		sw $18, 12($29)
		sw $19, 8($29)
		# $16 : d,		$17 : i	$18 : s+i		$19 : *(s+i)
		ori $16, $0, 0
		ori $17, $0, 0
		ori $18, $5, 0
	while:
		# while(s[i] != '\0\' )
		addu $18, $5, $17
		lbu $19, 0($18)
		beq $19, $0, fin_while
		# t[i]
		### $4 is a table of int, so *4
		sll $10, $17, 2 ###
		###addu $9, $4, $17
		addu $9, $4, $10 ###
		lw $9, 0($9)
	if1:
		# case 'R'
		ori $8, $0, 'R'
		bne $19, $8, else1
		addu $16, $16, $9
		j if2
	else1:
		# case 'D'
		subu $16, $16, $9
	if2:
		bltz $16, fin_while
		# i++
		addiu $17, $17, 1
		j while
	fin_while:
		# épilogue
		ori $2, $16, 0
		lw $31, 24($29)
		lw $16, 20($29)
		lw $17, 16($29)
		lw $18, 12($29)
		lw $19, 8($29)
		addiu $29, $29, 28
		jr $31

	
bon_budget_rec:
		### note down the arguments
		### $4 : int tab, 	$5 : char tab, 		$6 : index
		# prologue nr = 6,  nv = 1, na = 3
		addiu $29, $29, -40
		sw $31, 36($29)
		sw $16, 32($29)
		sw $17, 28($29)
		sw $18, 24($29)
		sw $19, 20($29)
		sw $20, 16($29)
		### sw $4, 0($29)
		### sw $5, 4($29)
		### sw $6, 8($29)
		sw $4, 40($29) ###
		sw $5, 44($29) ###
		sw $6, 48($29) ###
		# $16 : d,		$17 : ch + index	$18 : ch[index] 	$19 : tab + index ### tab+index*4		$20 : tab[index]
		ori $16, $0, 0
		addu $17, $5, $6
		lbu $18, 0($17)
		### addu $19, $4, $6
		sll $8, $6, 2 ### tab + index*4
		addu $19, $8, $4
		lw $20, 0($19)
	base:
		# if (ch[index] == '\0\' )
		lbu $18, 0($17)
		beq $18, $0, fin_rec
		# appel recursif
		lw $4, 40($29)
		lw $5, 44($29)
		lw $6, 48($29)
		### third argument erro : should be index +1 instead of index
		addiu $6, $6, 1 ###
		jal bon_budget_rec
		ori $16, $2, 0
	if_rec1:
		# d > 0
		bgtz $16, fin_rec
	if_rec2:
		# ch[index] == R
		ori $8, $0, 'R'
		bne $18, $8, else_rec
		addu $16, $16, $20
		j fin_rec
	else_rec:
		subu $16, $16, $20
	fin_rec:
		# épilogue
		ori $2, $16, 0
		lw $31, 36($29)
		lw $16, 32($29)
		lw $17, 28($29)
		lw $18, 24($29)
		lw $19, 20($29)
		lw $20, 16($29)
		addiu $29, $29, 40
		jr $31

