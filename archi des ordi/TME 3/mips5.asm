
.data

.text

# Operations logiques
ori $8, $0, 0x00FF # $8 =
ori $9, $0, 0xFFF0 # $9 =
and $10, $9, $8    # $10 =
xor $11, $9, $8    # $11 =
xor $11, $11, $11  # $11 =

# Decalages
ori $9, $0, 25
sll $10, $9, 1     # $10 =
sll $11, $9, 2     # $11 =
sll $12, $9, 3     # $12 =
srl $10, $9, 1     # $10 =
srl $10, $9, 2     # $10 =
srl $10, $9, 3     # $10 =
addi $9, $0, -25
srl  $10, $9, 1    # $10 =
srl  $11, $9, 2    # $11 =
sra  $12, $9, 1    # $12 =
sra  $13, $9, 2    # $13 =
sra  $14, $9, 3    # $14 =

# Comparaisonsori $9, $0, 2
ori $8, $0, 4
slt $11, $8, $9    # $11 =
slt $12, $9, $8    # $12 =
ori $2, $0, 10

syscall