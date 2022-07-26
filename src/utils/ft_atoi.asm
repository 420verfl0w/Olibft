;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-50-26 20:50:44
;; Filename	: ft_atoi
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_atoi

section '.text' executable

; TODO : je vais rename apres juste la c'est la sauce x)

ft_atoi:
	xor eax, eax
	mov ecx, 1
	jmp .L1

.L3:
	inc rdi
	
.L1:
	movzx edx, byte [rdi]
	test dl, dl
	jz .ret
	sub edx, 0x9			; substract '\t'
	cmp dl, 0x4				; *str >= '\t' && *str <= '\r'
	jbe .L3

.L4:
	cmp byte [rdi], 0
	je .ret
	movzx edx, byte [rdi]
	sub edx, 0x2b			; '+'
	test dl, 0xfd 			; check if ','
	jnz .L6
	cmp dl, 0x2d
	je @f

@@:
	not ecx
	add ecx, 1

.L5:
	inc rdi
	jmp .L4

.L6:
	movzx edx, byte [rdi]
	test dl, dl
	jz .ret
	sub dl, 0x30
	cmp dl, 0x9
	ja .ret
	and dl, 0xF
	lea eax, dword [rax+rax*4]
	lea eax, dword [rdx+rax*2]
	inc rdi
	jmp .L6

.ret:
	imul eax, ecx
	ret
