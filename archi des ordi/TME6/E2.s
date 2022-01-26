.data
	p1: 	.asciiz "X"	# 0x1001 0000 
		.word 2, 6 
	p2:	.asciiz "Y"	# 0x1001 000c
		.word 4, 4
	.align 2
	p3:	.space 12 	# 0x1001 0018
	.align 2
	ptr: 	.space 4	# 0x1001 0024

.text
	main:
		lui $8, 0x1001		# &p1
		ori $9, $8, 0x18 	# &p3
		ori $10, $8, 0x24	# &ptr
		sw $9, 0($10)
		ori $11, $8, 0x0c	# &p2
		
		# abs
		lw $12, 4($8)
		lw $13, 4($11)
		addu $13, $12, $13
		ori $12, $0, 2
		div $13, $12
		mflo $12
		lw $13, 0($10) ### affectation via pointer, we should first lw $pointee ($pointer), then sw $r ($pointee)
		### sw $12, 4($10)
		sw $12, 4($13) ###

		# ord
		lw $12, 8($8)
		lw $13, 8($11)
		addu $13, $12, $13
		ori $12, $0, 2
		div $13, $12
		mflo $12
		lw $13, 0($10)
		sw $12, 8($13)
		
		# 'Z'
		ori $12, $0, 'Z'
		lw $13, 0($10)
		sb $12, 0($13)
		sb $0, 1($13)
		
		# printf nom
		### lb $4, 0($9) 
		lw $4, 0($10) ### in the parenthese, should be @str
		ori $2, $0, 4
		syscall
		
		# printf abs
		lw $4, 4($9)
		ori $2, $0, 1
		syscall

		# printf ord
		lw $4, 8($9)
		ori $2, $0, 1
		syscall
		
		# épilogue
		ori $2, $0, 10
		syscall