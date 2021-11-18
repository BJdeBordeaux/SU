.data 

	# NOTE !!! : $8 should be $16, with consequential modifications
	# but I do not want to rewrite.
	# see E2Q3.s

.text 
main:
	#prologue nr = 0, nv = 9, na = 1
	addiu $29, $29, -40
	ori $15, $0, 0 # i
	# $24 : ch1 : 8($29)
	# $25 : ch2 : 24($29)
	#lecture ch1
	ori $4, $29, 8
	ori $5, $0, 16
	ori $2, $0, 8
	syscall
	#lecture ch2
	ori $4, $29, 8
	ori $5, $0, 16
	ori $2, $0, 8
	syscall
	
	#affichage ch1
	ori $4, $29, 8
	ori $2, $0, 4
	syscall
	#to_maj
	ori $4, $29, 8
	jal min_to_maj_chaine
	#affichage ch1
	ori $4, $29, 8
	ori $2, $0, 4
	syscall	
	
	#affichage ch2
	ori $4, $29, 24
	ori $2, $0, 4
	syscall
	#to_maj
	ori $4, $29, 24
	jal min_to_maj_chaine
	#affichage ch1
	ori $4, $29, 24
	ori $2, $0, 4
	syscall

	
	#épilogue
	addiu $29, $29, 8
	#terminaison
	ori $2,$0, 10
	syscall

min_to_maj_chaine:
	#prologue
	addiu $29, $29, -8
	sw $31, 4($29)
	ori $8, $0, 0 # i
while:
	addu $10, $4, $8 #&ch[i]
	lbu $11, 0($10) #ch[i]
	beq $11, $0, end_while
if:
	addiu $12, $11, -0x61
	bltz $12, end_if
	addiu $12, $11, -0x7A
	bgtz $12, end_if 
	addiu $14, $11, -0x20
	sb $14, 0($10)
end_if:
	addiu $8, $8, 1
	j while

end_while:
	#epilogue
	sw $31, 4($29)
	addiu $29, $29, 8
	#return
	jr $31