.CONST
filterCoefficients REAL4 -0.0000, 0.0003, 0.0008, 0.0011, 0.0008, 0.0002, -0.0003, -0.0002
                    REAL4 0.0006, 0.0015, 0.0015, 0.0004, -0.0011, -0.0018, -0.0008, 0.0011
                    REAL4 0.0021, 0.0007, -0.0027, -0.0055, -0.0053, -0.0020, 0.0012, 0.0007
                    REAL4 -0.0046, -0.0112, -0.0138, -0.0100, -0.0029, 0.0002, -0.0053, -0.0169
                    REAL4 -0.0258, -0.0240, -0.0121, -0.0006, -0.0017, -0.0181, -0.0385, -0.0452
                    REAL4 -0.0294, -0.0016, 0.0136, -0.0037, -0.0483, -0.0873, -0.0786, -0.0022
                    REAL4 0.1208, 0.2344, 0.2805, 0.2344, 0.1208, -0.0022, -0.0786, -0.0873
                    REAL4 -0.0483, -0.0037, 0.0136, -0.0016, -0.0294, -0.0452, -0.0385, -0.0181
                    REAL4 -0.0017, -0.0006, -0.0121, -0.0240, -0.0258, -0.0169
.CODE
ModifyBitsAsm PROC

    ;rcx = chunkPointer
    ;rdx = numElements

    push rbx ;zapisanie wartosci rejestrow
    push rdi
    push rsi
    xor rsi, rsi ;wyzerowanie licznika glownej petli
outer_loop:
    cmp rsi, rdx
    jae end_outer_loop
    xorps xmm0, xmm0 
    xor rdi, rdi
inner_loop:
    cmp rdi, 61 ;61=liczba el. filterCoefficients
    jae end_inner_loop
    mov rbx, rsi
    add rbx, rdi ;nastepny element
    cmp rbx, rdx
    jae skip_add
    movss xmm1, DWORD PTR [rcx + rbx * 4] ;ladowanie danych do xmm1
    lea rax, filterCoefficients ;ladowanie adresu tablicy ze wspolczynnikami
    movss xmm2, DWORD PTR [rax + rdi * 4];ladowanie wartosci wsp. do xmm2
    mulss xmm1, xmm2 ;mnozenie
    addss xmm0, xmm1 ;zaladowanie wyniku do xmm0
skip_add:
    inc rdi
    jmp inner_loop
end_inner_loop:
    movss DWORD PTR [rcx + rsi * 4], xmm0 ;zapisanie danych
    inc rsi
    jmp outer_loop
end_outer_loop:
    pop rsi 
    pop rdi
    pop rbx
    ret
ModifyBitsAsm ENDP
END