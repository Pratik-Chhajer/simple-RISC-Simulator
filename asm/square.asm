.main:
	mov r0,1
	mov r1,0
	mov r3,5
.loop:
	mul r2,r0,r0
	add r1,r1,r2
	add r0,r0,1
	cmp r3,r0
	bgt .loop
	beq .loop

