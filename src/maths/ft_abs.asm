;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-27 19:06:54
;; Filename	: ft_abs
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_asb

section '.text' executable

ft_abs:
	mov edx, edi
	sar edx, 28		; bit shifting edx to the left (edx >> 28)
	lea eax, [rdi + rdx] ; make mask
	xor eax, edx 	; aplying mask
	ret
