;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-27 00:08:05
;; Filename	: ft_isprint
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_isprint

section '.text' executable

ft_isprint:
	sub     edi, ' ' ; substracts 32 to arg
	xor     eax, eax ; sets eax to 0
	cmp     edi, 94	 ; is arg below 94 ?
	setbe   al		 ; if yes al = 1, al = 0 if not
	ret
