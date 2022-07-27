;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-21-27 03:21:27
;; Filename	: ft_open
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_open

section '.text' executable

ft_open:
	mov rax, 0x2
	syscall
	ret
