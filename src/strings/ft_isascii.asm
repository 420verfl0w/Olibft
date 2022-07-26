;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-26 23:34:20
;; Filename	: ft_isascii
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_isalpha

section '.text' executable

ft_isalpha:
	xor     eax, eax ; sets eax to 0
	cmp     edi, 127 ; is arg bellow 127 ?
	setbe   al		 ; sets al to 1 if cmp is true, 0 if not
	ret
