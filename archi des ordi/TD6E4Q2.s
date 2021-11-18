.data 
	N : .word 1
	
.text
main :
	# prologue
	addiu $29, $29, -32
	#OPTIMISATION $8 : i		$9 : ch2		$10 ; ch1		$11: N
	#ini
	ori $8, $0, 0
	ori $9, $29, 4
	ori $10, $29, 24
	ori $11, $0, 0x48 # 'H'
	sb $11, 0($10)
	ori $11, $0, 0x65 # 'e'
	sb $11, 1($10)
	ori $11, $0, 0x6C # 'l'
	sb $11, 2($10)
	ori $11, $0, 0x6C # 'l'
	sb $11, 3($10)
	ori $11, $0, 0x6F # 'o'
	sb $11, 4($10)
	#préparation
	lui $12, 0x1001
	lw $11, 0($12)
for:
	#cond
	slt $12, $8, $11 # si i < N, $11 = 1
	beq $12, $0, fin_for
	#ch2[i] = ch1[i]
	addu $12, $10, $8
	lbu $13, 0($12)
	addu $12, $8, $9
	sb $13, 0($12)
	#fin
	addiu $8, $8, 1
	j for
fin_for:
	#affichage chaine
	ori $4, $9, 0
	ori $5, $0, 20
	ori $2, $0, 4
	syscall 
	#épilogue
	addiu $29, $29, 32
	#terminaison
	ori $2, $0, 10
	syscall
