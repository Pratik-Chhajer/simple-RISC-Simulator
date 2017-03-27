.main:
	mov r0,6
	mov r1,3
	mov r2,1
	mov r3,1
.loop:
	mul r3,r3,r0
	add r2,r2,1
	cmp r1,r2
	bgt .loop
	beq .loop
	

