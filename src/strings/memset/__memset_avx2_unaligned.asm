;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-27 23:01:15
;; Filename	: __memset_avx2_unaligned
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public __memset_avx2_unaligned

section '.text' executable

__memset_avx2_unaligned:
	vmovd xmm0, esi
	mov rax, rdi
	vpbroadcastb ymm0, xmm0
	cmp rdx, 0x20
	jb .L01
	cmp rdx, 0x40
	ja .L06
	vmovdqu yword [rdi + rdx - 0x20], ymm0
	vmovdqu yword [rdi], ymm0
	vzeroupper
	ret

.L01:
	cmp dl, 0x10
	jae .L02
	vmovq rcx, xmm0
	cmp dl, 8
	jae .L03
	cmp dl, 4
	jae .L04
	cmp dl, 1
	ja .L05
	jb .end
	mov byte [rdi], cl
	vzeroupper
	ret

.L02:
	vmovdqu xword [rdi + rdx - 0x10], xmm0
	vmovdqu xword [rdi], xmm0
	vzeroupper
	ret

.L03:
	mov qword [rdi + rdx - 8], rcx
	mov qword [rdi], rcx
	vzeroupper
	ret

.L04:
	mov dword [rdi + rdx - 4], ecx
	mov dword [rdi], ecx
	vzeroupper
	ret

.L05:
	mov word [rdi + rdx - 2], cx
	mov word [rdi], cx
	vzeroupper
	ret

.L06:
	lea rcx, [rdi + 0x80]
	vmovdqu yword [rdi], ymm0
	and rcx, 0xffffffffffffff80
	vmovdqu yword [rdi + rdx - 0x20], ymm0
	vmovdqu yword [rdi + 0x20], ymm0
	vmovdqu yword [rdi + rdx - 0x40], ymm0
	vmovdqu yword [rdi + 0x40], ymm0
	vmovdqu yword [rdi + rdx - 0x60], ymm0
	vmovdqu yword [rdi + 0x60], ymm0
	vmovdqu yword [rdi + rdx - 0x80], ymm0
	add rdx, rdi
	and rdx, 0xffffffffffffff80
	cmp rcx, rdx
	je .end
	jmp .loop
	vzeroupper
	ret

.loop:
	vmovdqa yword [rcx], ymm0
	vmovdqa yword [rcx + 0x20], ymm0
	vmovdqa yword [rcx + 0x40], ymm0
	vmovdqa yword [rcx + 0x60], ymm0
	add rcx, 0x80
	cmp rdx, rcx
	jne .loop

.end:
	vzeroupper
	ret
