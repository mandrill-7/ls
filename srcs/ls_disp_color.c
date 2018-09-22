/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_disp_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:19:05 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/18 14:26:53 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_disp_line_color(t_finfo *finfo)
{
	if (S_ISDIR(finfo->stat.st_mode))
		ft_printf("%{CYAN}s\n", finfo->name);
	else if (S_ISLNK(finfo->stat.st_mode))
		ft_printf("%{GREEN}s\n", finfo->name);
	else if (S_IXUSR & finfo->stat.st_mode)
		ft_printf("%{RED}s\n", finfo->name);
	else
		ft_printf("%{GREY}s\n", finfo->name);
}

void	ls_disp_col_color(t_finfo *finfo)
{
	g_ls_env.width.total_width += g_ls_env.width.width_max + 7;
	if ((g_ls_env.width.total_width + g_ls_env.width.width_max) \
			>= g_ls_env.width.win_width)
	{
		g_ls_env.width.total_width = 0;
		write(1, "\n", 1);
	}
	if (--g_ls_env.width.f_nb)
	{
		if (S_ISDIR(finfo->stat.st_mode))
			ft_printf("%{CYAN}-*s ", g_ls_env.width.width_max, finfo->name);
		else if (S_ISLNK(finfo->stat.st_mode))
			ft_printf("%{GREEN}-*s ", g_ls_env.width.width_max, finfo->name);
		else if (S_IXUSR & finfo->stat.st_mode)
			ft_printf("%{RED}-*s ", g_ls_env.width.width_max, finfo->name);
		else
			ft_printf("%{GREY}-*s ", g_ls_env.width.width_max, finfo->name);
	}
	else
		ls_disp_line_color(finfo);
}

void	ls_disp_y_color(t_finfo *finfo)
{
	if (finfo->name[0] == '.')
		ls_disp_line_color(finfo);
}
