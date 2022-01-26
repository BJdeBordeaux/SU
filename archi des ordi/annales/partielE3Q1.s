.data
	size : .word 9
	ch: .asciiz "inversion"

.text
	#prologue nr = 0, nv = 3
	addiu $29, $29, -12
	#ini
	# int i = 0
###	ori $8, $0, 0 # i
	ori $18, $0, 0 # i
	lui $16, 0x1001 ### adresse size
	lw $19, 0($16)
	addiu $19, $19, -1 # j
###	sw $8, 0($29)
	# int j = size -1
###	lui $4, 0x1001 
###	lw $10, 0($4)
###	addiu $10, $10, -1 # j = size - 1
###	sw $10, 4($29)
	#printf
###	ori $4, $4, 4
	ori $4, $16, 4 
	ori $2, $0, 4
	syscall
###	ori $10, $0, 0
###	lui $10, 0x1001 # ch
	###	ori $10, $0, 4 
	ori $16, $16, 4 # ch
while:
###	lw $8, 0($29) # i
###	lw $9, 4($29) # j
###	slt $11, $8, $9
	slt $11, $18, $19
	beq $11, $0, fin_while
	# lecture de ch[j]
###	addu $11, $9, $10
	addu $11, $19, $16
	lbu $12, 0($11)
	# lecture de ch[i]
###	addu $13, $8, $10
	addu $13, $18, $16
	lbu $14, 0($13)
	# échange
	sb $12, 0($13)
	sb $14, 0($11)
	# i++
###	addiu $8, $8, 1
	addiu $18, $18, 1
###	sw $8, 0($29) ###
	# j--
###	addiu $9, $9, -1
	addiu $19, $19, -1
###	sw $9, 4($29) ###
	### $8 and $9 should be stored in stack
	j while
	
fin_while:
	#printf ch
###	lui $4, 0x1001
	### lw $4, 4($4)
###	ori $4, $4, 4
	ori $4, $16, 0
	ori $2, $0, 4
	syscall
	
	#printf i
###	lw $4, 0($29)
	ori $4, $18, 0
	ori $2, $0, 1
	syscall
	
	#épilogue à écrire
	addiu $29, $29, 12
	
	#terminaison
	ori $2, $0, 10
	syscall
	