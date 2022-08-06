;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-08-06 18:46:32
;; Filename	: ft_nbrlen
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_nbrlen

section '.text' executable

ft_nbrlen:
	mov eax, 1		; set the counter to 1
	test rdi, rdi	; if nbr passed is positive
	jns .L2			; we jump directly to .L2
	neg rdi			; else we make the nbr positive
	mov eax, 2		; we increment the size counter by 1

.L2:
	cmp rdi, 9	; if the nbr is less than 10
	jle .L1		; we return the size

.L4:
	imul rdi, rdi, 0x1999999A	; fast division by ten (nb = (0x1999999A * nb) >> 32;)
	sar rdi, 32
	add eax, 1	; adding 1 to the counter
	cmp rdi, 9	; while nbr is greater than 9
	jg  .L4		; we loop

.L1:
	ret

