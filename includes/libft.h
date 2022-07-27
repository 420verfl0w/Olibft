/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:48:48 by stales            #+#    #+#             */
/*   Updated: 2022/07/27 14:05:23 by stales           ###   ########.fr       */
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

#endif
