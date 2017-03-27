.main:
	mov r0,1
	cmp r0,0
	bgt .loop1
	b .loop3

.loop1:
	b .loop2

.loop2:
	add r0,r0,4
	b .loop3

.loop3:
	add r0,r0,r1
	mov r0,7
	b .loop4

.loop4:
	cmp r0,0
	bgt .loop6
	b .loop5

.loop5:
	mov r0,5
	b .loop6

.loop6:
	mov r0,10


	
