;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-47-28 19:47:08
;; Filename	: ft_htonl
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_htonl

section '.text' executable

ft_htonl:
	mov eax, edi
	bswap eax
	ret
