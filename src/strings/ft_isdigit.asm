;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-26 23:22:17
;; Filename	: ft_sqrt
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_isdigit

section '.text' executable

ft_isdigit:
	sub     edi, '0' ; subtracts 48 to arg given
	xor     eax, eax ; set eax to 0
	cmp     edi, 9	 ; arg is below to 9 ?
	setbe   al		 ; sets al to 1 if cmp is true, 0 if not
	ret
