

.data

.text

lui $3, 0xAABB
ori $3, $3, 0xCCDD

or $4, $0, $3
ori $2, $0, 34
syscall

sw $4, 0($3)

sb $4, 3($3)
sb $4, 2($3)
sb $4, 1($3)
sb $4, 0($3)

ori $2, $0, 10
syscall

