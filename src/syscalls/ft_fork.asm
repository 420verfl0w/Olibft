;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-21-27 04:21:24
;; Filename	: ft_fork
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_fork

section '.text' executable

ft_fork:
	mov rax, 0x39
	syscall
	ret
