.data
	# NOTE !!! : $8 should be $16, with consequential modifications
	# but I do not want to rewrite.
	# see E2Q3.s

.text

main:	# NOTE !!! : $8 should be $16, with consequential modifications
	# but I do not want to rewrite.
	# see E2Q3.s
	#prologue	nr = 0, nv = 5, na = 1
	addiu $29, $29, -24
	#corps
	ori $8, $0, 0 # i
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
	ori $8, $0, 0 # i
	addiu $9, $29, 8
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
	ori $4, $29, 8
	addiu $2, $0, 4
	syscall
	#épilogue
	addiu $29, $29, 24
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
	addiu $2, $4, -0x20
	j end_if
else:
	ori $2, $4, 0
end_if:
	#epilogue
	sw $31, 0($29)
	addiu $29, $29, 4
	#return
	jr $31