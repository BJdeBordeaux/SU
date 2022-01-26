.data
	size : .word 5 # 0x1001 0000
	.align 2
	tab1 : .space 20 # 0x1001 0004
	.align 2
	tab2 : .space 20 # 0x1001 0018
	
.text
	main:
		# prologue nv = 1, na = 2
		addiu $29, $29, -28
		
		# $16 : i	$17 : size	$18 : res
		ori $16, $0, 0
		lui $8, 0x1001
		lw $17, 0($8)
	while : 
		slt $9, $16, $17
		beq $9, $0, fin_while
		# scanf
		ori $2, $0, 5
		syscall
	if:
		blez $2, fin_if
		# tab1 + 4i
		lui $8, 0x1001
		ori $8, $8, 4
		sll $9, $16, 2
		addu $8, $8, $9
		sw $2, 0($8)
		addiu $16, $16, 1
	fin_if:
		j while
	fin_while:
		#appel fonction 
		lui $4, 0x1001
		ori $4, $4, 4
		addiu $5, $4, 20
		ori $6, $0, 0
		addiu $7, $17, -1
		jal somme_cumul
		# printf
		ori $18, $2, 0
		ori $4, $2, 0
		ori $2, $0, 1
		syscall
		# épilogue 
		addiu $29, $29, 12
		ori $2, $0, 10
		syscall
	
	somme_cumul: 
		# prologue : nr = 4, nv = 1, na = 4
		addiu $29, $29, -36
		sw $31, 32($29)
		sw $16, 28($29)
		sw $17, 24($29)
		sw $18, 20($29)
		sw $4, 0($29)
		sw $5, 4($29)
		sw $6, 8($29)
		sw $7, 12($29)
		
		# ini $16 : tab1 + 4i,	$17 : tab2 + 4i		$18 : res
		sll $8, $6, 2
		addu $16, $8, $4
		addu $17, $8, $5
		
	base:
		bne $6, $7, rec
		lw $9, 0($16)
		sw $9, 0($17)
		j fin_rec
	rec:
		# appel rec
		addiu $6, $6, 1
		jal somme_cumul
		ori $18, $2, 0
		# tab2[i] = tab1[i] + res
		lw $9, 0($16)
		addu $9, $2, $9
		sw $9, 0($17)
	fin_rec:
		lw $2, 0($17)
		# épilogue
		lw $31, 32($29)
		lw $16, 28($29)
		lw $17, 24($29)
		lw $18, 20($29)
		addiu $29, $29, 36
		jr $31