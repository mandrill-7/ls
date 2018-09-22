/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 22:02:02 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/17 20:25:08 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define LS_SIX_MONTH	15778800
#define LS_ROOT_VALUE	0x002F

bool		ls_get_path(t_finfo *new, const char *dirpath, const char *filename)
{
	size_t		dir_len;
	size_t		file_len;
	char		*newf_pos;
	bool		is_root;

	dir_len = ft_strlen(dirpath);
	file_len = ft_strlen(filename);
	is_root = (*(uint16_t *)dirpath == LS_ROOT_VALUE);
	if (!(new->path = (char *)malloc(dir_len + file_len + !is_root + 1)))
		return (EXIT_FAILURE);
	newf_pos = new->path + dir_len;
	ft_memcpy((void*)new->path, dirpath, dir_len);
	if (is_root == false)
		*newf_pos++ = '/';
	ft_memcpy(newf_pos, filename, file_len + 1);
	new->name = newf_pos;
	return (EXIT_SUCCESS);
}

void		ls_is_dir(t_finfo *item)
{
	if (S_ISDIR(item->stat.st_mode))
		g_ls_env.parse_dir(item);
}

void		ls_is_dir_a(t_finfo *item)
{
	uint32_t	*s;

	s = (uint32_t *)item->name;
	if (S_ISDIR(item->stat.st_mode) && ((*s & 0x0000FFFF) != 0x0000002E) \
			&& ((*s & 0x00FFFFFF) != 0x00002E2E))
		g_ls_env.parse_dir(item);
}

void		ls_handle_time(t_finfo *item)
{
	item->linfo->actual_time = time(&(item->linfo->actual_time));
	item->linfo->t = item->stat.st_mtimespec;
	item->linfo->time_string = ft_strdup(ctime(&(item->linfo->t.tv_sec)));
	item->linfo->time_string += 4;
	if (item->linfo->actual_time - item->linfo->t.tv_sec > LS_SIX_MONTH || \
			item->linfo->t.tv_sec - item->linfo->actual_time > 0)
		ft_memcpy(item->linfo->time_string + 7, \
				item->linfo->time_string + 15, 5);
}

void		ls_fill_linfo(t_finfo *item)
{
	size_t		tmp;

	if (!(item->linfo = (t_linfo *)malloc(sizeof(*item->linfo))))
		ls_exit_alloc_fail();
	ls_get_right(item->linfo->right_string, item->stat.st_mode);
	ls_handle_attr(item->path, &item->linfo->attr);
	ls_handle_time(item);
	if (!(item->linfo->uid = getpwuid(item->stat.st_uid)))
		item->linfo->uid_str = ft_itoa(item->stat.st_uid);
	else
		item->linfo->uid_str = item->linfo->uid->pw_name;
	if (!(item->linfo->gid = getgrgid(item->stat.st_gid)))
		item->linfo->gid_str = ft_itoa(item->stat.st_gid);
	else
		item->linfo->gid_str = item->linfo->gid->gr_name;
	if ((tmp = ft_get_abs_len(item->stat.st_nlink, 10)) \
			> g_ls_env.lwidth.nlnk_max)
		g_ls_env.lwidth.nlnk_max = tmp;
	if ((tmp = ft_strlen(item->linfo->uid_str)) > g_ls_env.lwidth.pn_max)
		g_ls_env.lwidth.pn_max = tmp;
	if ((tmp = ft_strlen(item->linfo->gid_str)) > g_ls_env.lwidth.gr_max)
		g_ls_env.lwidth.gr_max = tmp;
	if ((tmp = ft_get_abs_len(item->stat.st_size, 10)) > g_ls_env.lwidth.sz_max)
		g_ls_env.lwidth.sz_max = tmp;
}
