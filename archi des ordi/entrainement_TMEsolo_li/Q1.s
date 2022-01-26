.data
	recette_depense : .word 200, 150, 20, 30, 1100, 1000, 100  # 0X1001 0000
	.align 2
	chaine_rd : .asciiz "RDDDRDD" # 0x1001 001c
	ch_ok : .asciiz "bilan juste\n" # 0x1001 0024
	ch_nok : .asciiz "passage à decouvert ou mauvais calcul\n" #0x 1001 0031

.text
### main should be the first function
main:
	# prologue nv = 1, na = 2
	addiu $29, $29, -12
	# appel de fonction
	lui $4, 0x1001
	lui $5, 0x1001
	addiu $5, $5, 0x1c
	jal bon_budget
	ori $16, $2, 0
	# printf
nok:
	beq $16, $0, ok
	ori $4, $0, 0
	lui $4, 0x1001
	###ori $4, 0x31
	ori $4, $4, 0x31 ###
	ori $2, $0, 4
	syscall
	j fin_ok
ok:	
	ori $4, $0, 0
	lui $4, 0x1001
	### ori $4, $4, 0x24
	ori $4, $4, 0x31 ###
	ori $2, $0, 4
	syscall
fin_ok:
	#épilogue
	addiu $29, $29, 12
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
		
