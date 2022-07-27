;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-02-27 04:02:39
;; Filename	: ft_exit
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_exit

section '.text' executable

ft_exit:
	mov rax, 0x3c
	syscall
	ret
