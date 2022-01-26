.data
	a: .byte 0x02
	b: .half 0x0014
	tab: .word 0xFFFFFFFE, 0xFFFFFFFC
	c: .byte -1

.text
	#prologue nr = 0, nv = 2, na = 1 ### non, arg = 0
	addiu $29, $29, -12 # should be -8
	#ini
	lui $8, 0x1001
	# tmp1 = tab[1]
	lw $9, 8($8)
	sw $9, 4($29) 
	# tmp2 = a
	lb $9, 0($8)
	sb $9, 8($29) 
	# tmp3 = c
	lb $9, 12($8)
	sb $9, 9($29)
	
	#calcul
	# tmp3 = tmp3 + tmp1 + tmp2
	lb $10, 9($29)
	lw $11, 4($29)
	lb $12, 9($29)
	addu $10, $10, $11
	addu $10, $10, $12
	sb $10, 9($29)
	# b = b + tmp3
	lui $8, 0x1001
	lh $12, 2($8)
	lb $10, 9($29)
	addu $12, $12, $10
	sh $12, 2($8)
	
	#printf
	lh $4, 2($8)
	ori $2, $0, 1
	syscall
	
	###épilogue à écrire
	# addiu $29, $29, 8
	
	#terminaison
	ori $2, $0, 10
	syscall
	
	