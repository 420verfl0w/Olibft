;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-50-26 20:50:44
;; Filename	: ft_atoi
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_atoi

;int	ft_atoi(const char *str)
;{
;	long long int	to_dec;
;   int neg;
;
;	to_dec = 0;
;   neg = 1;
;	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
;		str++;
;	while (*str && (*str == '+' || *str == '-'))
;		if (*str++ == '-') neg = ~(neg - 1);
;	while (*str && *str >= '0' && *str <= '9')
;		to_dec = ((to_dec << 1) + (to_dec << 3) + (*str++ & 0xF));
;	if (to_dec > INT_MAX || to_dec < INT_MIN) return (0);
;	return (to_dec * neg);
;}

section '.text' executable

ft_atoi:
	jmp .L16

.L19:
        lea     edx, dword [rax-0x9]
        cmp     dl, 0x4			; check whitespace
        jbe     .L4
        cmp     al, 0x20		; check space
        jne     .L18
.L4:
        add     rdi, 0x1
.L16:
        movzx   eax, byte [rdi]
        test    al, al			; perform AND, set zero flag if is true
        jne     .L19
.L12:
        xor     esi, esi
.L1:
        mov     eax, esi
        ret
.L18:
        mov     ecx, 0x1		; set neg to one
        jmp     .L5
.L7:
        add     rdi, 1
        mov     edx, ecx
        neg     edx
        cmp     al, '-'
        movzx   eax, byte [rdi]
        cmove   ecx, edx
        test    al, al
        je      .L12
.L5:
        lea     edx, dword [rax-'+']	; check if + or -
        and     edx, 0xFD
        je      .L7
        lea     edx, dword [rax- '0' ]	; check if char is digits
        cmp     dl, 9
        ja      .L12					; ret if not digits
        xor     edx, edx
.L8:
        and     eax, 0xF				; take nibble of one byte of eax
        lea     rdx, qword [rdx+rdx*4]	; mul by 10
        add     rdi, 1
        lea     rdx, qword [rax+rdx*2]	; mul by 10
        movzx   eax, byte [rdi]
        lea     esi, dword [rax-48]		; check if number
        cmp     sil, 0x9
        jbe     .L8						; reloop
        mov     eax, 0x80000000	; check overflow
        xor     esi, esi
        add     rax, rdx
        shr     rax, 0x20		; check overflow
        jne     .L1
        imul    ecx, edx
        mov     eax, ecx
        ret
