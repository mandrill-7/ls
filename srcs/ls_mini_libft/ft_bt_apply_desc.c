/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_apply_desc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 22:12:33 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/15 22:12:34 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_bt_apply_desc(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		ft_bt_apply_desc(root->right, applyf);
		applyf(root->item);
		ft_bt_apply_desc(root->left, applyf);
	}
}
