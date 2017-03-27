@General initializations

mov r10, 0	@ r10 will store the total number of test cases that will be called
mov r11, 0	@ R11 will store the total passed cases
mov r12, 0	@ r12 will hold count of failed test cases

@--------------------------------------------------------------------------------------------------
.Test1:
@Test case for Register Transfer instruction(tested to function correctly)
@--------------------------------------------------------------------------------------------------

mov r10, 1	@ increasing count of test case Test 1
mov r1, 10
mov r2, r1
cmp r1, r2
beq .pass1
add r12, r12, 1 @ increase count of failed cases
b .Test2

.pass1:
add r11, r11, 1  @ increase count of passed cases
b .Test2

@--------------------------------------------------------------------------------------------------
.Test2:
@Test case for Arithmetic instruction
@--------------------------------------------------------------------------------------------------


@-------------ADD instruction -------------
.Test21a:
add r10, r10, 1 @ increasing count of test case Test 2 
mov r1, 10 
mov r2, 10
add r3, r1, r2	@ adding resiter operands
cmp r3, 20
beq .pass2
add r12, r12, 1 @ increase count of failed cases
b .Test21b

.pass2:
add r11, r11, 1  @ increase count of passed cases
b .Test21b


.Test21b:
add r10, r10, 1 @ increasing count of test case Test 3
mov r4, 10 
add r3, r4, 10	@ adding immediate operands
cmp r3, 20
beq .pass3
add r12, r12, 1 @ increase count of failed cases
b .Test22

.pass3:
add r11, r11, 1 @ increase count of passed cases
b .Test22

.Test22:
@-------------SUB instruction -------------
.Test22a:
add r10, r10, 1 @ increasing count of test case Test 4 
mov r1, 10 
mov r2, 10
sub r3, r1, r2	@ adding resiter operands
cmp r3, 0
beq .pass4
add r12, r12, 1 @ increase count of failed cases
b .Test22b

.pass4:
add r11, r11, 1  @ increase count of passed cases
b .Test22b

.Test22b:
add r10, r10, 1 @ increasing count of test case Test 5
mov r4, 10 
sub r3, r4, 10	@ adding immediate operands
cmp r3, 0
beq .pass5
add r12, r12, 1 @ increase count of failed cases
b .Test23

.pass5:
add r11, r11, 1 @ increase count of passed cases
b .Test23

.Test23:
@-------------MUL instruction -------------
.Test23a:
add r10, r10, 1 @ increasing count of test case Test 6 
mov r1, 10 
mov r2, 10
mul r3, r1, r2	@ adding resiter operands
cmp r3, 100
beq .pass6
add r12, r12, 1 @ increase count of failed cases
b .Test23b

.pass6:
add r11, r11, 1  @ increase count of passed cases
b .Test23b

.Test23b:
add r10, r10, 1 @ increasing count of test case Test 7
mov r4, 10 
mul r3, r4, 10	@ adding immediate operands
cmp r3, 100
beq .pass7
add r12, r12, 1 @ increase count of failed cases
b .Test24

.pass7:
add r11, r11, 1 @ increase count of passed cases
b .Test24

.Test24:
@-------------DIV instruction -------------
.Test24a:
add r10, r10, 1 @ increasing count of test case Test 8 
mov r1, 10 
mov r2, 20
div r3, r2, r1	@ adding resiter operands
cmp r3, 2
beq .pass8
add r12, r12, 1 @ increase count of failed cases
b .Test24b

.pass8:
add r11, r11, 1  @ increase count of passed cases
b .Test24b

.Test24b:
add r10, r10, 1 @ increasing count of test case Test 9
mov r4, 10 
div r3, r4, 10	@ adding immediate operands
cmp r3, 1
beq .pass9
add r12, r12, 1 @ increase count of failed cases
b .Test25

.pass9:
add r11, r11, 1 @ increase count of passed cases
b .Test25

.Test25:
@-------------MOD instruction -------------
.Test25a:
add r10, r10, 1 @ increasing count of test case Test 10 
mov r1, 10 
mov r2, 20
mod r3, r2, r1	@ adding resiter operands
cmp r3, 0
beq .pass10
add r12, r12, 1 @ increase count of failed cases
b .Test25b

.pass10:
add r11, r11, 1  @ increase count of passed cases
b .Test25b

.Test25b:
add r10, r10, 1 @ increasing count of test case Test 11
mov r4, 10 
mod r3, r4, 8	@ adding immediate operands
cmp r3, 2
beq .pass11
add r12, r12, 1 @ increase count of failed cases
b .Test3

.pass11:
add r11, r11, 1 @ increase count of passed cases
b .Test3

@note: CMP instructions are already taken care off in each of the test cases so no explicit test case made

@-----------------------------------------------------------------------------------------------------
.Test3:
@Test case for Logical instruction
@-----------------------------------------------------------------------------------------------------

.Test31:
@-------------AND instruction -------------
.Test31a:
add r10, r10, 1 @ increasing count of test case Test 12 
mov r1, 0x0787 
mov r2, 0x0787
and r3, r2, r1	@ adding resiter operands
cmp r3, 0x0787
beq .pass12
add r12, r12, 1 @ increase count of failed cases
b .Test31b

.pass12:
add r11, r11, 1  @ increase count of passed cases
b .Test31b


.Test31b:
add r10, r10, 1 @ increasing count of test case Test 13 
mov r1, 0x0787 
and r3, r2, 0x0787 @ adding immediate operands
cmp r3, 0x0787
beq .pass13
add r12, r12, 1 @ increase count of failed cases
b .Test32

.pass13:
add r11, r11, 1  @ increase count of passed cases
b .Test32


.Test32:
@-------------OR instruction -------------
.Test32a:
add r10, r10, 1 @ increasing count of test case Test 14 
mov r1, 0x0787 
mov r2, 0x0000
or r3, r2, r1	@ adding resiter operands
cmp r3, 0x0787
beq .pass14
add r12, r12, 1 @ increase count of failed cases
b .Test32b

.pass14:
add r11, r11, 1  @ increase count of passed cases
b .Test32b


.Test32b:
add r10, r10, 1 @ increasing count of test case Test 15 
mov r1, 0x0000 
or r3, r2, 0x0787 @ adding immediate operands
cmp r3, 0x0787
beq .pass15
add r12, r12, 1 @ increase count of failed cases
b .Test33

.pass15:
add r11, r11, 1  @ increase count of passed cases
b .Test33


.Test33:
@-------------NOT instruction -------------
.Test33a:
add r10, r10, 1 @ increasing count of test case Test 16 
mov r1, 4096
not r2, r1	@ adding resiter operands
cmp r2, -4096
beq .pass16
add r12, r12, 1 @ increase count of failed cases
b .Test33b

.pass16:
add r11, r11, 1  @ increase count of passed cases
b .Test33b


.Test33b:
add r10, r10, 1 @ increasing count of test case Test 17 
not r2, 4096  @ adding immediate operands
cmp r2, -4096
beq .pass17
add r12, r12, 1 @ increase count of failed cases
b .Test4

.pass17:
add r11, r11, 1  @ increase count of passed cases
b .Test4


@-----------------------------------------------------------------------------------------------------
.Test4:
@Test case for Shift instruction
@-----------------------------------------------------------------------------------------------------

.Test41:
@-------------LSL instruction -------------
.Test41a:
add r10, r10, 1 @ increasing count of test case Test 18 
mov r1, 0x0001
mov r2, 4 
lsl r3, r1, r2	@ adding resiter operands
cmp r3, 0x0010
beq .pass18
add r12, r12, 1 @ increase count of failed cases
b .Test33b

.pass18:
add r11, r11, 1  @ increase count of passed cases
b .Test41b


.Test41b:
add r10, r10, 1 @ increasing count of test case Test 19 
mov r1, 0x0001
lsl r3, r1, 4	@ adding immediate operands
cmp r3, 0x0010
beq .pass19
add r12, r12, 1 @ increase count of failed cases
b .Test42

.pass19:
add r11, r11, 1  @ increase count of passed cases
b .Test42


.Test42:
@-------------LSR instruction -------------
.Test42a:
add r10, r10, 1 @ increasing count of test case Test 20 
mov r1, 0x0008
mov r2, 4 
lsr r3, r1, r2	@ adding resiter operands
cmp r3, 0x0000
beq .pass20
add r12, r12, 1 @ increase count of failed cases
b .Test42b

.pass20:
add r11, r11, 1  @ increase count of passed cases
b .Test42b


.Test42b:
add r10, r10, 1 @ increasing count of test case Test 21 
mov r1, 0x0008
lsr r3, r1, 4	@ adding immediate operands
cmp r3, 0x0000
beq .pass21
add r12, r12, 1 @ increase count of failed cases
b .Test43

.pass21:
add r11, r11, 1  @ increase count of passed cases
b .Test43


.Test43:
@-------------ASR instruction -------------
.Test43a:
add r10, r10, 1 @ increasing count of test case Test 22 
mov r1, -256
mov r2, 4 
asr r3, r1, r2	@ adding resiter operands
cmp r3, -16
beq .pass22
add r12, r12, 1 @ increase count of failed cases
b .Test43b

.pass22:
add r11, r11, 1  @ increase count of passed cases
b .Test43b


.Test43b:
add r10, r10, 1 @ increasing count of test case Test 23 
mov r1, -256
asr r3, r1, 4	@ adding immediate operands
cmp r3, -16
beq .pass23
add r12, r12, 1 @ increase count of failed cases
b .Test5

.pass23:
add r11, r11, 1  @ increase count of passed cases
b .Test5



@-----------------------------------------------------------------------------------------------------
.Test5:
@Test case for Data transfer instruction
@-----------------------------------------------------------------------------------------------------

@-------------LOAD - STORE instructions -------------
.Test5a:
@simple store value and load it wihout offset
add r10, r10, 1 @ increasing count of test case Test 24
mov r1, 100
mov r2, 1000
st r1, [r2]
ld r3, [r2]
cmp r1, r3
beq .pass24
add r12, r12, 1 @ increase count of failed cases
b .Test5b

.pass24:
add r11, r11, 1  @ increase count of passed cases
b .Test5b



.Test5b:
@simple store value and load it wih +ve offset
add r10, r10, 1 @ increasing count of test case Test 25
mov r1, 100
mov r2, 1000
st r1, 10[r2]
ld r3, 10[r2]
cmp r1, r3
beq .pass25
add r12, r12, 1 @ increase count of failed cases
b .Test5c

.pass25:
add r11, r11, 1  @ increase count of passed cases
b .Test5c



.Test5c:
@simple store value and load it wih -ve offset
add r10, r10, 1 @ increasing count of test case Test 26
mov r1, 100
mov r2, 1000
st r1, -10[r2]
ld r3, -10[r2]
cmp r1, r3
beq .pass26
add r12, r12, 1 @ increase count of failed cases
b .Test5d

.pass26:
add r11, r11, 1  @ increase count of passed cases
b .Test5d


.Test5d:




