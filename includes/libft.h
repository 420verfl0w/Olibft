/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:48:48 by stales            #+#    #+#             */
/*   Updated: 2022/07/27 00:44:48 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

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

#endif
