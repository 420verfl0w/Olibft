;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-27 23:01:15
;; Filename	: __memset_sse2_unaligned
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public __memset_sse2_unaligned

section '.text' executable

__memset_sse2_unaligned:
	movd    xmm0, esi
	mov     rax, rdi
	punpcklbw xmm0, xmm0
	punpcklwd xmm0, xmm0
	pshufd  xmm0, xmm0, 0
	cmp     rdx, 0x10
	jb      .L01
	cmp     rdx, 0x20
	ja      .L02
	movdqu  xword [rdi + rdx - 0x10], xmm0
	movdqu  xword [rdi], xmm0
	ret

.L01:
	ret

.L02:
	ret
