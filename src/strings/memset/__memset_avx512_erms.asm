;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-28 17:15:30
;; Filename	: __memset_avx512_erms
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

__memset_avx512_erms:
	vzeroupper
	mov rcx, rdx
	movzx eax, sil
	mov rdx, rdi
	rep stosb
	mov rax, rdx
	ret
