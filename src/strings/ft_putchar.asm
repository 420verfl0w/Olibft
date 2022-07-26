;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-44-26 23:44:27
;; Filename	: ft_putchar
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_putchar

section '.text' executable

ft_putchar:
	push rdi
	mov rax, 0x1
	mov rdi, 0x1
	mov rsi, rsp
	mov rdx, 0x1
	syscall
	add rsp, 0x8
	ret
