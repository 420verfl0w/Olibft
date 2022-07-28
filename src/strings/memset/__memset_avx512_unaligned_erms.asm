;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-27 23:02:13
;; Filename	: __memset_avx512_unaligned_erms
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public __memset_avx512_unaligned_erms

section '.text' executable

__memset_avx512_unaligned_erms:
	vmovd xmm0, esi
	mov rax, rdi
	vpbroadcastb xmm0, xmm0
	vpbroadcastq zmm0, xmm0
	cmp rdx, 0x40
	jb .L01
	cmp rdx, 0x80
	ja .size_checker
	vmovdqu64 zword [rdi + rdx - 0x40], zmm0
	vmovdqu64 zword [rdi], zmm0
	vzeroupper
	ret

.L01:
	cmp dl, 0x20
	jae .L02

.L02:
	vmovdqu yword [rdi + rdx - 0x20], ymm0
	vmovdqu yword [rdi], ymm0
	vzeroupper
	ret

.size_checker:
	cmp rdx, 0x800
	ja 0x446ab4
	cmp rdx, 0x100
	ja 0x446b3e

