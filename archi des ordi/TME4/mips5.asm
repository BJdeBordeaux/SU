.data

	tab: .byte 0x31,0x32, 0x33, 0x34, 0x35, 0x36, 0x00
	
.text

	lui $8, 0x1001
	
	or $4, $0, $8

	lb $16, 3($8)
	sub $17,$16,0x30
	or $4, $0, $17
	
	ori $2, $0, 1
	syscall
	
	
	
	ori $2, $0, 10
	syscall
	