.data
	.align 2
	a : .space 4
	b : .space 4

.text
main:
	lui $8, 0x1001 # a

	#lecture a 
	ori $2, $0, 5
	syscall
	sw $2, 0($8)
	lw $9, 0($8)

	#lecture b
	ori $2, $0, 5
	syscall
	sw $2, 4($8)
	lw $10, 4($8)
	
	ori $11, $0, 0 # somme
	#calcul
#if:
	# p >= q saut
#	slt $12, $9, $10
#	beq $12, $0, fin

loop:
	#élaboration de condition a<b
	addiu $9, $9, 1
	slt $12, $9, $10
	beq $12, $0, fin
	addu $11, $11, $9
	j loop

fin:
	ori $2, $0, 1
	ori $4, $11, 0
	syscall 
	ori $2, $0, 10
	syscall 