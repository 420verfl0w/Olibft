/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_net.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:28:35 by stales            #+#    #+#             */
/*   Updated: 2022/07/28 18:43:43 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_NET_H
# define LIBFT_NET_H

//////////////////////////////////
//
//			INCLUDES
//
//////////////////////////////////

# include "libft.h"
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>

//////////////////////////////////
//
//			TYPEDEFS
//
//////////////////////////////////

typedef t_u16 t_port;

//////////////////////////////////
//
//			WEAK ALIAS
//
//////////////////////////////////

t_port __attribute__ ((weak, alias("ft_bswap_16"))) htons(t_u16 x);
t_u32  __attribute__ ((weak, alias("ft_bswap_32"))) htonl(t_u32 x);

#endif
