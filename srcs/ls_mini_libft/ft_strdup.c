/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 23:33:57 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/15 22:13:06 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	const char		*ptr;
	char			*new;

	ptr = s;
	while (*ptr)
		ptr++;
	if (!(new = malloc(sizeof(char) * (ptr - s) + 1)))
		return (NULL);
	ptr = s;
	while ((*new++ = *s++))
		;
	return (new - (s - ptr));
}
