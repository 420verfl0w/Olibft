;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-29-27 20:29:47
;; Filename	: ft_mprotect
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_mprotect

section '.text' executable

ft_mprotect:
	mov rax, 0xa
	syscall
	ret
