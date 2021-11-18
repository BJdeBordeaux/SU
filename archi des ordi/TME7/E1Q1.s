.data
ch : .asciiz "l exemple d'exemple\n"

.text
main :
lui $9, 0x1001 #ch
ori $8, $0, 0 #i

ori $4, $9, 0
ori $2,$0, 4
syscall

while:
addu $10, $9, $8 #&ch[i]
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
ori $4, $9, 0
ori $2,$0, 4
syscall

ori $2,$0, 10
syscall

