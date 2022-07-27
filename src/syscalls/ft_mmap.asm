;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-35-27 13:35:19
;; Filename	: ft_mmap
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_mmap

section '.text' executable

ft_mmap:
	mov rax, 0x9
	mov r10, rcx
	mov r8d, -1
	xor r9, r9
	syscall
	cmp rax, 0xfffffffffffff000
	ja @f
	ret

@@:
	xor rax, rax
	not rax
	ret
