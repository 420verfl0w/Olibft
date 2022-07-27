;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-57-27 03:57:09
;; Filename	: ft_lseek
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_lseek

section '.text' executable

ft_lseek:
	mov rax, 0x8
	syscall
	ret
