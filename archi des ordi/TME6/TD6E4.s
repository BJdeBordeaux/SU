.data
	.align 2
	ch2 : .space 20
	N : .word 7
	ch1 : .asciiz "Hello" #0x1001 0018
	
.text
main :
	# prologue
	addiu $29, $29, -4
	#OPTIMISATION $8 : ch2		$9 : i,		$10 ; N		$12 ; ch1
	#ini	#xxxxxxxxxxxxx一个一个单独affecter, 不可用别人的
	lui $8, 0x1001
	ori $12, $8, 0x18
	ori $9, $0, 0
	lw $10, 20($8)
	#corps
for:
	#cond
	slt $11, $9, $10 # si i < N, $11 = 1
	beq $11, $0, fin_for
	#ch2[i] = ch1[i]
	addu $13, $12, $9
	lbu $14, 0($13)
	addu $13, $8, $9
	sb $14, 0($13)
	#fin
	addiu $9, $9, 1
	j for
fin_for:
	#ch2[i] = '\0'
	addu $13, $9, $8
	sb $0, 0($13)
	#affichage chaine
	ori $4, $8, 0
	ori $5, $0, 20   #xxxxxxxxxxxxx
	ori $2, $0, 4
	syscall 
	#épilogue
	addiu $29, $29, 4     
	#terminaison
	ori $2, $0, 10
	syscall
