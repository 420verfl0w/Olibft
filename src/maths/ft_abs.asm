;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-27 19:06:54
;; Filename	: ft_abs
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_abs

section '.text' executable

ft_abs:
	mov ebx, eax
	neg eax
	cmovl eax, ebx ; if eax is now negative, restore its saved value
	ret
