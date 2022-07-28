;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: stales
;; Date   	: 2022-50-28 17:50:33
;; Filename	: ft_bswap_16
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_bswap_16

section '.text' executable

ft_bswap_16:
	;(((di >> 8) & 0xFF) | ((di) & 0xFF) << 8)
	mov ax, di
	shr di, 0x8
	and di, 0xFF
	and ax, 0xFF
	shl ax, 0x8
	or ax, di
	ret
