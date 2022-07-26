;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-27 00:19:26
;; Filename	: ft_isspace
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_isspace

section '.text' executable

ft_isspace:
	lea     eax, [rdi - '\t']
	cmp     eax, 4
	setbe   al
	cmp     edi, ' '
	sete    dl
	or      eax, edx
	movzx   eax, al
	ret
