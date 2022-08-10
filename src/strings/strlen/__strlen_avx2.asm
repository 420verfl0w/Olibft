;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 
;; Author   : maldavid
;; Date     : 2022-08-10 22:36:41
;; Filename : __strlen_avx2
;; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public __strlen_avx2

section '.text' executable

__strlen_avx2:
	mov ecx, edi
	mov rdx, rdi
	vpxor xmm0, xmm0, xmm0
	and ecx, 0x3f
	cmp ecx, 0x20
	ja .L01
	vpcmpeqb ymm1, ymm0, yword [rdi]
	vpmovmskb eax, ymm1
	test eax, eax
	jne .L02
	add rdi, 0x20
	and ecx, 0x1f
	and rdi, 0xffffffffffffffe0
	jmp .L03

.L01:
	and ecx, 0x1f
	and rdi, 0xffffffffffffffe0
	vpcmpeqb ymm1, ymm0, yword [rdi]
	vpmovmskb eax, ymm1
	sar eax, cl
	test eax, eax
	je .L0101
	tzcnt eax, eax
	add rax, rdi
	add rax, rcx
	sub rax, rdx
	vzeroupper
	ret

.L0101:
	add rdi, 0x20
.L03:
	vpcmpeqb ymm1, ymm0, yword [rdi]
	vpmovmskb eax, ymm1
	test eax, eax
	jne .L02
	vpcmpeqb ymm1, ymm0, yword [rdi + 0x20]
	vpmovmskb eax, ymm1
	test eax, eax
	jne .L0301
	vpcmpeqb ymm1, ymm0, yword [rdi + 0x40]
	vpmovmskb eax, ymm1
	test eax, eax
	jne .L0302
	vpcmpeqb ymm1, ymm0, yword [rdi + 0x60]
	vpmovmskb eax, ymm1
	test eax, eax
	jne .L0303
	add rdi, 0x80
	mov rcx, rdi
	and ecx, 0x7f
	and rdi, 0xffffffffffffff80
	nop dword [rax + rax]

.loop:
	vmovdqa ymm1, yword [rdi]
	vmovdqa ymm2, yword [rdi + 0x20]
	vmovdqa ymm3, yword [rdi + 0x40]
	vmovdqa ymm4, yword [rdi + 0x60]
	vpminub ymm5, ymm2, ymm1
	vpminub ymm6, ymm4, ymm3
	vpminub ymm5, ymm6, ymm5
	vpcmpeqb ymm5, ymm0, ymm5
	vpmovmskb eax, ymm5
	test eax, eax
	jne .loop_escape
	add rdi, 0x80
	jmp .loop

.L02:
	tzcnt eax, eax
	add rax, rdi
	sub rax, rdx
	vzeroupper
	ret

.L0301:
	tzcnt eax, eax
	add rax, 0x20
	add rax, rdi
	sub rax, rdx
	vzeroupper
	ret

.L0302:
	tzcnt eax, eax
	add rax, 0x40
	add rax, rdi
	sub rax, rdx
	vzeroupper
	ret

.loop_escape:
	vpcmpeqb ymm1, ymm0, ymm1
	vpmovmskb eax, ymm1
	test eax, eax
	jne .L02
	vpcmpeqb ymm2, ymm0, ymm2
	vpmovmskb eax, ymm2
	test eax, eax
	jne .L0301
	vpcmpeqb ymm3, ymm0, ymm3
	vpmovmskb eax, ymm3
	test eax, eax
	jne .L0302
	vpcmpeqb ymm4, ymm0, ymm4
	vpmovmskb eax, ymm4

.L0303:
	tzcnt eax, eax
	add rax, 0x60
	add rax, rdi
	sub rax, rdx
	vzeroupper
	ret
