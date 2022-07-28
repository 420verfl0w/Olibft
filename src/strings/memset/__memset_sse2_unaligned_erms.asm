;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-27 23:02:13
;; Filename	: __memset_sse2_unaligned_erms
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public __memset_sse2_unaligned_erms

file '__memset_erms.asm'

section '.text' executable

; PS : si ca marche pas rajoute endbr64 au debut

__memset_sse2_unaligned_erms:
	movd xmm0, esi
	mov rax, rdi
	punpcklbw xmm0, xmm0
	punpcklwd xmm0, xmm0
	pshufd  xmm0, xmm0, 0
	cmp rdx, 0x10
	jb .L02
	cmp rdx, 0x20
	ja .L01
	movdqu  xword [rdi + rdx - 0x10], xmm0
	movdqu  xword [rdi], xmm0
	ret

.L01:
	cmp rdx, 0x800
	ja .setter ; defined in __memset_erms.asm

.L02:
	movq    rcx, xmm0
	cmp     dl, 8 
	; TODO, continue demain
