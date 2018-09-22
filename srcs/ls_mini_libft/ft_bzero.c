/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:41:45 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/15 22:12:43 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *m, size_t len)
{
	uint64_t	*long_word;

	while (len % 8)
	{
		*(uint8_t *)m++ = (uint8_t)0;
		--len;
	}
	if (len)
	{
		long_word = (uint64_t *)m;
		while (len)
		{
			*long_word++ = (uint64_t)0;
			len -= 8;
		}
	}
}
