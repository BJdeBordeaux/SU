.data
	ch: .asciiz "coucou"
	.align 0
	tem1 : .space 1
	tem2 : .space 1
	
.text
	lui $8 0x1001
	
	or $4, $0, $8
	ori $2, $0, 4
	syscall

	or $9, $0, $8
	ori $9, $9, 7
	or $10, $9, 1
	lbu $9, 0($8)  #$9 : c
	lbu $10, 1($8) # $10 : o
	sb $10, 0($8) 
	sb $9, 1($8) 

	# vérification
	or $4, $0, $8
	ori $2, $0, 4
	syscall
		
	ori $2, $0, 10
	syscall