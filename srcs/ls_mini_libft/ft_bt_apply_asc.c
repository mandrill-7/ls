/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_apply_asc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 22:12:30 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/15 22:12:31 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_bt_apply_asc(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		ft_bt_apply_asc(root->left, applyf);
		applyf(root->item);
		ft_bt_apply_asc(root->right, applyf);
	}
}
