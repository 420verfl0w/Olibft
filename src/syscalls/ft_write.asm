;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-41-27 02:41:03
;; Filename	: ft_write
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_write

section '.text' executable

ft_write:
	mov rax, 0x1
	syscall
	ret
