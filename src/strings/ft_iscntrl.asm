;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-26 23:50:15
;; Filename	: ft_iscntrl
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_iscntrl

section '.text' executable

ft_iscntrl:
	cmp     edi, 31		; is arg below space ?
	setbe   al			; if yes, al = 1, al = 0 if not
	cmp     edi, 127	; is arg equal to DEL ?
	sete    dl			; if yes, al = 1, al = 0 if not
	or      eax, edx
	movzx   eax, al		; copies al to eax and zero extends the value
	ret
