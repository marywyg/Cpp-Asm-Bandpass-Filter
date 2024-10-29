.DATA

negative_one QWORD -1.0

.CODE
ModifyBitsAsm PROC
    mov rdx, 64
loop_start:
    movsd xmm0, QWORD PTR [rcx]   
    mulsd xmm0, QWORD PTR [negative_one] 
    movsd QWORD PTR [rcx], xmm0    
    add rcx, 8             
    dec rdx                
    jnz loop_start
    ret
ModifyBitsAsm ENDP

END

