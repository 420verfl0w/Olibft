;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-09-27 04:09:52
;; Filename	: ft_chdir
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_chdir

section '.text' executable

ft_chdir:
	mov rax, 0x50
	syscall
	ret
