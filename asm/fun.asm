.main:
	mov r0,5
	mov r1,2
	call .foo
	mov r2,3
	b .exit

.foo:
	add r0,r0,1
	ret

