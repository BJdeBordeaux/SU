.data
	.align 2
	chaine : .space 11
	
.text
main :
	# prologue
	addiu $29, $29, -16
	#OPTIMISATION $8 : i,	$9 : nb, 	$10 : r,	 $11 : nbzero, 		$12 : 10
	#$13 : ch

	#lire un entier
	ori $2, $0, 5
	syscall
	ori $9, $2, 0 # récupération
	#ini
	lui $13, 0x1001
	sb $0, 10($13)
	ori $8, $0, 9
	ori $12, $0, 10
	#corps
for:
	bltz $8, fin_for
	divu $9, $12
	mfhi $10 #reste
	mflo $9	#quotien
	addiu $14, $10, 0x30
	addu $15, $13, $8 # ch+i
	sb $14, 0($15) 
	addiu $8, $8, -1
	j for
fin_for:
	#affichage chaine
	ori $4, $13, 0
	ori $5, $0, 11
	ori $2, $0,  4
	syscall 
	#compter le nb de '0' dans ch
	ori $8, $0, 0
	ori $11, $0, 0
	# $12 : 9, 
while:	
	ori $12, $0, 9,
	slt $14, $8, $12 # $14 = 1 si i<9
	beq $14, $0, fin_while
	addu $14, $13, $8
	lbu $15, 0($14)
	addiu $15, $15, -0x30 
	bne $15, $0, fin_while #$15 - 0x30 == 0
	addiu $11, $11, 1
	addiu $8, $8, 1
	j while
fin_while:
	#affichage
	ori $4, $11, 0
	ori $2, $0,  1
	syscall 
	ori $8, $0, 0
	#$12 : 11		$8 : i,	$9 : nb, 	$10 : r,	 $11 : nbzero, 		$12 : 10
	ori $12, $0, 11	
for_recopie:
	#élab
	subu $14, $12, $11 # 
	slt $15, $8, $14 # si i < 11 - nbzero, $15 == 1
	beq $15, $0, fin_for_recopie
	#corps
	addu $14, $8, $11
	addu $15, $13, $14
	lbu $14, 0($15)
	addu $15, $13, $8
	sb $14, 0($15)
	addiu $8, $8, 1
	j for_recopie
fin_for_recopie:
	#affichage chaine
	ori $4, $13, 0
	ori $5, $0, 11
	ori $2, $0,  4
	syscall 
	#épilogue
	addiu $29, $29, 16
	#terminaison
	ori $2, $0, 10
	syscall