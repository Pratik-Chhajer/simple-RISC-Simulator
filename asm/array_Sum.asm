mov r0,5										
mov r1,0										
.loop:
	mul r2,r1,4									
	add r2,r2,0x100							
	st r1,[r2]									
	add r1,r1,1									
	cmp r0,r1 									
	bgt .loop									

mov r1,0										
mov r3,0										
.loop1:		
	mul r2,r1,4									
	add r2,r2,0x100									
	ld r4,0[r2]									
	add r1,r1,1							
	add r3,r3,r4	 								
	cmp r0,r1 									
	bgt .loop1							

