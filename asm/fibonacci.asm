mov r0,8									
mov r1,1										
mov r2,1										
mov r3,2										
.loop:
	mov r4,r2									
	add r2,r2,r1							
	mov r1,r4									
	add r3,r3,1								
	cmp r0,r3									
	bgt .loop					
