.data
ch1 : .asciiz "l exemple d'exemple\n"
ch2 : .asciiz "Hello world!\n"

.text

main:
lui $4, 0x1001
ori $2, $0, 4
syscall

ori $4, $0, 0
lui $4, 0x1001
jal min_to_maj_chaine

ori $4, $0, 0
lui $4, 0x1001
ori $2, $0, 4
syscall

ori $4, $0, 0
lui $4, 0x1001
addiu $4, $4, 21
ori $2, $0, 4
syscall

ori $4, $0, 0
lui $4, 0x1001
addiu $4, $4, 21
jal min_to_maj_chaine

ori $4, $0, 0
lui $4, 0x1001
addiu $4, $4, 21
ori $2, $0, 4
syscall

ori $2,$0, 10
syscall


min_to_maj_chaine:
#prologue
addiu $29, $29, -8
sw $31, 4($29)
ori $8, $0, 0
#while
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
