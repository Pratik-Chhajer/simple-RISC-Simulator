b .main

.foo:	
	add r0,r1,1
	ret

.main:
	mov r0,5
	call .foo
	call .foo
	call .foo
	call .foo
 
