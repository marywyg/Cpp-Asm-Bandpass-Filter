.CONST
filterCoefficients REAL4 -0.0059, 0.0215, 0.1756, 0.3827, 0.3827, 0.1756, 0.0215, -0.0059

.CODE
    ; rcx = chunkPointer
    ; rdx = numElements

ModifyBitsAsm PROC
    push rbx
    push rdi
    push rsi
    xor rsi, rsi               ; i = 0

outer_loop:
    cmp rsi, rdx
    jae end_outer_loop         ; if i >= numElements, exit outer loop
    vpxor ymm0, ymm0, ymm0

    ; inner loop index (j)
    xor rdi, rdi

    lea rbx, filterCoefficients 

inner_loop:
    mov r8, rsi                ; r8 = i
    add r8, rdi                ; r8 = i + j
    cmp r8, rdx
    jae end_inner_loop

    vbroadcastss ymm1, real4 ptr [rcx + r8 * 4]
    vmovups ymm2, real4 ptr [rbx + rdi * 4] ; Load filterCoefficients[j] into ymm2
    vmulps ymm1, ymm1, ymm2     ; ymm1 *= ymm2
    vaddps ymm0, ymm0, ymm1     ; ymm0 += ymm1

    ; Increment j (rdi)
    inc rdi
    cmp rdi, 8                 ; Compare j with the number of coefficients
    jb inner_loop

end_inner_loop:
    ; Store the result back into chunkPointer[i]
    vmovss real4 ptr [rcx + rsi * 4], xmm0

    ; Increment i (rsi)
    inc rsi
    jmp outer_loop

end_outer_loop:
    pop rsi
    pop rdi
    pop rbx
    ret
ModifyBitsAsm ENDP
END