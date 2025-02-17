; Listing generated by Microsoft (R) Optimizing Compiler Version 19.41.34123.0 

include listing.inc

INCLUDELIB OLDNAMES

EXTRN	__security_check_cookie:PROC
PUBLIC	ModifyBitsCpp
PUBLIC	__real@3bc154ca
PUBLIC	__real@3cb020c5
PUBLIC	__real@3e33d07d
PUBLIC	__real@3ec3f141
EXTRN	_fltused:DWORD
;	COMDAT __real@3ec3f141
CONST	SEGMENT
__real@3ec3f141 DD 03ec3f141r			; 0.3827
CONST	ENDS
;	COMDAT __real@3e33d07d
CONST	SEGMENT
__real@3e33d07d DD 03e33d07dr			; 0.1756
CONST	ENDS
;	COMDAT __real@3cb020c5
CONST	SEGMENT
__real@3cb020c5 DD 03cb020c5r			; 0.0215
CONST	ENDS
;	COMDAT __real@3bc154ca
CONST	SEGMENT
__real@3bc154ca DD 03bc154car			; 0.0059
CONST	ENDS
; Function compile flags: /Ogtpy
; File C:\Users\marwy\source\repos\SolBandpass\CppDll\mojadll.cpp
;	COMDAT ModifyBitsCpp
_TEXT	SEGMENT
chunkPointer$ = 8
numElements$ = 16
ModifyBitsCpp PROC					; COMDAT

; 5    : 
; 6    :     float filterCoefficients[] = {
; 7    :      -0.0059f,   0.0215f,    0.1756f,    0.3827f,    0.3827f,    0.1756f,    0.0215f, - 0.0059f
; 8    : 
; 9    :     };
; 10   :     for (size_t i = 0; i < numElements; ++i) {

	test	rdx, rdx
	je	$LN3@ModifyBits
	movss	xmm2, DWORD PTR __real@3bc154ca
	mov	r8d, 2
	movss	xmm3, DWORD PTR __real@3cb020c5
	add	rcx, 8
	movss	xmm4, DWORD PTR __real@3e33d07d
	movss	xmm5, DWORD PTR __real@3ec3f141
$LL4@ModifyBits:

; 11   :         float result = 0.f;
; 12   :         for (size_t j = 0; j < std::size(filterCoefficients); ++j) {
; 13   :             if (i + j < numElements) {

	lea	rax, QWORD PTR [r8-2]
	xorps	xmm1, xmm1
	cmp	rax, rdx
	jae	SHORT $LN15@ModifyBits

; 14   :                 result += chunkPointer[i + j] * filterCoefficients[j];

	movss	xmm0, DWORD PTR [rcx-8]
	mulss	xmm0, xmm2
	subss	xmm1, xmm0
$LN15@ModifyBits:

; 11   :         float result = 0.f;
; 12   :         for (size_t j = 0; j < std::size(filterCoefficients); ++j) {
; 13   :             if (i + j < numElements) {

	lea	rax, QWORD PTR [r8-1]
	cmp	rax, rdx
	jae	SHORT $LN18@ModifyBits

; 14   :                 result += chunkPointer[i + j] * filterCoefficients[j];

	movss	xmm0, DWORD PTR [rcx-4]
	mulss	xmm0, xmm3
	addss	xmm1, xmm0
$LN18@ModifyBits:

; 11   :         float result = 0.f;
; 12   :         for (size_t j = 0; j < std::size(filterCoefficients); ++j) {
; 13   :             if (i + j < numElements) {

	cmp	r8, rdx
	jae	SHORT $LN20@ModifyBits

; 14   :                 result += chunkPointer[i + j] * filterCoefficients[j];

	movss	xmm0, DWORD PTR [rcx]
	mulss	xmm0, xmm4
	addss	xmm1, xmm0
$LN20@ModifyBits:

; 11   :         float result = 0.f;
; 12   :         for (size_t j = 0; j < std::size(filterCoefficients); ++j) {
; 13   :             if (i + j < numElements) {

	lea	r9, QWORD PTR [r8+1]
	cmp	r9, rdx
	jae	SHORT $LN33@ModifyBits

; 14   :                 result += chunkPointer[i + j] * filterCoefficients[j];

	movss	xmm0, DWORD PTR [rcx+4]
	mulss	xmm0, xmm5
	addss	xmm1, xmm0
$LN33@ModifyBits:

; 11   :         float result = 0.f;
; 12   :         for (size_t j = 0; j < std::size(filterCoefficients); ++j) {
; 13   :             if (i + j < numElements) {

	lea	rax, QWORD PTR [r8+2]
	cmp	rax, rdx
	jae	SHORT $LN24@ModifyBits

; 14   :                 result += chunkPointer[i + j] * filterCoefficients[j];

	movss	xmm0, DWORD PTR [rcx+8]
	mulss	xmm0, xmm5
	addss	xmm1, xmm0
$LN24@ModifyBits:

; 11   :         float result = 0.f;
; 12   :         for (size_t j = 0; j < std::size(filterCoefficients); ++j) {
; 13   :             if (i + j < numElements) {

	lea	rax, QWORD PTR [r8+3]
	cmp	rax, rdx
	jae	SHORT $LN26@ModifyBits

; 14   :                 result += chunkPointer[i + j] * filterCoefficients[j];

	movss	xmm0, DWORD PTR [rcx+12]
	mulss	xmm0, xmm4
	addss	xmm1, xmm0
$LN26@ModifyBits:

; 11   :         float result = 0.f;
; 12   :         for (size_t j = 0; j < std::size(filterCoefficients); ++j) {
; 13   :             if (i + j < numElements) {

	lea	rax, QWORD PTR [r8+4]
	cmp	rax, rdx
	jae	SHORT $LN28@ModifyBits

; 14   :                 result += chunkPointer[i + j] * filterCoefficients[j];

	movss	xmm0, DWORD PTR [rcx+16]
	mulss	xmm0, xmm3
	addss	xmm1, xmm0
$LN28@ModifyBits:

; 11   :         float result = 0.f;
; 12   :         for (size_t j = 0; j < std::size(filterCoefficients); ++j) {
; 13   :             if (i + j < numElements) {

	lea	rax, QWORD PTR [r8+5]
	cmp	rax, rdx
	jae	SHORT $LN30@ModifyBits

; 14   :                 result += chunkPointer[i + j] * filterCoefficients[j];

	movss	xmm0, DWORD PTR [rcx+20]
	mulss	xmm0, xmm2
	subss	xmm1, xmm0
$LN30@ModifyBits:

; 15   :             }
; 16   :         }
; 17   :         chunkPointer[i] = result;

	movss	DWORD PTR [rcx-8], xmm1
	lea	rax, QWORD PTR [r9-2]
	add	rcx, 4
	mov	r8, r9
	cmp	rax, rdx
	jb	$LL4@ModifyBits
$LN3@ModifyBits:

; 18   :     }
; 19   : }

	ret	0
ModifyBitsCpp ENDP
_TEXT	ENDS
END
