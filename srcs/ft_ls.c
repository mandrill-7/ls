/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 21:44:18 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/18 14:20:33 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ls_fdel(t_btree **node)
{
	t_finfo		*finfo;

	finfo = (*node)->item;
	free((void *)finfo->path);
	if (finfo->linfo)
	{
		if (!finfo->linfo->uid)
			free((void *)finfo->linfo->uid_str);
		if (!finfo->linfo->gid)
			free((void *)finfo->linfo->gid_str);
		free((void *)(finfo->linfo->time_string - 4));
		free((void *)finfo->linfo);
	}
	free((*node)->item);
	free(*node);
}

static void		ls_init_ls_env(void)
{
	g_ls_env.ret = 0;
	g_ls_env.width.f_nb = 0;
	g_ls_env.flags = 0;
	g_ls_env.dispname = false;
	g_ls_env.newline = false;
	g_ls_env.file = NULL;
	g_ls_env.dir = NULL;
	g_ls_env.error = NULL;
	g_ls_env.cmpf = NULL;
	g_ls_env.disp_tree = NULL;
	g_ls_env.disp_elem = NULL;
}

int				main(int argc, char **argv)
{
	int		arg_index;

	ls_init_ls_env();
	arg_index = 1;
	if ((ls_get_flags(argc, argv, &arg_index)) == LS_INVALID_FLAG)
		ls_exit_invalid_flag();
	ls_handle_flags();
	ls_get_operand(argc, argv, arg_index);
	if (g_ls_env.file)
		g_ls_env.newline = true;
	if (g_ls_env.error || g_ls_env.file || (g_ls_env.dir && \
				(g_ls_env.dir->left || g_ls_env.dir->right)))
		g_ls_env.dispname = true;
	ft_bt_apply_asc(g_ls_env.error, (void *)&ls_put_invalid_path);
	ft_bt_tree_del(&g_ls_env.error, &ft_memdel);
	g_ls_env.disp_tree(g_ls_env.file, (void *)g_ls_env.disp_elem);
	ft_bt_tree_del(&g_ls_env.file, (void *)&ls_fdel);
	g_ls_env.disp_tree(g_ls_env.dir, (void *)g_ls_env.parse_dir);
	ft_bt_tree_del(&g_ls_env.dir, (void *)&ls_fdel);
	return (g_ls_env.ret);
}
