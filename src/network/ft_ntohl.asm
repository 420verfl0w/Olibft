;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-46-28 19:46:42
;; Filename	: ft_ntohl
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_ntohl

section '.text' executable

ft_ntohl:
	mov eax, edi
	bswap eax
	ret
