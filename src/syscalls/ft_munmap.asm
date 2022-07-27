;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-36-27 13:36:42
;; Filename	: ft_munmap
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_munmap

section '.text' executable

ft_munmap:
	mov rax, 0xb
	syscall
	ret
