/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_error_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 22:05:12 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/17 20:25:10 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_exit_invalid_flag(void)
{
	ft_dprintf(2, "ft_ls: illegal option -- %c\nusage: ft_ls [-RalrtdfGuUy1] \
			[file ...]\n", g_ls_env.flags);
	exit(1);
}

void	ls_exit_alloc_fail(void)
{
	ft_dprintf(2, "ft_ls: Allocation failed\n");
	exit(1);
}

void	ls_put_invalid_path(const char *path)
{
	ft_dprintf(2, "ft_ls: %s: No such file or directory\n", path);
}
