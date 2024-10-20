.CODE
MyProc1 proc		
add 	rcx, rdx
mov 	rax, rcx
jnc ET1
ror	rcx,1
mul 	rcx
ret
ET1:	
neg 	rax
ret
MyProc1 endp

END 
