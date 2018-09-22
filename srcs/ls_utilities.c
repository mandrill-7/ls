/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 20:37:58 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/18 13:00:21 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_init_width_tools(void)
{
	g_ls_env.lwidth.nlnk_max = 0;
	g_ls_env.lwidth.pn_max = 0;
	g_ls_env.lwidth.gr_max = 0;
	g_ls_env.lwidth.sz_max = 0;
	g_ls_env.width.width_max = 0;
	g_ls_env.width.total_width = 0;
}

void	ls_handle_layout(const char *path)
{
	if (g_ls_env.newline == true)
		write(1, "\n", 1);
	else
		g_ls_env.newline = true;
	if (g_ls_env.dispname == true)
		ft_printf("%s:\n", path);
	else
		g_ls_env.dispname = true;
}

bool	ls_init_dir(DIR **dir, char *path)
{
	ls_init_width_tools();
	ls_handle_layout(path);
	if (!(*dir = opendir(path)))
	{
		if (errno == ENOMEM)
			ls_exit_alloc_fail();
		else
		{
			perror("ft_ls");
			return (true);
		}
	}
	return (false);
}

bool	ls_fill_finfo(t_finfo **new, struct dirent *sett, char *dir_path)
{
	if (!(*new = (t_finfo *)malloc(sizeof(**new))))
		ls_exit_alloc_fail();
	(*new)->linfo = NULL;
	if (ls_get_path(*new, dir_path, sett->d_name) == EXIT_FAILURE)
		ls_exit_alloc_fail();
	if (lstat((*new)->path, &(*new)->stat) == -1)
	{
		free((*new)->path);
		free(*new);
		perror("ft_ls");
		return (true);
	}
	return (false);
}
