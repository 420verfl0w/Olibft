;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-27 00:23:40
;; Filename	: ft_isxdigit
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_isxdigit

section '.text' executable

ft_isxdigit:
	mov     eax, edi
	and     eax, -33 ; convert to uppercase (if arg is already uppercase, it doesn't change)
	sub     eax, 'A' ; substracts 65 to arg
	cmp     eax, 5
	setbe   al
	sub     edi, '0'
	cmp     edi, 9
	setbe   dl
	or      eax, edx
	movzx   eax, al
	ret
