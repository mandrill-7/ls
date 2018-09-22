/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_disp_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 22:00:06 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/17 14:26:32 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ls_disp_y(t_finfo *finfo)
{
	if (finfo->name[0] == '.')
		ft_putendl(finfo->name);
}

void			ls_disp_line(t_finfo *finfo)
{
	ft_putendl(finfo->name);
}

void			ls_disp_col(t_finfo *finfo)
{
	g_ls_env.width.total_width += g_ls_env.width.width_max + 1;
	if ((g_ls_env.width.total_width + g_ls_env.width.width_max) \
			>= g_ls_env.width.win_width)
	{
		g_ls_env.width.total_width = 0;
		write(1, "\n", 1);
	}
	if (--g_ls_env.width.f_nb)
		ft_printf("%-*s ", g_ls_env.width.width_max, finfo->name);
	else
		ft_putendl(finfo->name);
}
