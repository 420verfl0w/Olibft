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
