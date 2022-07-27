/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:48:48 by stales            #+#    #+#             */
/*   Updated: 2022/07/27 16:10:51 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/////////////////////////////////
//
//			INCLUDES
//
/////////////////////////////////

# include <stddef.h>
# include <stdint.h>
# include <sys/types.h>

/////////////////////////////////
//
//			DEFINES
//
/////////////////////////////////

/*---===STDFD===---*/

# define STDIN_FD	 0x0
# define STDOUT_FD	 0x1
# define STDERR_FD	 0x2

/*---===FILE_DEF===---*/

# define OPEN_RO 	  0
# define OPEN_WO 	  1
# define OPEN_RW 	  2
# define OPEN_CREAT   0x0200
# define OPEN_EXCL	  0x0800
# define OPEN_TRUNC   0x0400
# define OPEN_NOCTTY  0x8000
# define OPEN_ASYNC   0x0040
# define OPEN_FSYNC   0x0080
# define OPEN_SYNC    0x0080
# define OPEN_SHLOCK  0x0010
# define OPEN_EXLOCK  0x0020
# define OPEN_DIR     0x00200000
# define OPEN_NOFLW   0x00000100
# define OPEN_CLOEXEC 0x00400000

/*---===SEEK_DEF===---*/

# define SEEK_SET	  0
# define SEEK_CUR     1
# define SEEK_END     2
# define SEEK_DATA    3
# define SEEK_HOLE    4
# define SEEK_MAX	  4

/*---===MMAP_DEF===---*/

/* Page can be read.  */
# define PROT_READ	  		0x1
/* Page can be written.  */
# define PROT_WRITE   		0x2
/* Page can be executed.  */
# define PROT_EXEC    		0x4
/* Page can not be accessed.  */
# define PROT_NONE    		0x0
/* Extend change to start of
 * growsdown vma (mprotect only).  */
# define PROT_GROWSDOWN		0x01000000
/* Extend change to start of
 * growsup vma (mprotect only).  */
# define PROT_GROWSUP		0x02000000
/* Share changes.  */
# define MAP_SHARED			0x1
/* Map failed. */
# define MAP_FAILED			((void *)-1)
/* Changes are private.  */
# define MAP_PRIVATE		0x2
/* Mask for type of mapping.  */
# define MAP_TYPE			0xF
/* Interpret addr exactly.  */
# define MAP_FIXED			0x10
/* Don't use a file.  */
# define MAP_ANONYMOUS		0x20
/* Sync memory asynchronously.  */
# define MS_ASYNC			0x1
/* Synchronous memory sync.  */
# define MS_SYNC			0x4
/* Invalidate the caches.  */
# define MS_INVALIDATE		0x2

/////////////////////////////////
//
//			TYPEDEFS
//
/////////////////////////////////

typedef int	t_fd;
typedef int	t_pid;

/////////////////////////////////
//
//			ENUM
//
/////////////////////////////////

enum e_file_flags
{
	FILE_DUPFD,
	FILE_GETFD,
	FILE_SETFD,
	FILE_GETFL,
	FILE_SETFL,
	FILE_GETOWN,
	FILE_SETOWN,
	FILE_GETLK,
	FILE_SETLK,
	FILE_SETLKW
};

enum e_s_perm_flags
{
	S_ISUID = (1 << 11),
	S_ISGID = (1 << 10),
	S_ISVTX = (1 << 9),
	S_IRUSR = (1 << 8),
	S_IWUSR = (1 << 7),
	S_IXUSR = (1 << 6),
	S_IRGRP = (1 << 5),
	S_IWGRP = (1 << 4),
	S_IXGRP = (1 << 3),
	S_IROTH = (1 << 2),
	S_IWOTH = (1 << 1),
	S_IXOTH = (1 << 0)
};

//////////////////////////////////
//
//			UTILS
//
//////////////////////////////////

extern int		ft_atoi(const char *nstr);
extern void		ft_swap(int *a, int *b);

//////////////////////////////////
//
//			MATHS
//
//////////////////////////////////

extern float	ft_sqrt(float nbr);

//////////////////////////////////
//
//			STRINGS
//
//////////////////////////////////

extern int		ft_isalpha(int c);
extern int		ft_isdigit(int c);
extern int		ft_isascii(int c);
extern int		ft_isblank(int c);
extern int		ft_isspace(int c);
extern int		ft_isgraph(int c);
extern int		ft_islower(int c);
extern int		ft_isprint(int c);
extern int		ft_isupper(int c);
extern int		ft_iscntrl(int c);
extern int		ft_isxdigit(int c);
extern int		ft_putchar(int c);
extern int		ft_tolower(int c);
extern int		ft_toupper(int c);

/////////////////////////////////
//
//			SYSCALLS
//
/////////////////////////////////

extern void		*ft_mmap(void *addr, size_t length, int prot, int flags);
extern off_t	ft_lseek(unsigned int fd, off_t offset, unsigned int whence);
extern int		ft_munmap(void *addr, size_t length);
extern int		ft_read(unsigned int fd, char *buf, size_t len);
extern int		ft_write(unsigned int fd, const char *buf, size_t len);
extern int		ft_open(const char *filename, int flags, int mode);
extern int		ft_close(unsigned int fd);
extern int		ft_exit(int code);
extern int		ft_chdir(const char *path);
extern t_pid	ft_fork(void);
extern int		ft_dup(unsigned int fd);
extern int		ft_dup2(unsigned int oldfd, unsigned int newfd);

/////////////////////////////////
//
//			ERRORS
//
/////////////////////////////////

int				*__ft_bits_get_errno_location(void);
# define FT_ERRNO (*__ft_bits_get_errno_location())

extern char		*ft_strerror(int e);

# define FT_EPERM            1
# define FT_ENOENT           2
# define FT_ESRCH            3
# define FT_EINTR            4
# define FT_EIO              5
# define FT_ENXIO            6
# define FT_E2BIG            7
# define FT_ENOEXEC          8
# define FT_EBADF            9
# define FT_ECHILD          10
# define FT_EAGAIN          11
# define FT_ENOMEM          12
# define FT_EACCES          13
# define FT_EFAULT          14
# define FT_ENOTBLK         15
# define FT_EBUSY           16
# define FT_EEXIST          17
# define FT_EXDEV           18
# define FT_ENODEV          19
# define FT_ENOTDIR         20
# define FT_EISDIR          21
# define FT_EINVAL          22
# define FT_ENFILE          23
# define FT_EMFILE          24
# define FT_ENOTTY          25
# define FT_ETXTBSY         26
# define FT_EFBIG           27
# define FT_ENOSPC          28
# define FT_ESPIPE          29
# define FT_EROFS           30
# define FT_EMLINK          31
# define FT_EPIPE           32
# define FT_EDOM            33
# define FT_ERANGE          34
# define FT_EDEADLK         35
# define FT_ENAMETOOLONG    36
# define FT_ENOLCK          37
# define FT_ENOSYS          38
# define FT_ENOTEMPTY       39
# define FT_ELOOP           40
# define FT_EWOULDBLOCK     FT_EAGAIN
# define FT_ENOMSG          42
# define FT_EIDRM           43
# define FT_ECHRNG          44
# define FT_EL2NSYNC        45
# define FT_EL3HLT          46
# define FT_EL3RST          47
# define FT_ELNRNG          48
# define FT_EUNATCH         49
# define FT_ENOCSI          50
# define FT_EL2HLT          51
# define FT_EBADE           52
# define FT_EBADR           53
# define FT_EXFULL          54
# define FT_ENOANO          55
# define FT_EBADRQC         56
# define FT_EBADSLT         57
# define FT_EDEADLOCK       FT_EDEADLK
# define FT_EBFONT          59
# define FT_ENOSTR          60
# define FT_ENODATA         61
# define FT_ETIME           62
# define FT_ENOSR           63
# define FT_ENONET          64
# define FT_ENOPKG          65
# define FT_EREMOTE         66
# define FT_ENOLINK         67
# define FT_EADV            68
# define FT_ESRMNT          69
# define FT_ECOMM           70
# define FT_EPROTO          71
# define FT_EMULTIHOP       72
# define FT_EDOTDOT         73
# define FT_EBADMSG         74
# define FT_EOVERFLOW       75
# define FT_ENOTUNIQ        76
# define FT_EBADFD          77
# define FT_EREMCHG         78
# define FT_ELIBACC         79
# define FT_ELIBBAD         80
# define FT_ELIBSCN         81
# define FT_ELIBMAX         82
# define FT_ELIBEXEC        83
# define FT_EILSEQ          84
# define FT_ERESTART        85
# define FT_ESTRPIPE        86
# define FT_EUSERS          87
# define FT_ENOTSOCK        88
# define FT_EDESTADDRREQ    89
# define FT_EMSGSIZE        90
# define FT_EPROTOTYPE      91
# define FT_ENOPROTOOPT     92
# define FT_EPROTONOSUPPORT 93
# define FT_ESOCKTNOSUPPORT 94
# define FT_EOPNOTSUPP      95
# define FT_ENOTSUP         FT_EOPNOTSUPP
# define FT_EPFNOSUPPORT    96
# define FT_EAFNOSUPPORT    97
# define FT_EADDRINUSE      98
# define FT_EADDRNOTAVAIL   99
# define FT_ENETDOWN        100
# define FT_ENETUNREACH     101
# define FT_ENETRESET       102
# define FT_ECONNABORTED    103
# define FT_ECONNRESET      104
# define FT_ENOBUFS         105
# define FT_EISCONN         106
# define FT_ENOTCONN        107
# define FT_ESHUTDOWN       108
# define FT_ETOOMANYREFS    109
# define FT_ETIMEDOUT       110
# define FT_ECONNREFUSED    111
# define FT_EHOSTDOWN       112
# define FT_EHOSTUNREACH    113
# define FT_EALREADY        114
# define FT_EINPROGRESS     115
# define FT_ESTALE          116
# define FT_EUCLEAN         117
# define FT_ENOTNAM         118
# define FT_ENAVAIL         119
# define FT_EISNAM          120
# define FT_EREMOTEIO       121
# define FT_EDQUOT          122
# define FT_ENOMEDIUM       123
# define FT_EMEDIUMTYPE     124
# define FT_ECANCELED       125
# define FT_ENOKEY          126
# define FT_EKEYEXPIRED     127
# define FT_EKEYREVOKED     128
# define FT_EKEYREJECTED    129
# define FT_EOWNERDEAD      130
# define FT_ENOTRECOVERABLE 131
# define FT_ERFKILL         132
# define FT_EHWPOISON       133

#endif
