;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-59-26 23:59:16
;; Filename	: ft_toupper
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_toupper

section '.text' executable

ft_toupper:
	lea ecx, dword [rdi - 'a']
	mov edx, edi
	mov eax, edi
	xor edx, 0x20	;	Swap lower to upper
	cmp ecx, 0x1a
	cmovb eax, edx	; move edx to eax if carry flag is set
	ret
