.data
ch: .asciiz "123"
a: .word 0xBA439821

.text
lui $8, 0x1001
lb $9, 0($8)
lbu $10, 0($8)
ori $8, $8, 4
lb $11, 0($8)
lbu $12, 0($8)

ori $2, $0, 10
syscall
