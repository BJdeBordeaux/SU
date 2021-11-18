# NOTE !!! : $8 and $9 should be $16 and $17 respectively, with consequential modifications
	# but I do not want to rewrite.
	# see E2Q3.s
.data
ch1 : .asciiz "l exemple d'exemple\n"

.text

main:
	#prologue
	addiu $29, $29, -8
	#corps
	ori $8, $0, 0 # i
	lui $9, 0x1001 # ch
	#printf
	lui $4, 0x1001
	ori $2, $0, 4
	syscall
while : 
	addu $10, $8,  $9 # ch + i
	lbu $11, 0($10)
	beq $11, $0, end_while
	ori $4, $10, 0
	jal min_to_maj_chaine
	addiu $8, $8, 1
	j while
end_while:
	#printf
	ori $4, $0, 0
	lui $4, 0x1001
	addiu $2, $0, 4
	syscall
	#épilogue
	addiu $29, $29, 8
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
