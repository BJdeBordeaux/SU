.data
	v1 : .byte 0xFF

	
.text
	lui $8 0x1001

	
	lb $9, 0($8)
	lbu $10, 0($8)
	
	or $4, $0, $9
	ori $2, $0, 1
	syscall
	
	
	or $4, $0, $10
	ori $2, $0, 1
	syscall

	
	
	
	ori $2, $0, 10
	syscall