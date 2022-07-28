;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-11-28 18:11:23
;; Filename	: ft_bswap_64
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_bswap_64

section '.text' executable

ft_bswap_64:
	xchg rax, rdi
	bswap rax
	ret
