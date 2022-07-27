;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Author 	: maldavid
;; Date   	: 2022-07-27 15:03:32
;; Filename	: ft_strerrno
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

format ELF64

public ft_strerrno

section '.text' executable

.LC0:
	.string "ft_errno : Unknown error code"

ft_strerrno:
	mov     eax, OFFSET FLAT:.LC0 ; loads the offest in memory of the default error message
	cmp     edi, 131 ; if errno is greater than 131 (number of error codes listed)
	ja      .L1		 ; it leaves the function
	mov     edi, edi
	mov     rax, QWORD PTR CSWTCH.1[0 + rdi * 8] ; returns strings that corresponds to the error code

.L1:
	ret

.LC1:
	.string "ft_errno : No error information"
.LC2:
	.string "ft_errno : Operation not permitted"
.LC3:
	.string "ft_errno : No such file or directory"
.LC4:
	.string "ft_errno : No such process"
.LC5:
	.string "ft_errno : Interrupted system call"
.LC6:
	.string "ft_errno : I/O error"
.LC7:
	.string "ft_errno : No such device or address"
.LC8:
	.string "ft_errno : Argument list too long"
.LC9:
	.string "ft_errno : Exec format error"
.LC10:
	.string "ft_errno : Bad file descriptor"
.LC11:
	.string "ft_errno : No child process"
.LC12:
	.string "ft_errno : Resource temporarily unavailable"
.LC13:
	.string "ft_errno : Out of memory"
.LC14:
	.string "ft_errno : Permission denied"
.LC15:
	.string "ft_errno : Bad address"
.LC16:
	.string "ft_errno : Block device required"
.LC17:
	.string "ft_errno : Resource busy"
.LC18:
	.string "ft_errno : File exists"
.LC19:
	.string "ft_errno : Cross-device link"
.LC20:
	.string "ft_errno : No such device"
.LC21:
	.string "ft_errno : Not a directory"
.LC22:
	.string "ft_errno : Is a directory"
.LC23:
	.string "ft_errno : Invalid argument"
.LC24:
	.string "ft_errno : Too many open files in system"
.LC25:
	.string "ft_errno : No file descriptors available"
.LC26:
	.string "ft_errno : Not a tty"
.LC27:
	.string "ft_errno : Text file busy"
.LC28:
	.string "ft_errno : File too large"
.LC29:
	.string "ft_errno : No space left on device"
.LC30:
	.string "ft_errno : Invalid seek"
.LC31:
	.string "ft_errno : Read-only file system"
.LC32:
	.string "ft_errno : Too many links"
.LC33:
	.string "ft_errno : Broken pipe"
.LC34:
	.string "ft_errno : Domain error"
.LC35:
	.string "ft_errno : Result not representable"
.LC36:
	.string "ft_errno : Resource deadlock would occur"
.LC37:
	.string "ft_errno : Filename too long"
.LC38:
	.string "ft_errno : No locks available"
.LC39:
	.string "ft_errno : Function not implemented"
.LC40:
	.string "ft_errno : Directory not empty"
.LC41:
	.string "ft_errno : Symbolic link loop"
.LC42:
	.string "ft_errno : No message of desired type"
.LC43:
	.string "ft_errno : Identifier removed"
.LC44:
	.string "ft_errno : Device not a stream"
.LC45:
	.string "ft_errno : No data available"
.LC46:
	.string "ft_errno : Device timeout"
.LC47:
	.string "ft_errno : Out of streams resources"
.LC48:
	.string "ft_errno : Link has been severed"
.LC49:
	.string "ft_errno : Protocol error"
.LC50:
	.string "ft_errno : Multihop attempted"
.LC51:
	.string "ft_errno : Bad message"
.LC52:
	.string "ft_errno : Value too large for data type"
.LC53:
	.string "ft_errno : File descriptor in bad state"
.LC54:
	.string "ft_errno : Illegal byte sequence"
.LC55:
	.string "ft_errno : Not a socket"
.LC56:
	.string "ft_errno : Destination address required"
.LC57:
	.string "ft_errno : Message too large"
.LC58:
	.string "ft_errno : Protocol wrong type for socket"
.LC59:
	.string "ft_errno : Protocol not available"
.LC60:
	.string "Protocol not supported"
.LC61:
	.string "Socket type not supported"
.LC62:
	.string "ft_errno : Not supported"
.LC63:
	.string "ft_errno : Protocol family not supported"
.LC64:
	.string "ft_errno : Address family not supported by protocol"
.LC65:
	.string "ft_errno : Address in use"
.LC66:
	.string "Address not available"
.LC67:
	.string "ft_errno : Network is down"
.LC68:
	.string "ft_errno : Network unreachable"
.LC69:
	.string "ft_errno : Connection reset by network"
.LC70:
	.string "ft_errno : Connection aborted"
.LC71:
	.string "ft_errno : Connection reset by peer"
.LC72:
	.string "ft_errno : No buffer space available"
.LC73:
	.string "ft_errno : Socket is connected"
.LC74:
	.string "ft_errno : Socket not connected"
.LC75:
	.string "ft_errno : Cannot send after socket shutdown"
.LC76:
	.string "ft_errno : Operation timed out"
.LC77:
	.string "ft_errno : Connection refused"
.LC78:
	.string "ft_errno : Host is down"
.LC79:
	.string "ft_errno : Host is unreachable"
.LC80:
	.string "ft_errno : Operation already in progress"
.LC81:
	.string "ft_errno : Operation in progress"
.LC82:
	.string "ft_errno : Stale file handle"
.LC83:
	.string "ft_errno : Remote I/O error"
.LC84:
	.string "ft_errno : Quota exceeded"
.LC85:
	.string "ft_errno : No medium found"
.LC86:
	.string "ft_errno : Wrong medium type"
.LC87:
	.string "ft_errno : Operation canceled"
.LC88:
	.string "ft_errno : Required key not available"
.LC89:
	.string "ft_errno : Key has expired"
.LC90:
	.string "ft_errno : Key has been revoked"
.LC91:
	.string "ft_errno : Key was rejected by service"
.LC92:
	.string "ft_errno : Previous owner died"
.LC93:
	.string "ft_errno : State not recoverable"

CSWTCH.1: ; like a switch case
	.quad   .LC1
	.quad   .LC2
	.quad   .LC3
	.quad   .LC4
	.quad   .LC5
	.quad   .LC6
	.quad   .LC7
	.quad   .LC8
	.quad   .LC9
	.quad   .LC10
	.quad   .LC11
	.quad   .LC12
	.quad   .LC13
	.quad   .LC14
	.quad   .LC15
	.quad   .LC16
	.quad   .LC17
	.quad   .LC18
	.quad   .LC19
	.quad   .LC20
	.quad   .LC21
	.quad   .LC22
	.quad   .LC23
	.quad   .LC24
	.quad   .LC25
	.quad   .LC26
	.quad   .LC27
	.quad   .LC28
	.quad   .LC29
	.quad   .LC30
	.quad   .LC31
	.quad   .LC32
	.quad   .LC33
	.quad   .LC34
	.quad   .LC35
	.quad   .LC36
	.quad   .LC37
	.quad   .LC38
	.quad   .LC39
	.quad   .LC40
	.quad   .LC41
	.quad   .LC0
	.quad   .LC42
	.quad   .LC43
	.quad   .LC0
	.quad   .LC0
	.quad   .LC0
	.quad   .LC0
	.quad   .LC0
	.quad   .LC0
	.quad   .LC0
	.quad   .LC0
	.quad   .LC0
	.quad   .LC0
	.quad   .LC0
	.quad   .LC0
	.quad   .LC0
	.quad   .LC0
	.quad   .LC0
	.quad   .LC0
	.quad   .LC44
	.quad   .LC45
	.quad   .LC46
	.quad   .LC47
	.quad   .LC0
	.quad   .LC0
	.quad   .LC0
	.quad   .LC48
	.quad   .LC0
	.quad   .LC0
	.quad   .LC0
	.quad   .LC49
	.quad   .LC50
	.quad   .LC0
	.quad   .LC51
	.quad   .LC52
	.quad   .LC0
	.quad   .LC53
	.quad   .LC0
	.quad   .LC0
	.quad   .LC0
	.quad   .LC0
	.quad   .LC0
	.quad   .LC0
	.quad   .LC54
	.quad   .LC0
	.quad   .LC0
	.quad   .LC0
	.quad   .LC55
	.quad   .LC56
	.quad   .LC57
	.quad   .LC58
	.quad   .LC59
	.quad   .LC60
	.quad   .LC61
	.quad   .LC62
	.quad   .LC63
	.quad   .LC64
	.quad   .LC65
	.quad   .LC66
	.quad   .LC67
	.quad   .LC68
	.quad   .LC69
	.quad   .LC70
	.quad   .LC71
	.quad   .LC72
	.quad   .LC73
	.quad   .LC74
	.quad   .LC75
	.quad   .LC0
	.quad   .LC76
	.quad   .LC77
	.quad   .LC78
	.quad   .LC79
	.quad   .LC80
	.quad   .LC81
	.quad   .LC82
	.quad   .LC0
	.quad   .LC0
	.quad   .LC0
	.quad   .LC0
	.quad   .LC83
	.quad   .LC84
	.quad   .LC85
	.quad   .LC86
	.quad   .LC87
	.quad   .LC88
	.quad   .LC89
	.quad   .LC90
	.quad   .LC91
	.quad   .LC92
	.quad   .LC93
