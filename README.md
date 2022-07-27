# Openlibft
OpenLibft [C/ASM] (works on x86 only)

# Project
Here is the Openlibft mainly written in assembler in order to optimize the code and the ease for the dev !

✔️ = fully done<br>
❌ = not touched<br>
🚧 = work in progress<br>

![Olibft.png](olibft.png)

### Function list

|Fonctions			|is_done ?|is_documented ?|				reference ? 		   | 
|:------------------|:-------:|:-------------:|:----------------------------------:|
|ft_atoi			|✔️ (PART1)|      ✔️        | [ft_atoi](./src/utils/ft_atoi.asm) |
|ft_isalpha			|✔️ (PART1)|      ✔️        | [ft_isalpha](./src/strings/ft_isalpha.asm) |
|ft_isdigit			|✔️ (PART1)|      ✔️        | [ft_isdigit](./src/utils/ft_isdigit.asm) |
|ft_isalnum			|✔️ (PART1)|      ✔️        | [ft_isalnum](./src/utils/ft_isalnum.asm) |
|ft_isascii			|✔️ (PART1)|      ✔️        | [ft_isascii](./src/utils/ft_isascii.asm) |
|ft_isprint			|✔️ (PART1)|      ✔️        | [ft_isprint](./src/utils/ft_isprint.asm) |
|ft_tolower			|✔️ (PART1)|      ✔️        | [ft_tolower](./src/strings/ft_tolower.asm) |
|ft_toupper			|✔️ (PART1)|      ✔️        | [ft_toupper](./src/strings/ft_toupper.asm) |
|ft_write			|✔️ (SCALL)|      ✔️        | [ft_write](./src/syscalls/ft_write.asm) |
|ft_read			|✔️ (SCALL)|      ✔️        | [ft_read](./src/syscalls/ft_read.asm) |
|ft_open			|✔️ (SCALL)|      ✔️        | [ft_open](./src/syscalls/ft_open.asm) |
|ft_lseek			|✔️ (SCALL)|      ✔️        | [ft_lseek](./src/syscalls/ft_lseek.asm) |
|ft_chdir			|✔️ (SCALL)|      ✔️        | [ft_chdir](./src/syscalls/ft_chdir.asm) |
|ft_fork			|✔️ (SCALL)|      ✔️        | [ft_fork](./src/syscalls/ft_fork.asm) |
|ft_mmap			|✔️ (SCALL)|      ✔️        | [ft_mmap](./src/syscalls/ft_mmap.asm) |
|ft_munmap			|✔️ (SCALL)|      ✔️        | [ft_munmap](./src/syscalls/ft_munmap.asm) |
|ft_close			|✔️ (SCALL)|      ✔️        | [ft_close](./src/syscalls/ft_close.asm) |
|ft_exit			|✔️ (SCALL)|      ✔️        | [ft_exit](./src/syscalls/ft_exit.asm) |
|ft_dup				|✔️ (SCALL)|      ✔️        | [ft_dup](./src/syscalls/ft_dup.asm) |
|ft_dup2			|✔️ (SCALL)|      ✔️        | [ft_dup2](./src/syscalls/ft_dup2.asm) |
|ft_swap			|✔️ (UTILS)|      ✔️        | [ft_swap](./src/utils/ft_swap.asm) |
|ft_isblank			|✔️ (UTILS)|      ✔️        | [ft_isblank](./src/strings/ft_isblank.asm) |
|ft_isspace			|✔️ (UTILS)|      ✔️        | [ft_isspace](./src/strings/ft_isspace.asm) |
|ft_isxdigit		|✔️ (UTILS)|      ✔️        | [ft_isxdigit](./src/strings/ft_isxdigit.asm) |
|ft_isgraph			|✔️ (UTILS)|      ✔️        | [ft_isgraph](./src/strings/ft_isgraph.asm) |
|ft_iscntrl			|✔️ (UTILS)|      ✔️        |[ft_iscntrl](./src/strings/ft_iscntrl.asm) |
|ft_putchar			|✔️ (UTILS)|      ✔️        | [ft_putchar](./src/strings/ft_putchar.asm) |
|ft_strerror		|✔️ (PART2)|      ✔️        | [ft_strerror](./src/sys/ft_strerrno.asm) |

