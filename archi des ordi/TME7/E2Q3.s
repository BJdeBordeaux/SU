.data

.text

main:
	#prologue	nr = 1, nv = 5, na = 1
	addiu $29, $29, -24
	sw $16, 20($29)
	#corps
	ori $16, $0, 0 # i
	#ch : 8($29)
	#lecture ch1
	addiu $4, $29, 8
	ori $5, $0, 16
	ori $2, $0, 8
	syscall
	#printf
	addiu $4, $29, 8
	ori $2, $0, 4
	syscall
while : 
	addiu $9, $29, 8 # ch
	addu $10, $16, $9 # ch + i
	lbu $11, 0($10)
	beq $11, $0, end_while
	ori $4, $10, 0
	jal min_to_maj_chaine
	addiu $16, $16, 1
	j while
end_while:
	#printf
	addiu $4, $29, 8
	ori $2, $0, 4
	syscall
	#épilogue
	lw $16, 20($29)
	addiu $29, $29, 24
	#terminaison
	ori $2,$0, 10
	syscall

min_to_maj_chaine:
	#prologue
	addiu $29, $29, -4
	sw $31, 0($29)
#corps
if:
	lbu $13, 0($4)
	addiu $12, $13, -0x61
	bltz $12, end_if
	addiu $12, $13, -0x7A
	bgtz $12, end_if
	addiu $12, $13, -0x20
	sb $12, 0($4) 
end_if:
	#epilogue
	sw $31, 0($29)
	addiu $29, $29, 4
	#return
	jr $31
