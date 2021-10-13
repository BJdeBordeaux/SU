

.data

.text

ori $2, $0, 5
syscall
or $9,$0,$2

ori $2, $0, 5
syscall
or $10,$0,$2


div $9,$10

mflo $11
mfhi  $12

mult $11, $10

mflo $13
addu $13, $13, $12

or $4, $0, $13

ori $2, $0, 1
syscall

ori $2, $0, 10
syscall
