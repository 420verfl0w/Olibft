/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:48:48 by stales            #+#    #+#             */
/*   Updated: 2022/07/28 18:06:53 by stales           ###   ########.fr       */
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
# include <limits.h>

/////////////////////////////////
//
//			DEFINES
//
/////////////////////////////////

# ifndef FT_NULL
#  if defined(__cplusplus)
#   define FT_NULL 0L
#  elif __STDC_VERSION__ >= 199901L
#   define FT_NULL 0
#  else
#   define FT_NULL ((void*)0)
#  endif
# endif

# define FT_ERRNO		103

/*---===STDFD===---*/

# define FT_STDIN_FD	 0x0
# define FT_STDOUT_FD	 0x1
# define FT_STDERR_FD	 0x2

/*---===FILE_DEF===---*/

# define FT_OPEN_RO 	  0
# define FT_OPEN_WO 	  1
# define FT_OPEN_RW 	  2
# define FT_OPEN_CREAT   0x0200
# define FT_OPEN_EXCL	 0x0800
# define FT_OPEN_TRUNC   0x0400
# define FT_OPEN_NOCTTY  0x8000
# define FT_OPEN_ASYNC   0x0040
# define FT_OPEN_FSYNC   0x0080
# define FT_OPEN_SYNC    0x0080
# define FT_OPEN_SHLOCK  0x0010
# define FT_OPEN_EXLOCK  0x0020
# define FT_OPEN_DIR     0x00200000
# define FT_OPEN_NOFLW   0x00000100
# define FT_OPEN_CLOEXEC 0x00400000

/*---===SEEK_DEF===---*/

# define FT_SEEK_SET	  0
# define FT_SEEK_CUR     1
# define FT_SEEK_END     2
# define FT_SEEK_DATA    3
# define FT_SEEK_HOLE    4
# define FT_SEEK_MAX	  4

/*---===MMAP_DEF===---*/

/* Page can be read.  */
# define FT_PROT_READ	  		0x1
/* Page can be written.  */
# define FT_PROT_WRITE   		0x2
/* Page can be executed.  */
# define FT_PROT_EXEC    		0x4
/* Page can not be accessed.  */
# define FT_PROT_NONE    		0x0
/* Extend change to start of
 * growsdown vma (mprotect only).  */
# define FT_PROT_GROWSDOWN		0x01000000
/* Extend change to start of
 * growsup vma (mprotect only).  */
# define FT_PROT_GROWSUP		0x02000000
/* Share changes.  */
# define FT_MAP_SHARED			0x1
/* Map failed. */
# define FT_MAP_FAILED			((void *)-1)
/* Changes are private.  */
# define FT_MAP_PRIVATE			0x2
/* Mask for type of mapping.  */
# define FT_MAP_TYPE			0xF
/* Interpret addr exactly.  */
# define FT_MAP_FIXED			0x10
/* Don't use a file.  */
# define FT_MAP_ANONYMOUS		0x20
/* Sync memory asynchronously.  */
# define FT_MS_ASYNC			0x1
/* Synchronous memory sync.  */
# define FT_MS_SYNC				0x4
/* Invalidate the caches.  */
# define FT_MS_INVALIDATE		0x2

/////////////////////////////////
//
//			TYPEDEFS
//
/////////////////////////////////

typedef double			t_f64;
typedef unsigned int	t_u32;
typedef float			t_f32;
typedef int				t_fd;
typedef int				t_pid;
# ifdef FT_USE_NETWORK
typedef uint16_t		t_port;
# endif

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
//			STRUCT
//
//////////////////////////////////

/*---===Network Struct===---*/

struct	s_sockaddr
{
	unsigned short		sa_family;
	char				sa_data[14];
};

struct	s_in_addr
{
	unsigned long		s_addr;
};

struct	s_sockaddr_in
{
	short				sin_family;
	unsigned short		sin_port;
	struct s_in_addr	sin_addr;
	char				sin_zero[8];
};

//////////////////////////////////
//
//			UTILS
//
//////////////////////////////////

extern int			ft_atoi(const char *nstr);
extern void			ft_swap(int *a, int *b);

//////////////////////////////////
//
//			MATHS
//
//////////////////////////////////

extern float		ft_sqrt(float nbr);

//////////////////////////////////
//
//			STRINGS
//
//////////////////////////////////

extern int			ft_isalpha(int c);
extern int			ft_isdigit(int c);
extern int			ft_isascii(int c);
extern int			ft_isblank(int c);
extern int			ft_isspace(int c);
extern int			ft_isgraph(int c);
extern int			ft_islower(int c);
extern int			ft_isprint(int c);
extern int			ft_isupper(int c);
extern int			ft_iscntrl(int c);
extern int			ft_isxdigit(int c);
extern int			ft_putchar(int c);
extern int			ft_tolower(int c);
extern int			ft_toupper(int c);

/////////////////////////////////
//
//			SYSCALLS
//
/////////////////////////////////

extern void			*ft_mmap(void *addr, size_t length, int prot, int flags);
extern off_t		ft_lseek(t_u32 fd, off_t offset, t_u32 whence);
extern int			ft_munmap(void *addr, size_t length);
extern int			ft_read(unsigned int fd, char *buf, size_t len);
extern int			ft_write(unsigned int fd, const char *buf, size_t len);
extern int			ft_open(const char *filename, int flags, int mode);
extern int			ft_close(unsigned int fd);
extern int			ft_exit(int code);
extern int			ft_chdir(const char *path);
extern t_pid		ft_fork(void);
extern int			ft_dup(unsigned int fd);
extern int			ft_dup2(unsigned int oldfd, unsigned int newfd);
extern int			ft_mprotect(void *addr, size_t len, int prot);
extern int			ft_socket(int domain, int type, int protocol);

/////////////////////////////////
//
//			ERRORS
//
/////////////////////////////////

// src/sys/ft_errnotab.c
extern const char		*g_errno_tab[FT_ERRNO];

# ifdef __STDC_NO_ATOMICS__

static int				g_ft_errno = 0;
# else

//static _Atomic int		g_ft_errno = 0;
# endif

const char			*ft_strerrno(int e);

# define FT_EPERM		0x1
# define FT_ENOENT		0x2
# define FT_ESRCH		0x3
# define FT_EINTR		0x4
# define FT_EIO			0x5
# define FT_ENXIO		0x6
# define FT_E2BIG		0x7
# define FT_ENOEXEC		0x8
# define FT_EBADF		0x9
# define FT_ECHILD		0xa
# define FT_EDEADLK		0xb
# define FT_ENOMEM		0xc
# define FT_EACCES		0xd
# define FT_EFAULT		0xe
# define FT_ENOTBLK		0xf
# define FT_EBUSY		0x10
# define FT_EEXIST		0x11
# define FT_EXDEV		0x12
# define FT_ENODEV		0x13
# define FT_ENOTDIR		0x14
# define FT_EISDIR		0x15
# define FT_EINVAL		0x16
# define FT_EMFILE		0x18
# define FT_ENFILE		0x17
# define FT_ENOTTY		0x19
# define FT_ETXTBSY		0x1a
# define FT_EFBIG		0x1b
# define FT_ENOSPC		0x1c
# define FT_ESPIPE		0x1d
# define FT_EROFS		0x1e
# define FT_EMLINK		0x1f
# define FT_EPIPE		0x20
# define FT_EDOM		0x21
# define FT_ERANGE		0x22
# define FT_EAGAIN		0x23
# define FT_EINPROGRESS		0x24   
# define FT_EALREADY		0x25   
# define FT_ENOTSOCK		0x26   
# define FT_EMSGSIZE		0x28   
# define FT_EPROTOTYPE		0x29   
# define FT_ENOPROTOOPT		0x2a   
# define FT_EPROTONOSUPPORT	0x2b   
# define FT_ESOCKTNOSUPPORT	0x2c   
# define FT_EOPNOTSUPP		0x2d   
# define FT_EPFNOSUPPORT	0x2e   
# define FT_EAFNOSUPPORT	0x2f   
# define FT_EADDRINUSE		0x30   
# define FT_EADDRNOTAVAIL	0x31   
# define FT_ENETDOWN		0x32   
# define FT_ENETUNREACH		0x33   
# define FT_ENETRESET		0x34   
# define FT_ECONNABORTED	0x35   
# define FT_ECONNRESET		0x36   
# define FT_ENOBUFS			0x37   
# define FT_EISCONN			0x38   
# define FT_ENOTCONN		0x39   
# define FT_EDESTADDRREQ	0x27   
# define FT_ESHUTDOWN		0x3a   
# define FT_ETOOMANYREFS	0x3b
# define FT_ETIMEDOUT		0x3c
# define FT_ECONNREFUSED	0x3d
# define FT_ELOOP			0x3e
# define FT_ENAMETOOLONG	0x3f
# define FT_EHOSTDOWN		0x40
# define FT_EHOSTUNREACH	0x41
# define FT_ENOTEMPTY		0x42
# define FT_EPROCLIM		0x43
# define FT_EUSERS		0x44
# define FT_EDQUOT		0x45
# define FT_ESTALE		0x46
# define FT_EREMOTE		0x47
# define FT_EBADRPC		0x48
# define FT_ERPCMISMATCH		0x49
# define FT_EPROGUNAVAIL		0x4a
# define FT_EPROGMISMATCH		0x4b
# define FT_EPROCUNAVAIL		0x4c
# define FT_ENOLCK		0x4d
# define FT_EFTYPE		0x4f
# define FT_EAUTH		0x50
# define FT_ENEEDAUTH	0x51
# define FT_ENOSYS		0x4e
# define FT_ENOTSUP		0x76
# define FT_EILSEQ		0x6a
# define FT_EBACKGROUND	0x64
# define FT_EDIED		0x65
# define FT_ED			0x66
# define FT_EGREGIOUS	0x67
# define FT_EIEIO		0x68
# define FT_EGRATUITOUS	0x69
# define FT_EBADMSG		0x6b
# define FT_EIDRM		0x6c
# define FT_EMULTIHOP	0x6d
# define FT_ENODATA		0x6e
# define FT_ENOLINK		0x6f
# define FT_ENOMSG		0x70
# define FT_ENOSR		0x71
# define FT_ENOSTR		0x72
# define FT_EOVERFLOW	0x73
# define FT_EPROTO		0x74	
# define FT_ETIME		0x75	
# define FT_ECANCELED	0x77	
# define FT_EOWNERDEAD	0x78	
# define FT_ENOTRECOVERABLE		0x79

//////////////////////////////////
//
//			FUNCTIONS
//
//////////////////////////////////

extern	unsigned long	ft_bswap_64(unsigned long x);
extern	unsigned int	ft_bswap_32(unsigned int x);
extern	unsigned short	ft_bswap_16(unsigned short x);

#endif
