.data
	n : .word 4

.text
	main:
		# prologue nv = 0, na = 1
		addiu $29, $29, -4
		lui $4, 0x1001 # should pass a int instead of an adresse
		lw $4, 0($4)
		jal fib
		ori $16, $2, 0
		
		# printf
		ori $4, $16, 0
		ori $2, $0, 1
		syscall
		
		# épilogue 
		addiu $29, $29, 4
		ori $2, $0, 10
		syscall
		
	fib:
		# prologue nr = 2, nv = 0, na = 1
		addiu $29, $29, -12
		sw $31, 8($29)
		sw $16, 4($29)
		sw $4, 12($29)
		# $16 : res
		ori $16, $0, 1
		base:
			beq $4, $0, fin_fib
			ori $8, $0, 1
			beq $4, $8, fin_fib
		rec:
			# fib(n-1)
			lw $4, 12($29)
			addiu $4, $4, -1
			jal fib
			addiu $16, $2, 0
			
			# fib(n-2)
			lw $4, 12($29)
			addiu $4, $4, -2
			jal fib	
			addu $16, $2, $16

		fin_fib:
		ori $2, $16, 0
		lw $31, 8($29)
		lw $16, 4($29)
		addiu $29, $29, 12
		jr $31