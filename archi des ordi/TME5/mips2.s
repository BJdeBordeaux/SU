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
	lw $9, 0($8) # tmpa

	#lecture b
	ori $2, $0, 5
	syscall
	sw $2, 4($8)
	lw $10, 4($8) # tmpb
	#calcul

loop:
	#élaboration de condition while a!=b
	beq $9, $10, fin
	#if élaboration
	slt $11, $9, $10
	bne $11,$0,else
	subu $9, $9,$10
	j loop
else:
	subu $10,$10,$9	
	j loop

	

fin:
	ori $2, $0, 1
	ori $4, $10, 0
	syscall 
	
	ori $2, $0, 10
	syscall 