.data
.globl main
.text

main:
li $a0,1
li $a1,1
li $a2,1
li $a3,1

addi $sp, $sp, -4
li $t0, 1
sw $t0, ($sp)

addi $sp, $sp, -4
li $t0, 1
sw $t0, ($sp)

jal suma
move $t1,$v0


lb $a0,($sp)
addi $sp,$sp,1

li $v0, 1
syscall

move $a0,$v1
li $v0, 1
syscall

move $a0,$t1
li $v0, 1
syscall

li $v0, 10
syscall

suma:
add $v0, $a0, $a1
add $v0, $v0, $a2
add $v0, $v0, $a3

lw $t0, ($sp)
addi $sp, $sp, 4

add $v0,$v0,$t0

lw $t1, ($sp)
addi $sp, $sp, 4

add $v0,$v0,$t1

addi $sp,$sp,-4
sw $v0,($sp)

addi $sp, $sp, -4     
sw $ra, ($sp)



addi $sp, $sp, -4
sw $t1, ($sp)

addi $sp, $sp, -4
sw $t0, ($sp)

jal multiplicacion
lw $ra, ($sp)       
addi $sp, $sp, 4


jr $ra

multiplicacion:
mul $v0,$a0,$a1
mul $v0,$v0,$a2
mul $v0,$v0,$a3

lw $t0, ($sp)
addi $sp, $sp, 4
mul $v0,$v0,$t0

lw $t1, ($sp)
addi $sp, $sp, 4

mul $v0,$v0,$t1



addi $sp, $sp, -4      
sw $v0, ($sp)
addi $sp, $sp, -4     
sw $ra, ($sp)

move $a0,$a2
move $a1,$t1

jal resta


lw $ra, ($sp)       
addi $sp, $sp, 4

lw $v1, ($sp)
addi $sp, $sp,4

jr $ra

resta:

sub $v0,$a0,$a1

jr $ra