.data
	tab: .word 23, 7, 12, 513, -1 # 0x1001 0000
					# 0x1001 0014

.text
	main:
		# prologue nv = 1 , na = 1
		addiu $29, $29, -8
	
		lui $4, 0x1001
		jal arimean
		ori $16, $2, 0
	
		# printf
		ori $4, $16, 0
		ori $2, $0, 1
		syscall
	
		# épilogue 
		addiu $29, $29, 8
		ori $2, $0, 10
		syscall
	
	arimean:
		# prologue nr = 3, nv = 2, na = 1
		addiu $29, $29, -24
		sw $31, 20($29)
		sw $16, 16($29)
		sw $17, 12($29)
		sw $4, 24($29)
		
		# init : $16 : n, 	$17 : x
		ori $16, $0, 0
		ori $17, $0, 0
		lw $4, 24($29)
		jal sizetab
		ori $16, $2, 0
		lw $4, 24($29)
		jal sumtab
		ori $17, $2, 0
		div $17, $16
		mflo $2

		# épilogue
		lw $31, 20($29)
		lw $16, 16($29)
		lw $17, 12($29)
		addiu $29, $29, 24
		jr $31
		
	sizetab:
		# prologue nr = 2, nv = 1, na = 0
		addiu $29, $29, -12
		sw $31, 8($29)
		sw $16, 4($29) ###
		sw $4, 12($29)
		# $16 : index
		ori $16, $0, 0
		
		while_size:
			sll $8, $16, 2
			### addu $4, $8, $4
			addu $8, $8, $4 ### should be added to non persistant register
			lw $9, 0($8)
			bltz $9, fin_while_size
			addiu $16, $16, 1
			j while_size
		fin_while_size:
			ori $2, $16, 0
		# épilogue
		lw $31, 8($29)
		lw $16, 4($29) ###
		addiu $29, $29, 12
		jr $31

	sumtab: 
		# prologue nr = 3, nv = 2, na = 0
		addiu $29, $29, -20
		sw $31, 16($29)
		sw $16, 12($29)
		sw $17, 8($29)
		
		# init $16 : accu,  $17 : index
		ori $16, $0, 0
		ori $17, $0, 0
		while_sum:
			sll $8, $17, 2
			addu $8, $8, $4
			lw $9, 0($8)
			bltz $9, fin_while_sum
			addu $16, $16, $9
			addiu $17, $17, 1
			### j while
			j while_sum ### nomination : utility + function + numer
	fin_while_sum:
		ori $2, $16, 0
		# épilogue
		lw $31, 16($29)
		lw $16, 12($29)
		lw $17, 8($29)
		addiu $29, $29, 20
		jr $31