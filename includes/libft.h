/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:48:48 by stales            #+#    #+#             */
/*   Updated: 2022/07/27 17:59:44 by maldavid         ###   ########.fr       */
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

const char		*ft_strerrno(int e);

# define FT_EPERM		0x1	/* Operation not permitted */
# define FT_ENOENT		0x2	/* No such file or directory */
# define FT_ESRCH		0x3	/* No such process */
# define FT_EINTR		0x4	/* Interrupted system call */
# define FT_EIO			0x5	/* Input/output error */
# define FT_ENXIO		0x6	/* No such device or address */
# define FT_E2BIG		0x7	/* Argument list too long */
# define FT_ENOEXEC		0x8	/* Exec format error */
# define FT_EBADF		0x9	/* Bad file descriptor */
# define FT_ECHILD		0xa	/* No child processes */
# define FT_EDEADLK		0xb	/* Resource deadlock avoided */
# define FT_ENOMEM		0xc	/* Cannot allocate memory */
# define FT_EACCES		0xd	/* Permission denied */
# define FT_EFAULT		0xe	/* Bad address */
# define FT_ENOTBLK		0xf	/* Block device required */
# define FT_EBUSY		0x10	/* Device or resource busy */
# define FT_EEXIST		0x11	/* File exists */
# define FT_EXDEV		0x12	/* Invalid cross-device link */
# define FT_ENODEV		0x13	/* No such device */
# define FT_ENOTDIR		0x14	/* Not a directory */
# define FT_EISDIR		0x15	/* Is a directory */
# define FT_EINVAL		0x16	/* Invalid argument */
# define FT_EMFILE		0x18	/* Too many open files */
# define FT_ENFILE		0x17	/* Too many open files in system */
# define FT_ENOTTY		0x19	/* Inappropriate ioctl for device */
# define FT_ETXTBSY		0x1a	/* Text file busy */
# define FT_EFBIG		0x1b	/* File too large */
# define FT_ENOSPC		0x1c	/* No space left on device */
# define FT_ESPIPE		0x1d	/* Illegal seek */
# define FT_EROFS		0x1e	/* Read-only file system */
# define FT_EMLINK		0x1f	/* Too many links */
# define FT_EPIPE		0x20	/* Broken pipe */
# define FT_EDOM		0x21	/* Numerical argument out of domain */
# define FT_ERANGE		0x22	/* Numerical result out of range */
# define FT_EAGAIN		0x23	/* Resource temporarily unavailable */
# define FT_EINPROGRESS		0x24	/* Operation now in progress */
# define FT_EALREADY		0x25	/* Operation already in progress */
# define FT_ENOTSOCK		0x26	/* Socket operation on non-socket */
# define FT_EMSGSIZE		0x28	/* Message too long */
# define FT_EPROTOTYPE		0x29	/* Protocol wrong type for socket */
# define FT_ENOPROTOOPT		0x2a	/* Protocol not available */
# define FT_EPROTONOSUPPORT		0x2b	/* Protocol not supported */
# define FT_ESOCKTNOSUPPORT		0x2c	/* Socket type not supported */
# define FT_EOPNOTSUPP			0x2d	/* Operation not supported */
# define FT_EPFNOSUPPORT		0x2e	/* Protocol family not supported */
# define FT_EAFNOSUPPORT		0x2f	/* Address family not supported by protocol */
# define FT_EADDRINUSE			0x30	/* Address already in use */
# define FT_EADDRNOTAVAIL		0x31	/* Cannot assign requested address */
# define FT_ENETDOWN		0x32	/* Network is down */
# define FT_ENETUNREACH		0x33	/* Network is unreachable */
# define FT_ENETRESET		0x34	/* Network dropped connection on reset */
# define FT_ECONNABORTED	0x35	/* Software caused connection abort */
# define FT_ECONNRESET		0x36	/* Connection reset by peer */
# define FT_ENOBUFS			0x37	/* No buffer space available */
# define FT_EISCONN			0x38	/* Transport endpoint is already connected */
# define FT_ENOTCONN		0x39	/* Transport endpoint is not connected */
# define FT_EDESTADDRREQ	0x27	/* Destination address required */
# define FT_ESHUTDOWN		0x3a	/* Cannot send after transport endpoint shutdown */
# define FT_ETOOMANYREFS	0x3b	/* Too many references: cannot splice */
# define FT_ETIMEDOUT		0x3c	/* Connection timed out */
# define FT_ECONNREFUSED	0x3d	/* Connection refused */
# define FT_ELOOP			0x3e	/* Too many levels of symbolic links */
# define FT_ENAMETOOLONG	0x3f	/* File name too long */
# define FT_EHOSTDOWN		0x40	/* Host is down */
# define FT_EHOSTUNREACH	0x41	/* No route to host */
# define FT_ENOTEMPTY		0x42	/* Directory not empty */
# define FT_EPROCLIM		0x43	/* Too many processes */
# define FT_EUSERS		0x44	/* Too many users */
# define FT_EDQUOT		0x45	/* Disk quota exceeded */
# define FT_ESTALE		0x46	/* Stale file handle */
# define FT_EREMOTE		0x47	/* Object is remote */
# define FT_EBADRPC		0x48	/* RPC struct is bad */
# define FT_ERPCMISMATCH		0x49	/* RPC version wrong */
# define FT_EPROGUNAVAIL		0x4a	/* RPC program not available */
# define FT_EPROGMISMATCH		0x4b	/* RPC program version wrong */
# define FT_EPROCUNAVAIL		0x4c	/* RPC bad procedure for program */
# define FT_ENOLCK		0x4d	/* No locks available */
# define FT_EFTYPE		0x4f	/* Inappropriate file type or format */
# define FT_EAUTH		0x50	/* Authentication error */
# define FT_ENEEDAUTH	0x51	/* Need authenticator */
# define FT_ENOSYS		0x4e	/* Function not implemented */
# define FT_ENOTSUP		0x76	/* Not supported */
# define FT_EILSEQ		0x6a	/* Invalid or incomplete multibyte or wide character */
# define FT_EBACKGROUND	0x64	/* Inappropriate operation for background process */
# define FT_EDIED		0x65	/* Translator died */
# define FT_ED			0x66	/* ? */
# define FT_EGREGIOUS	0x67	/* You really blew it this time */
# define FT_EIEIO		0x68	/* Computer bought the farm */
# define FT_EGRATUITOUS	0x69	/* Gratuitous error */
# define FT_EBADMSG		0x6b	/* Bad message */
# define FT_EIDRM		0x6c	/* Identifier removed */
# define FT_EMULTIHOP	0x6d	/* Multihop attempted */
# define FT_ENODATA		0x6e	/* No data available */
# define FT_ENOLINK		0x6f	/* Link has been severed */
# define FT_ENOMSG		0x70	/* No message of desired type */
# define FT_ENOSR		0x71	/* Out of streams resources */
# define FT_ENOSTR		0x72	/* Device not a stream */
# define FT_EOVERFLOW	0x73	/* Value too large for defined data type */
# define FT_EPROTO		0x74	/* Protocol error */
# define FT_ETIME		0x75	/* Timer expired */
# define FT_ECANCELED	0x77	/* Operation canceled */
# define FT_EOWNERDEAD	0x78	/* Owner died */
# define FT_ENOTRECOVERABLE		0x79	/* State not recoverable */

// src/sys/ft_errnotab.c
extern const char *g_errno_tab[103];

#endif
