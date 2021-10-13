.data

	tab: .word  4, 23, 12, 3, 8, 1
	.align 2
	s: .space 4
	p: .space 4
	
.text

	lui $8, 0x1001
	ori $9, $8, 0x18  #$9: s
	addiu $10, $9, 4 #$10:p
	
	# s = tab[3]
	lw $16, 12 ($8)
	sw $16, 0($9)
	
	# p = tab[4]
	lw $16, 16 ($8)
	sw $16, 0($10)
	
	#tab[0] = s+1
	lw $17, 0($9)
	addiu $16, $17, 1
	sw $16, 0($8)
	
	#tab[1] = s+p
	lw $18, 0($10)
	addu $16, $17, $18
	sw $16, 4($8)
	
	#tab[2] = s+5
	lw $16, 20($8)
	sw $16, 8($8)
	
	ori $2, $0, 10
	syscall
	