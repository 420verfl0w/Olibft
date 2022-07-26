;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-26 23:34:20
;; Filename	: ft_isblank
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_isblank

section '.text' executable

ft_isblank:
	cmp     edi, ' '  ; is arg equal to space ?
	sete    al		  ; sets al to 1 if arg is equal to space
	cmp     edi, '\t' ; is arg equal to tab ?
	sete    dl		  ; sets al to 1 if arg is equal to tab
	or      eax, edx
	movzx   eax, al	  ; copies al to eax and zero extends the value
	ret
