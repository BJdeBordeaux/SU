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
	#printf
	lui $4, 0x1001
	ori $2, $0, 4
	syscall
	lui $9, 0x1001 # ch
while : 
	addu $10, $8,  $9 # ch + i
	lb $11, 0($10)
	beq $11, $0, end_while
	ori $4, $11, 0
	jal min_to_maj_chaine
	sb $2, 0($10)
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
	ori $2,$0, 10
	syscall


min_to_maj_chaine:
	#prologue
	addiu $29, $29, -4
	sw $31, 0($29)
#corps
if:
	addiu $12, $4, -0x61
	bltz $12, else
	addiu $12, $4, -0x7A
	bgtz $12, else
	addiu $14, $4, -0x20
	j end_if
else:
	ori $14, $4, 0
end_if:
	ori $2, $14, 0
	#epilogue
	sw $31, 0($29)
	addiu $29, $29, 4
	#return
	jr $31
