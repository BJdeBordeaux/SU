.data
	ch : .asciiz "153"

.text
main:
	lui $8, 0x1001 # ch
	ori $10, $0, 0 # cpt
	

loop:
	#élaboration de condition (str+i)* != '\0'
	lb $9, 0($8)
	beq $9, $0, fin
	#cpt++, i++
	addiu $10, $10, 1
	addiu $8, $8, 1
	j loop

fin:
	ori $2, $0, 1
	ori $4, $10, 0
	syscall 
	
	ori $2, $0, 10
	syscall 