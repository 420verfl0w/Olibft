;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-50-27 02:50:38
;; Filename	: ft_read
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_read

section '.text' executable

ft_read:
	xor rax, rax
	syscall
	ret
