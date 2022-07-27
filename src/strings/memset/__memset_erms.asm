;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-27 23:02:13
;; Filename	: __memset_erms
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public __memset_erms

section '.text' executable

__memset_erms:
	test rdx, rdx
	jne .setter
	mov rax, rdi
	ret

.setter:
	mov     rcx, rdx
	movzx   eax, sil
	mov     rdx, rdi
	rep     stosb byte [rdi], al
	mov     rax, rdx
	ret
