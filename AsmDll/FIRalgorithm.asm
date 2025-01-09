.CONST
filterCoefficients REAL4 -0.0059, 0.0215, 0.1756, 0.3827, 0.3827, 0.1756, 0.0215,-0.0059

.CODE
    ; rcx = chunkPointer
    ; rdx = numElements
    ; rsi = i (iterator pêtli)
    ; rbx = wskaznik na wspolczynniki filtra

ModifyBitsAsm PROC
    push rbx
    xor rsi, rsi               ; rsi = 0
    lea rbx, filterCoefficients
    vmovups ymm1, real4 ptr [rbx] ; Zaladowanie wspolczynnikow filtra do ymm1

outer_loop:
    cmp rsi, rdx
    jae end_outer_loop
    vmovups ymm2, real4 ptr [rcx + rsi * 4] ; Wczytywanie probki do ymm2 (8 floatow)
    vmulps ymm2, ymm2, ymm1                 ; Mnozenie probek przez wspolczynniki filtra    
    vextractf128 xmm3, ymm2, 1 ; Wyodrêbnienie górnej po³owy ymm2 do xmm3
    vaddps xmm2, xmm2, xmm3    ; Dodawanie górnej po³owy do dolnej po³owy
    vhaddps xmm2, xmm2, xmm2   ; Horyzontalne dodawanie par elementów
    vhaddps xmm2, xmm2, xmm2   ; Ponowne horyzontalne dodawanie par elementów
    vmovss real4 ptr [rcx + rsi * 4], xmm2 ; Zapisanie wyniku do pamieci
    vxorps ymm2, ymm2, ymm2 
    add rsi, 1 ; i++
    jmp outer_loop

end_outer_loop:
    pop rbx
    ret
ModifyBitsAsm ENDP
END