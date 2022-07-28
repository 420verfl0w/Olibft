;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-27 23:53:45
;; Filename	: __memset_avx_utils
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

end_avx:
	vzeroupper
	ret

avx_size_checker:
	cmp rdx, 0x800
	ja .size_2048
	cmp rdx, 0x100
	ja .size_256
	vmovdqu64 zword [rdi], zmm0
	vmovdqu64 zword [rdi + 0x40], zmm0
	vmovdqu64 zword [rdi + rdx - 0x40], zmm0
	vmovdqu64 zword [rdi + rdx - 0x80], zmm0
	vzeroupper
	ret

.size_2048:
	vzeroupper
	mov rcx, rdx
	movzx eax, sil
	mov rdx, rdi
	rep stosb
	mov rax, rdx
	ret

.size_256:
	lea rcx, [rdi + 0x100]
	vmovdqu64 zword [rdi], zmm0
	and rcx, 0xffffffffffffff00
	vmovdqu64 zword [rdi + rdx - 0x40], zmm0
	vmovdqu64 zword [rdi + 0x40], zmm0
	vmovdqu64 zword [rdi + rdx - 0x80], zmm0
	vmovdqu64 zword [rdi + 0x80], zmm0
	vmovdqu64 zword [rdi + rdx - 0xc0], zmm0
	vmovdqu64 zword [rdi + 0xc0], zmm0
	vmovdqu64 zword [rdi + rdx - 0x100], zmm0
	add rdx, rdi
	and rdx, 0xffffffffffffff00
	cmp rcx, rdx
	je end_avx
	jmp .loop

.loop:
	vmovdqa64 zword [rcx], zmm0
	vmovdqa64 zword [rcx + 0x40], zmm0
	vmovdqa64 zword [rcx + 0x80], zmm0
	vmovdqa64 zword [rcx + 0xc0], zmm0
	add rcx, 0x100
	cmp rdx, rcx
	jne .loop
	vzeroupper
	ret

avx_20:
	cmp dl, 0x10
	jae .L02
	vmovq rcx, xmm0
	cmp dl, 8
	jae .L03
	cmp dl, 4
	jae .L04
	cmp dl, 1
	ja .L05
	jb end_avx
	mov byte [rdi], cl
	vzeroupper
	ret

.L02:
	vmovdqu xword [rdi + rdx - 0x10], xmm0
	vmovdqu xword [rdi], xmm0
	vzeroupper
	ret

.L03:
	mov qword [rdi + rdx - 8], rcx
	mov qword [rdi], rcx
	vzeroupper
	ret

.L04:
	mov dword [rdi + rdx - 4], ecx
	mov dword [rdi], ecx
	vzeroupper
	ret

.L05:
	mov word [rdi + rdx - 2], cx
	mov word [rdi], cx
	vzeroupper
	ret
