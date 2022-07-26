;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-26 23:58:18
;; Filename	: ft_islower
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_islower

section '.text' executable

ft_islower:
	sub     edi, 'a'	; substracts 97 to arg
	xor     eax, eax	; sets eax to 0
	cmp     edi, 25		; is arg in the alphabet ?
	setbe   al			; al = 1 if yes, al = 0 if not
	ret
