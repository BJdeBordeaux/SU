.data
	one : .byte 0x61
	two : .half 0x14
	three : .word 0xAABBCCDD
	four : .asciiz "("
	five : .half 0x62
	
.text
	lui $8, 0x1001
	lb $9, 4($8)
	
	ori $2, $0, 1
	ori $4, $9, 0
	syscall
	
	ori $2, $0, 10
	syscall
