;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-26 21:24:37
;; Filename	: ft_sqrt
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_sqrt

section '.text' executable

ft_sqrt:
	sqrtss xmm0, xmm0 ; calc the sqrt of the given number using single precision float numbers
	ret
