.CONST
filterCoefficients REAL4 -0.0059, 0.0215, 0.1756, 0.3827, 0.3827, 0.1756, 0.0215,-0.0059

.CODE
    ; rcx = chunkPointer
    ; rdx = numElements

ModifyBitsAsm PROC
    push rbx
    push rdi
    xor rsi, rsi               ; i = 0

    lea rbx, filterCoefficients
    vmovups ymm1, real4 ptr [rbx] ; Load filter coefficients into ymm1

outer_loop:
    cmp rsi, rdx
    jae end_outer_loop         
    vmovups ymm2, real4 ptr [rcx + rsi * 4] ; Load 8 audio samples
    vmulps ymm2, ymm2, ymm1                 ; Multiply samples with coefficients

    ; Clear ymm3 before horizontal addition
    vxorps ymm3, ymm3, ymm3
    
    ; Sum elements in ymm2
    ;vperm2f128 ymm3, ymm2, ymm2, 1    ; Swap upper and lower halves
    ;vaddps ymm2, ymm2, ymm3            ; Add upper half to lower half
    ;vpermilps ymm3, ymm2, 78          ; Swap positions 2,3 with 1,4
    ;vaddps ymm2, ymm2, ymm3            ; Add adjacent elements
    ;vpermilps ymm3, ymm2, 177         ; Swap positions 1,4 with 2,3
    ;vaddps ymm2, ymm2, ymm3            ; Add final pairs
    vextractf128 xmm3, ymm2, 1 ; Wyodrêbnij górn¹ po³owê ymm2 do xmm3
    vaddps xmm2, xmm2, xmm3    ; Dodaj górn¹ po³owê do dolnej po³owy
    vhaddps xmm2, xmm2, xmm2   ; Horyzontalne dodawanie par elementów
    vhaddps xmm2, xmm2, xmm2   ; Ponowne horyzontalne dodawanie par elementów

    ; Store result
    vmovss real4 ptr [rcx + rsi * 4], xmm2
    vxorps ymm2, ymm2, ymm2
    add rsi, 1
    jmp outer_loop

end_outer_loop:
    ; Clear YMM registers before returning
    vzeroupper
    pop rdi
    pop rbx
    ret
ModifyBitsAsm ENDP
END
