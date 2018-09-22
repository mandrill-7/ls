/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse_dir2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 16:58:32 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/18 11:56:26 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_parse_dir_a_l(t_finfo *finfo)
{
	DIR				*dir;
	struct dirent	*sett;
	t_btree			*root;
	t_finfo			*new;
	uint64_t		total;

	root = NULL;
	total = 0;
	if (ls_init_dir(&dir, finfo->path) == true)
		return ;
	while ((sett = readdir(dir)))
	{
		if (ls_fill_finfo(&new, sett, finfo->path) == true)
			continue ;
		ft_bt_insert_node(&root, new, (void *)g_ls_env.cmpf);
		total += new->stat.st_blocks;
		ls_fill_linfo(new);
	}
	closedir(dir);
	ft_printf("total %d\n", total);
	g_ls_env.disp_tree(root, (void *)g_ls_env.disp_elem);
	ft_bt_tree_del(&root, (void *)&ls_fdel);
}

void	ls_parse_dir_a_big_r(t_finfo *finfo)
{
	DIR				*dir;
	struct dirent	*sett;
	t_btree			*root;
	t_finfo			*new;
	size_t			tmp;

	root = NULL;
	if (ls_init_dir(&dir, finfo->path) == true)
		return ;
	while ((sett = readdir(dir)))
	{
		if (ls_fill_finfo(&new, sett, finfo->path) == true)
			continue ;
		ft_bt_insert_node(&root, new, (void *)g_ls_env.cmpf);
		if ((tmp = ft_strlen(new->name)) > g_ls_env.width.width_max)
			g_ls_env.width.width_max = tmp;
		++g_ls_env.width.f_nb;
	}
	closedir(dir);
	g_ls_env.disp_tree(root, (void *)g_ls_env.disp_elem);
	g_ls_env.disp_tree(root, (void *)g_ls_env.is_dir);
	ft_bt_tree_del(&root, (void *)&ls_fdel);
}

void	ls_parse_dir_l_big_r(t_finfo *finfo)
{
	DIR				*dir;
	struct dirent	*sett;
	t_btree			*root;
	t_finfo			*new;
	uint64_t		total;

	root = NULL;
	total = 0;
	if (ls_init_dir(&dir, finfo->path) == true)
		return ;
	while ((sett = readdir(dir)))
		if (sett->d_name[0] != '.')
		{
			if (ls_fill_finfo(&new, sett, finfo->path) == true)
				continue ;
			ft_bt_insert_node(&root, new, (void *)g_ls_env.cmpf);
			total += new->stat.st_blocks;
			ls_fill_linfo(new);
		}
	closedir(dir);
	ft_printf("total %d\n", total);
	g_ls_env.disp_tree(root, (void *)g_ls_env.disp_elem);
	g_ls_env.disp_tree(root, (void *)g_ls_env.is_dir);
	ft_bt_tree_del(&root, (void *)&ls_fdel);
}

void	ls_parse_dir_a_l_big_r(t_finfo *finfo)
{
	DIR				*dir;
	struct dirent	*sett;
	t_btree			*root;
	t_finfo			*new;
	uint64_t		total;

	root = NULL;
	total = 0;
	if (ls_init_dir(&dir, finfo->path) == true)
		return ;
	while ((sett = readdir(dir)))
	{
		if (ls_fill_finfo(&new, sett, finfo->path) == true)
			continue ;
		ft_bt_insert_node(&root, new, (void *)g_ls_env.cmpf);
		total += new->stat.st_blocks;
		ls_fill_linfo(new);
	}
	closedir(dir);
	ft_printf("total %d\n", total);
	g_ls_env.disp_tree(root, (void *)g_ls_env.disp_elem);
	g_ls_env.disp_tree(root, (void *)g_ls_env.is_dir);
	ft_bt_tree_del(&root, (void *)&ls_fdel);
}
