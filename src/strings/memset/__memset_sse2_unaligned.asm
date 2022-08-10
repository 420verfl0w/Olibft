;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-27 23:01:15
;; Filename	: __memset_sse2_unaligned
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

include '__memset_sse2_unaligned_erms.asm'

public __memset_sse2_unaligned

section '.text' executable

__memset_sse2_unaligned:
	movd xmm0, esi
	mov rax, rdi
	punpcklbw xmm0, xmm0
	punpcklwd xmm0, xmm0
	pshufd  xmm0, xmm0, 0
	cmp rdx, 0x10
	jb smart_setter
	cmp rdx, 0x20
	ja _sse2_shared_setter
	movdqu  xword [rdi + rdx - 0x10], xmm0
	movdqu  xword [rdi], xmm0
	ret

.L01:
	cmp rdx, 0x40
	ja .L02
	movdqu xword [rdi], xmm0
	movdqu xword [rdi + 0x10], xmm0
	movdqu xword [rdi + rdx - 0x10], xmm0
	movdqu xword [rdi + rdx - 0x20], xmm0
	ret

.L02:
	lea rcx, [rdi + 0x40]
	movdqu  xword [rdi], xmm0
	and rcx, 0xffffffffffffffc0
	movdqu xword [rdi + rdx - 0x10], xmm0
	movdqu xword [rdi + 0x10], xmm0
	movdqu xword [rdi + rdx - 0x20], xmm0
	movdqu xword [rdi + 0x20], xmm0
	movdqu xword [rdi + rdx - 0x30], xmm0
	movdqu xword [rdi + 0x30], xmm0
	movdqu xword [rdi + rdx - 0x40], xmm0
	add rdx, rdi
	and rdx, 0xffffffffffffffc0
	cmp rcx, rdx
	je end_func
	jmp .loop
	ret

.loop:
	movdqa xword [rcx], xmm0
	movdqa xword [rcx + 0x10], xmm0
	movdqa xword [rcx + 0x20], xmm0
	movdqa xword [rcx + 0x30], xmm0
	add rcx, 0x40
	cmp rdx, rcx
	jne .loop
