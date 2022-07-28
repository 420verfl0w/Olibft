/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_net.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:28:35 by stales            #+#    #+#             */
/*   Updated: 2022/07/28 19:56:54 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_NET_H
# define LIBFT_NET_H

//////////////////////////////////
//
//			INCLUDES
//
//////////////////////////////////

# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>

//////////////////////////////////
//
//			TYPEDEFS
//
//////////////////////////////////

typedef unsigned int	t_in_addr;
typedef unsigned short	t_port;

//////////////////////////////////
//
//			Network function
//
//////////////////////////////////

/* convert values between host and network byte order */

extern unsigned int		ft_htonl(unsigned int hostlong);
extern unsigned int		ft_ntohl(unsigned int netshort);
extern unsigned short	ft_htons(unsigned short hostshort);
extern unsigned short	ft_ntohs(unsigned short netshort);

#endif
