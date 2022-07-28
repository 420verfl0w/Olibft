;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-28 17:14:20
;; Filename	: __memset_utils
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

end_func:
	ret

smart_setter:
	movq rcx, xmm0
	cmp dl, 8 
	jae setbytes8 ; copy 8 bytes by 8 bytes
	cmp dl, 4
	jae setbytes4 ; copy 4 bytes by 4 bytes
	cmp dl, 1
	ja setbytes1 ; copy bytes by bytes
	jb end_func
	mov byte [rdi], cl
	ret

setbytes8:
	mov qword [rdi + rdx - 8], rcx
	mov qword [rdi], rcx
	ret

setbytes4:
	mov dword [rdi + rdx - 4], ecx
	mov dword [rdi], ecx
	ret

setbytes1:
	mov word [rdi + rdx - 2], cx
	mov word [rdi], cx
	ret

dumb_setter:
	mov     rcx, rdx
	movzx   eax, sil
	mov     rdx, rdi
	rep    	stosb
	mov     rax, rdx
	ret

