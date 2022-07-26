;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-27 00:12:45
;; Filename	: ft_isupper
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_isupper

section '.text' executable

ft_isupper:
	sub     edi, 'A' ; substracts 65 to arg
	xor     eax, eax ; sets eax to 0
	cmp     edi, 25	 ; is arg in the alphabet ?
	setbe   al		 ; al = 1 if yes, al = 0 if not
	ret
