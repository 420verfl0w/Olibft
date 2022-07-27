;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-17-27 15:17:32
;; Filename	: ft_dup2
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_dup2

section '.text' executable

ft_dup2:
	mov rax, 0x21
	syscall
	ret
