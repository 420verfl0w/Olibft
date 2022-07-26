;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-26 23:55:15
;; Filename	: ft_isgraph
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_isgraph

section '.text' executable

ft_isgraph:
	sub     edi, 33	 ; substracts 0x33 to arg given
	xor     eax, eax ; sets eax to 0
	cmp     edi, 93	 ; is arg below 93 ?
	setbe   al		 ; if yes, al = 1, al = 0 if not
	ret

