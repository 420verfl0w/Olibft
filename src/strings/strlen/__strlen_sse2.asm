;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 
;; Author   : maldavid
;; Date     : 2022-08-10 23:45:23
;; Filename : __strlen_sse2
;; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public __strlen_sse2

section '.text' executable

__strlen_sse2:
	pxor xmm0, xmm0
	pxor xmm1, xmm1
	pxor xmm2, xmm2
	pxor xmm3, xmm3
	mov rax, rdi
	mov rcx, rdi
	and rcx, 0xfff
	cmp rcx, 0xfcf
	ja .L01
	movdqu  xmm4, xword [rax]
	pcmpeqb xmm4, xmm0
	pmovmskb edx, xmm4
	test edx, edx
	je .L02
	bsf eax, edx
	ret

.L02:
	and rax, 0xfffffffffffffff0
	pcmpeqb xmm1, xword [rax + 0x10]
	pcmpeqb xmm2, xword [rax + 0x20]
	pcmpeqb xmm3, xword [rax + 0x30]
	pmovmskb edx, xmm1
	pmovmskb r8d, xmm2
	pmovmskb ecx, xmm3
	shl rdx, 0x10
	shl rcx, 0x10
	or rcx, r8
	shl rcx, 0x20
	or rdx, rcx
	mov rcx, rdi
	xor rcx, rax
	and rax, 0xffffffffffffffc0
	sar rdx, cl
	test rdx, rdx 
	je .L0201
	bsf rax, rdx
	ret

.L01:
	and rax, 0xffffffffffffffc0
	pcmpeqb xmm0, xword [rax]
	pcmpeqb xmm1, xword [rax + 0x10]
	pcmpeqb xmm2, xword [rax + 0x20]
	pcmpeqb xmm3, xword [rax + 0x30]
	pmovmskb esi, xmm0
	pmovmskb edx, xmm1
	pmovmskb r8d, xmm2
	pmovmskb ecx, xmm3
	shl rdx, 0x10
	shl rcx, 0x10
	or rdx, rsi
	or rcx, r8
	shl rcx, 0x20
	or rdx, rcx
	mov rcx, rdi
	xor rcx, rax
	and rax, 0xffffffffffffffc0
	sar rdx, cl
	test rdx, rdx
	je .L0101
	bsf rax, rdx
	ret

.L0101:
	pxor xmm1, xmm1
	pxor xmm2, xmm2
	pxor xmm3, xmm3
	nop dword [rax]

.L0201:
	movdqa xmm0, xword [rax + 0x40]
	pminub xmm0, xword [rax + 0x50]
	pminub xmm0, xword [rax + 0x60]
	pminub xmm0, xword [rax + 0x70]
	pcmpeqb xmm0, xmm3
	pmovmskb edx, xmm0
	test edx, edx
	jne .L0202
	sub rax, 0xffffffffffffff80
	movdqa xmm0, xword [rax]
	pminub xmm0, xword [rax + 0x10]
	pminub xmm0, xword [rax + 0x20]
	pminub xmm0, xword [rax + 0x30]
	pcmpeqb xmm0, xmm3
	pmovmskb edx, xmm0
	test edx, edx
	jne .L0203
	jmp .L0201

.L0202:
	add rax, 0x40
.L0203:
	pxor xmm0, xmm0
	pcmpeqb xmm0, xword [rax]
	pcmpeqb xmm1, xword [rax + 0x10]
	pcmpeqb xmm2, xword [rax + 0x20]
	pcmpeqb xmm3, xword [rax + 0x30]
	pmovmskb esi, xmm0
	pmovmskb edx, xmm1
	pmovmskb r8d, xmm2
	pmovmskb ecx, xmm3
	shl rdx, 0x10
	shl rcx, 0x10
	or rdx, rsi
	or rcx, r8
	shl rcx, 0x20
	or rdx, rcx
	bsf rdx, rdx
	add rax, rdx
	sub rax, rdi
	ret
