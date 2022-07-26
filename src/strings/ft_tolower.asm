;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-55-26 23:55:23
;; Filename	: ft_tolower
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_tolower

section '.text' executable

ft_tolower:
	lea ecx, dword [rdi - 'A']
	mov edx, edi
	mov eax, edi
	or edx, 0x20	; swap uppercase to lowercase, an xor 0x20 can be done too
	cmp ecx, 0x1a
	cmovb eax, edx	; check if carry flag is set move edx to eax
	ret
