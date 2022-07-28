;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-27 23:01:15
;; Filename	: __memset_avx512_unaligned
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

include '__memset_avx_utils.asm'

public __memset_avx512_unaligned

section '.text' executable

__memset_avx512_unaligned:
	vmovd xmm0, esi
	mov rax, rdi
	vpbroadcastb xmm0, xmm0
	vpbroadcastq zmm0, xmm0
	cmp rdx, 0x40
	jb .L01
	cmp rdx, 0x80
	ja avx_size_checker
	vmovdqu64 zword [rdi + rdx - 0x40], zmm0
	vmovdqu64 zword [rdi], zmm0
	vzeroupper
	ret

.L01:
	cmp dl, 0x20
	jae .L02
	cmp dl, 0x10
	jae .L03
	vmovq rcx, xmm0
	cmp dl, 8
	jae .L04
	cmp dl, 4
	jae .L05
	cmp dl, 1
	ja .L06
	jb end_avx
	mov byte [rdi], cl
	vzeroupper
	ret

.L02:
	vmovdqu yword [rdi + rdx - 0x20], ymm0
	vmovdqu yword [rdi], ymm0
	vzeroupper
	ret

.L03:
	vmovdqu xword [rdi + rdx - 0x10], xmm0
	vmovdqu xword [rdi], xmm0
	vzeroupper
	ret

.L04:
	mov qword [rdi + rdx - 8], rcx
	mov qword [rdi], rcx
	vzeroupper
	ret

.L05:
	mov dword [rdi + rdx - 4], ecx
	mov dword [rdi], ecx
	vzeroupper
	ret

.L06:
	mov word [rdi + rdx - 2], cx
	mov word [rdi], cx
	vzeroupper
	ret

