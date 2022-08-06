;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-08-6 20:18:54
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
