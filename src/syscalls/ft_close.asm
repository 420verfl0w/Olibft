;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-30-27 03:30:41
;; Filename	: ft_close
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_close

section '.text' executable

ft_close:
	mov rax, 0x3
	syscall
	ret
