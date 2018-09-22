/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_tree_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 22:12:40 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/15 22:12:42 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_bt_tree_del(t_btree **root, void (*del)(void **))
{
	if (*root)
	{
		ft_bt_tree_del(&(*root)->left, del);
		ft_bt_tree_del(&(*root)->right, del);
		del((void **)root);
	}
}
