;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-27 22:59:15
;; Filename	: __memset_avx_no_vzeroupper
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public __memset_avx_no_vzeroupper

section '.text' executable

__memset_avx_no_vzeroupper:
	vpxor xmm0, xmm0, xmm0
	vmovd xmm1, esi
	lea rsi, [rdi + rdx]
	mov rax, rdi
	vpshufb xmm0, xmm1, xmm0
	cmp rdx, 0x10
	jb .L01
	cmp rdx, 0x200
	vbroadcastss zmm2 , xmm0
	ja .L001
	cmp rdx, 0x100
	jb .L0001
	vmovups zword [rdi], zmm2
	vmovups zword [rdi + 0x40], zmm2
	vmovups zword [rdi + 0x80], zmm2
	vmovups zword [rdi + 0xc0], zmm2
	vmovups zword [rsi - 0x100], zmm2
	vmovups zword [rsi - 0xc0], zmm2
	vmovups zword [rsi - 0x80], zmm2
	vmovups zword [rsi - 0x40], zmm2
	ret

.L01:
	cmp dl, 8
	jb .L02
	vmovq qword [rdi], xmm0
	vmovq qword [rsi - 8], xmm0
	ret

.L02:
	vmovd ecx, xmm0
	cmp dl, 4
	jb .L03
	mov dword [rdi], ecx
	mov dword [rsi - 4], ecx
	ret

.L03:
	cmp dl, 2
	jb .L04
	mov word [rdi], cx
	mov word [rsi - 2], cx
	ret

.L04:
	cmp dl, 1
	jb .end
	mov byte [rdi], cl
	ret

.L001:
	;mov rcx, qword [__x86_shared_cache_size_half]
	cmp rdx, rcx
	ja .L002
	cmp rdx, 0x400
	;ja 0x4458ef
	vmovups zword [rdi], zmm2
	vmovups zword [rdi + 0x40], zmm2
	vmovups zword [rdi + 0x80], zmm2
	vmovups zword [rdi + 0xc0], zmm2
	vmovups zword [rdi + 0x100], zmm2
	vmovups zword [rdi + 0x140], zmm2
	vmovups zword [rdi + 0x180], zmm2
	vmovups zword [rdi + 0x1c0], zmm2
	vmovups zword [rsi - 0x200], zmm2
	vmovups zword [rsi - 0x1c0], zmm2
	vmovups zword [rsi - 0x180], zmm2
	vmovups zword [rsi - 0x140], zmm2
	vmovups zword [rsi - 0x100], zmm2
	vmovups zword [rsi - 0xc0], zmm2
	vmovups zword [rsi - 0x80], zmm2
	vmovups zword [rsi - 0x40], zmm2
	ret

.L002:
	sub     rsi, 0x100 ; 256
	vmovups zword [rax], zmm2
	and     rdi, 0xffffffffffffffc0 ; arg1
	add     rdi, 0x40  ; sym.__libc_tsd_CTYPE_TOLOWER ; arg1
	jmp      .loop

.loop:
	vmovaps zword [rdi], zmm2
	vmovaps zword [rdi + 0x40], zmm2
	vmovaps zword [rdi + 0x80], zmm2
	vmovaps zword [rdi + 0xc0], zmm2
	add     rdi, 0x100 ; 256 ; arg1
	cmp     rdi, rsi   ; arg1
	jb      .loop
	vmovups zword [rsi], zmm2
	vmovups zword [rsi + 0x40], zmm2
	vmovups zword [rsi + 0x80], zmm2
	vmovups zword [rsi + 0xc0], zmm2
	ret

.L0001:
	cmp dl, 0x80
	jb .L0002
	vmovups zword [rdi], zmm2
	vmovups zword [rdi + 0x40], zmm2
	vmovups zword [rsi - 0x80], zmm2
	vmovups zword [rsi - 0x40], zmm2
	ret

.L0002:
	cmp  dl, 0x40
	jb .L0003
	vmovups zword [rdi], zmm2
	vmovups zword [rsi - 0x40], zmm2
	ret

.L0003:
	cmp dl, 0x20
	jb .L0004
	vmovdqu yword [rdi], ymm2
	vmovdqu yword [rsi - 0x20], ymm2
	ret

.L0004:
	vmovdqu xword [rdi], xmm0
	vmovdqu xword [rsi - 0x10], xmm0
	ret

.end:
	ret
