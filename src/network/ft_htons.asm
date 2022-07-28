;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-42-28 19:42:41
;; Filename	: ft_htons
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_htons

section '.text' executable

ft_htons:
	mov eax, edi
	rol ax, 0x8
	ret
