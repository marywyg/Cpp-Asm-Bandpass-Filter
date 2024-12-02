.CONST
filterCoefficients REAL4 -0.0000, 0.0003
                      REAL4 0.0008, 0.0011
                      REAL4 0.0008, 0.0002
                      REAL4 -0.0003, -0.0002
                      REAL4 0.0006, 0.0015
                      REAL4 0.0015, 0.0004
                      REAL4 -0.0011, -0.0018
                      REAL4 -0.0008, 0.0011
                      REAL4 0.0021, 0.0007
                      REAL4 -0.0027, -0.0055
                      REAL4 -0.0053, -0.0020
                      REAL4 0.0012, 0.0007
                      REAL4 -0.0046, -0.0112
                      REAL4 -0.0138, -0.0100
                      REAL4 -0.0029, 0.0002
                      REAL4 -0.0053, -0.0169
                      REAL4 -0.0258, -0.0240
                      REAL4 -0.0121, -0.0006
                      REAL4 -0.0017, -0.0181
                      REAL4 -0.0385, -0.0452
                      REAL4 -0.0294, -0.0016
                      REAL4 0.0136, -0.0037
                      REAL4 -0.0483, -0.0873
                      REAL4 -0.0786, -0.0022
                      REAL4 0.1208, 0.2344
                      REAL4 0.2805, 0.2344
                      REAL4 0.1208, -0.0022
                      REAL4 -0.0786, -0.0873
                      REAL4 -0.0483, -0.0037
                      REAL4 0.0136, -0.0016
                      REAL4 -0.0294, -0.0452
                      REAL4 -0.0385, -0.0181
                      REAL4 -0.0017, -0.0006
                      REAL4 -0.0121, -0.0240
                      REAL4 -0.0258, -0.0169
                      REAL4 -0.0053, 0.0002
                      REAL4 -0.0029, -0.0100
                      REAL4 -0.0138, -0.0112
                      REAL4 -0.0046, 0.0007
                      REAL4 0.0012, -0.0020
                      REAL4 -0.0053, -0.0055
                      REAL4 -0.0027, 0.0007
                      REAL4 0.0021, 0.0011
                      REAL4 -0.0008, -0.0018
                      REAL4 -0.0011, 0.0004
                      REAL4 0.0015, 0.0015
                      REAL4 0.0006, -0.0002
                      REAL4 -0.0003, 0.0002
                      REAL4 0.0008, 0.0011
                      REAL4 0.0008, 0.0003
                      REAL4 -0.0000
.CODE
    ;rcx = chunkPointer
    ;rdx = numElements
ModifyBitsAsm PROC
    push rbx
    push rdi
    push rsi
    xor rsi, rsi
outer_loop:
    cmp rsi, rdx
    jae end_outer_loop
    xorps xmm0, xmm0
    xor rdi, rdi
    lea rbx, filterCoefficients
inner_loop:
    cmp rdi, 99
    jae end_inner_loop
    mov rax, rsi
    add rax, rdi
    cmp rax, rdx
    jae skip_add
    movups xmm1, XMMWORD PTR [rcx + rax * 4]
    movups xmm2, XMMWORD PTR [rbx + rdi * 4]
    mulps xmm1, xmm2
    addps xmm0, xmm1

skip_add:
    add rdi, 1
    jmp inner_loop

end_inner_loop:
    movups XMMWORD PTR [rcx + rsi * 4], xmm0
    add rsi, 1
    jmp outer_loop

end_outer_loop:
    pop rsi
    pop rdi
    pop rbx
    ret
ModifyBitsAsm ENDP
END