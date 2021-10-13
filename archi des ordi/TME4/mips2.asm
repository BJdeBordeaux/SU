.data
	v1 : .word -1
	v2 : .word 0xFF
	
.text
	lui $8 0x1001
	ori $9, $8, 0x0004
	
	lw $4, 0($8)
	addi $4, $4, 1
	sw $4,0($8)
	ori $2, $0, 1
	syscall
	
	lw $4, 0($9)
	addi $4, $4, 1
	sw $4,0($9)
	ori $2, $0, 1
	syscall
	
	ori $2, $0, 10
	syscall