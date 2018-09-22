/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_insert_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 22:12:35 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/17 11:58:01 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bt_insert_node(t_btree **root, void *data_ref, \
		int (*cmpf)(void *, void *))
{
	if (!*root)
	{
		*root = ft_bt_new_node(data_ref);
		return ;
	}
	else if (cmpf(data_ref, (*root)->item) < 0)
		ft_bt_insert_node(&(*root)->left, data_ref, cmpf);
	else
		ft_bt_insert_node(&(*root)->right, data_ref, cmpf);
}
