;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-07-28 18:07:33
;; Filename	: ft_bswap_32
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_bswap_32

section '.text' executable

ft_bswap_32:
	xchg eax, edi
	bswap eax
	ret
