;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-26 22:58:32
;; Filename	: ft_isalpha
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_isalpha

section '.text' executable

ft_isalpha:
	and     edi, -33 ; convert to uppercase (if arg is already uppercase, it doesn't change)
	xor     eax, eax ; set eax to 0
	sub     edi, 'A' ; substracts 65 to arg given
	cmp     edi, 25  ; arg is below 25 (size of the alphabet) ? 
	setbe   al		 ; sets al to 1 if cmp is true, 0 if not
	ret
