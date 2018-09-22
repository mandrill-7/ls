/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_abs_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:13:39 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/17 11:58:15 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_get_abs_len(int n, int base)
{
	unsigned int	len;

	if (base <= 0)
		return (0);
	if (base == 1)
		return (n);
	len = 1;
	while ((n /= base))
		++len;
	return (len);
}
