.data
	.align 2
	s : .space 20 # 0x1001 0000

	### ch_ok : asciiz "bien parenthésé\n" # 0x1001 0014
	ch_ok : .asciiz "bien parenthésé\n" # 0x1001 0014
	
	### ch_nok : asciiz "bien parenthésé\n" # 0x1001 0014
	ch_nok : .asciiz "mal parenthésé\n" # 0x1001 0028

.text
main:
	# prologue : nv = 1, na = 1
	addiu $29, $29, -8
	# $16 : s, 	$17 : ok
	lui $16, 0x1001
	# scanf
	### ori $2, 0, 8
	ori $2, $0, 8
	ori $4, $16, 0
	ori $5, $0, 20
	syscall
	
	#printf
	ori $4, $16, 0
	### ori $2, 0, 4
	ori $2, $0, 4
	syscall
	
	# ok = bon_parenthesage(s)
	ori $4, $16, 0
	jal bon_parentesage
	ori $17, $2, 0
ok:
	bne $17, $0, no_ok
	# printf
	###ori $4, $16, 14
	ori $4, $16, 0x14
	ori $2, $0, 4
	syscall
	j fin_ok
no_ok:
	# printf
	###ori $4, $16, 28
	ori $4, $16, 0x25
	ori $2, $0, 4
	syscall	
fin_ok:
	# épilogue
	addiu $29, $29, 8
	# terminaison
	ori $2, $0, 10
	syscall


bon_parentesage:
	# prologue nr = 1+2, nv = 2, na = 0
	addiu $29, $29, -20
	sw $31, 16($29)
	sw $16, 12($29)
	sw $17, 8($29)
	# d : $16,	ch + i : $17
	### init
	addiu $16, $0, 0 ###
	addu $17, $4, $0
	# '(' : $9,  ')':$10
	ori $9, $0, 0x28
	ori $10, $0, 0x29
while:
	# condition
	###lb $8, (0)$17
	lb $8, 0($17)
	beq $8, $0, fin_while
if1:
	bne $8, $9, if2
	addiu $16, $16, 1
if2:
	bne $8, $10, if3
	addiu $16, $16, -1
if3:	
	###blez $16, fin_while
	bltz $16, fin_while 
	addiu $17, $17, 1
	j while
	
fin_while:
	ori $2, $16, 0
	# épilogue
	lw $16, 12($29)
	lw $17, 8($29)
	lw $31, 16($29)
	addiu $29, $29, 20
	jr $31
