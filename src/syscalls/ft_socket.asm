;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-02-28 12:02:42
;; Filename	: ft_socket
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_socket

section '.text' executable

ft_socket:
	mov rax, 0x29
	syscall
	ret
