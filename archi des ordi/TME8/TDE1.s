.data

.text
	main:
		# prologue nv = 2, na = 2
		addiu $29, $29, -16
		
		# init
		# $16: x, $17 : p
		ori $16, $0, 3
		ori $17, $0, 2
		
		# appel1
		ori $4, $16, 0
		ori $5, $17, 0
		jal puissance
		
		# printf1
		ori $4, $2, 0
		ori $2, $0, 1
		syscall
		
		# appel2
		ori $4, $0, 2
		ori $5, $0, 6
		jal puissance
		
		# printf1
		ori $4, $2, 0
		ori $2, $0, 1
		syscall
		
		# épilogue
		addiu $29, $29, 16
		ori $2, $0, 10
		syscall
		
	puissance:
		# $4: x , $5: n
		# prologue : nr = 2, nv = 1, na = 2
		addiu $29, $29, -20
		sw $31, 16($29)
		sw $16, 12($29)
		sw $4, 20($29)
		### sw $5, 20($29)
		sw $5, 24($29) ###
		# $16: tmp
		if_pui:
			bne $5, $0, else_pui
			ori $2, $0, 1
			j fin_if_pui
		else_pui:
			lw $4, 20($29)
			lw $5, 24($29)
			addiu $5, $5, -1
			jal puissance
			ori $16, $2, 0
			lw $4, 20($29)
			mult $4, $16
			mflo $2
		fin_if_pui:
		# épilogue
		lw $31, 16($29)
		lw $16, 12($29)
		addiu $29, $29, 20
		jr $31