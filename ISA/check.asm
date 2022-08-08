;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-33-28 23:33:55
;; Filename	: check
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64 executable 3

entry _start

segment readable writeable
	avx2_str db "AVX2/"
	len_avx2 = $ - avx2_str
	avx_str  db "AVX/"
	len_avx = $ - avx_str
	sse2_str db "SSE2/"
	len_sse2 = $ - sse2_str
	sse_str  db "SSE/"
	len_sse = $ - sse_str
	erms_str db "ERMS/"
	len_erms = $ - erms_str

segment readable executable

_start:
	jmp _check_avx2

_check_avx2:
	mov eax, 0x7
	xor ecx, ecx
	cpuid
	shr ebx, 0x5
	and ebx, 0x1
	cmp ebx, 0x1
	je is_avx2

_check_avx:
	mov eax, 0x1
	cpuid
	shr ecx, 28
	and ecx, 0x1
	cmp ecx, 0x1
	je is_avx

_check_sse2:
	mov eax, 0x1
	cpuid
	shr edx, 26
	and edx, 0x1
	cmp edx, 0x1
	je is_sse2

_check_sse:
	mov eax, 0x1
	cpuid
	shr edx, 25
	and edx, 0x1
	cmp edx, 0x1
	je is_sse

is_avx2:
	mov rax, 0x1
	mov rdi, 0x1
	mov rsi, avx2_str
	mov rdx, len_avx2
	syscall
	jmp is_erms

is_avx:
	mov rax, 0x1
	mov rdi, 0x1
	mov rsi, avx_str
	mov rdx, len_avx
	syscall
	jmp is_erms

is_sse2:
	mov rax, 0x1
	mov rdi, 0x1
	mov rsi, sse2_str
	mov rdx, len_sse2
	syscall
	jmp is_erms

is_sse:
	mov rax, 0x1
	mov rdi, 0x1
	mov rsi, sse_str
	mov rdx, len_sse
	syscall
	jmp is_erms

_check_erms:
	mov eax, 0x7
	xor ecx, ecx
	cpuid
	shr ebx, 0x9
	and ebx, 0x1
	cmp ebx, 0x1
	je is_erms

is_erms:
	mov rax, 0x1
	mov rdi, 0x1
	mov rsi, erms_str
	mov rdx, len_erms
	syscall

_exit:
	mov rax, 0x1
	mov rdi, 0x1
	mov rsi, 0
	mov rdx, 1
	syscall
	mov rax, 0x3c
	xor rdi, rdi
	syscall
