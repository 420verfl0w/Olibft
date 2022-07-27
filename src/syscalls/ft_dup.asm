;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-17-27 15:17:16
;; Filename	: ft_dup
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_dup

section '.text' executable

ft_dup:
	mov rax, 0x20
	syscall
	ret
