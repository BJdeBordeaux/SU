.data
	.align 2
	s : .space 20 # 0x1001 0000
###	ch_ok : asciiz "bien parenthésé\n" # 0x1001 0014
	ch_ok : .asciiz "bien parenthésé\n" # 0x1001 0014
###	ch_nok : asciiz "mal parenthésé\n" # 0x1001 0028
	ch_nok : .asciiz "mal parenthésé\n" # 0x1001 0025
	#两个字符串一起，不align, align只对下一个有效

.text
main:
	# prologue : nv = 1, na = 1
	addiu $29, $29, -8
	
	# $16 : s, 	$17 : ok
	lui $16, 0x1001
	
	# scanf
	###ori $2, 0, 8
	# 中间那个0要写dollar
	ori $2, $0, 8
	ori $4, $16, 0
	ori $5, $0, 20
	syscall
	
	#printf
	ori $4, $16, 0
	###ori $2, 0, 4
	ori $2, $0, 4
	syscall
	
	# ok = bon_parenthesage(s)
	ori $4, $16, 0
	jal bon_parentesage
	ori $17, $2, 0
ok1:
	###bne $17, $0, no_ok
	bne $17, $0, no_ok1
	# printf
	###ori $4, $16, 14 写首页地址要用hex，相对地址才dec

	ori $4, $16, 0x14
	ori $2, $0, 4
	syscall
	###j fin_ok 复制粘贴要改标签：对接下来的每个东西加号码
	j fin_ok1

no_ok1:
	# printf
	###ori $4, $16, 28 
	ori $4, $16, 0x25
	ori $2, $0, 4
	syscall	

fin_ok1:

	# ok = bon_parenthesage_rec(s,0)
	ori $4, $16, 0
	ori $5, $0, 0
	jal bon_parentesage_rec
	ori $17, $2, 0
ok2:
	###bne $17, $0, no_ok
	bne $17, $0, no_ok2
	# printf
	ori $4, $16, 0x14
	ori $2, $0, 4
	syscall
	j fin_ok2
###no_o2:
no_ok2:
	# printf
	ori $4, $16, 0x25
	ori $2, $0, 4
	syscall	

###fin_ok2 地址后面加：，要变成斜体才可以
fin_ok2:
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
	###blez $16, fin_while 若判断内直接return, 不用取否，跳到fin
	# 若判断内处理再return， （return d+1），那么先+1再跳到return
	# 若判断内还有下面，则取否，跳到下面
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
	
bon_parentesage_rec:
	# prologue nr = 1+2, nv = 2, na = 2
	addiu $29, $29, -28
	sw $31, 24($29)
	sw $16, 20($29)
	sw $17, 16($29)
	sw $4, 0($29)
	sw $5, 4($29)
	# d : $16,	ch + index : $17
	addu $17, $4, $5
	# '(' : $9,  ')':$10
	ori $9, $0, 0x28
	ori $10, $0, 0x29
	ori $16, $0, 0
base:
	###lb $8, (0)$17
	lb $8, 0($17)
	beq $8, $0, fin_rec
	
	# d = bon_parentesage_rec(ch, index + 1)
	addiu $5, $5, 1
	jal bon_parentesage_rec
	ori $16, $2, 0
if1_rec:
	###bgtz $16, $0, fin_rec
	bgtz $16, fin_rec
if2_rec:
	### recharger $8 après appel，或曰，应该用dollar18存lb 17出来的
	lb $8, 0($17)###
	bne $8, $10, if3_rec
	addiu $16, $16, -1
	j fin_rec
if3_rec:	
	###bne $16, fin_rec
	bne $8, $9, fin_rec
	addiu $16, $16, 1
	j fin_rec
	
fin_rec:
	ori $2, $16, 0
	# épilogue
	lw $31, 24($29)
	lw $16, 20($29)
	lw $17, 16($29)
	addiu $29, $29, 28
	jr $31