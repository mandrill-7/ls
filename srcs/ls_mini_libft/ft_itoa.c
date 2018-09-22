/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:15:50 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/17 13:47:43 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*str;
	unsigned	cp;
	int			len;

	len = 1;
	if (n < 0)
	{
		++len;
		n *= -1;
	}
	cp = n;
	while ((n /= 10))
		++len;
	if (!(str = (char *)malloc(len + 1)))
		return (NULL);
	str[len--] = 0;
	while (1)
	{
		str[len--] = ((cp % 10) + 48);
		if (!(cp /= 10))
			break ;
	}
	if (len == 0)
		*str = '-';
	return (str);
}
