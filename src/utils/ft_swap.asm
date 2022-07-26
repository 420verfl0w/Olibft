;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-29-26 23:29:50
;; Filename	: ft_swap
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_swap

section '.text' executable

ft_swap:
	mov eax, dword [rdi]		; *a ^= *b
	xor eax, dword [rsi]

	mov dword [rdi], eax		; *b ^= *a
	xor eax, dword [rsi]
	
	mov dword [rsi], eax		; *a ^= *b
	xor dword [rdi], eax

	ret
