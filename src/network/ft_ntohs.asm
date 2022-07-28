;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-44-28 19:44:05
;; Filename	: ft_ntohs
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_ntohs

section '.text' executable

ft_ntohs:
	mov eax, edi
	rol ax, 0x8
	ret
