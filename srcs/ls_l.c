/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_l.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 22:09:01 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/18 14:10:51 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_handle_major_disp(t_finfo *finfo)
{
	if (S_ISLNK(finfo->stat.st_mode))
	{
		ft_bzero(finfo->linfo->link, PATH_MAX);
		readlink(finfo->path, finfo->linfo->link, PATH_MAX);
		ft_printf("%.10v%c %*hu %-*s  %-*s  %2hhu, %3hhu %.12v %s -> %s\n", \
				finfo->linfo->right_string, \
				finfo->linfo->attr, g_ls_env.lwidth.nlnk_max, \
				finfo->stat.st_nlink, g_ls_env.lwidth.pn_max, \
				finfo->linfo->uid_str, g_ls_env.lwidth.gr_max, \
				finfo->linfo->gid_str, LS_MAJOR(finfo->stat.st_rdev), \
				LS_MINOR(finfo->stat.st_rdev), finfo->linfo->time_string, \
				finfo->name, finfo->linfo->link);
	}
	else
		ft_printf("%.10v%c %*hu %-*s  %-*s  %2hhu, %3hhu %.12v %s\n", \
				finfo->linfo->right_string, \
				finfo->linfo->attr, g_ls_env.lwidth.nlnk_max, \
				finfo->stat.st_nlink, g_ls_env.lwidth.pn_max, \
				finfo->linfo->uid_str, g_ls_env.lwidth.gr_max, \
				finfo->linfo->gid_str, LS_MAJOR(finfo->stat.st_rdev), \
				LS_MINOR(finfo->stat.st_rdev), finfo->linfo->time_string, \
				finfo->name);
}

static void		ls_handle_class_disp(t_finfo *finfo)
{
	if (S_ISLNK(finfo->stat.st_mode))
	{
		ft_bzero(finfo->linfo->link, PATH_MAX);
		readlink(finfo->path, finfo->linfo->link, PATH_MAX);
		ft_printf("%.10v%c %*hu %-*s  %-*s  %*llu %.12v %s -> %s\n", \
				finfo->linfo->right_string, \
				finfo->linfo->attr, g_ls_env.lwidth.nlnk_max, \
				finfo->stat.st_nlink, g_ls_env.lwidth.pn_max, \
				finfo->linfo->uid_str, g_ls_env.lwidth.gr_max, \
				finfo->linfo->gid_str, g_ls_env.lwidth.sz_max, \
				finfo->stat.st_size, finfo->linfo->time_string, finfo->name, \
				finfo->linfo->link);
	}
	else
		ft_printf("%.10v%c %*hu %-*s  %-*s  %*llu %.12v %s\n", \
				finfo->linfo->right_string, \
				finfo->linfo->attr, g_ls_env.lwidth.nlnk_max, \
				finfo->stat.st_nlink, g_ls_env.lwidth.pn_max, \
				finfo->linfo->uid_str, g_ls_env.lwidth.gr_max, \
				finfo->linfo->gid_str, g_ls_env.lwidth.sz_max, \
				finfo->stat.st_size, finfo->linfo->time_string, \
				finfo->name);
}

void			ls_disp_l(t_finfo *finfo)
{
	if (finfo->stat.st_rdev)
		ls_handle_major_disp(finfo);
	else
		ls_handle_class_disp(finfo);
}

void			ls_get_right(char right_string[10], uint16_t right)
{
	if (S_ISREG(right))
		right_string[0] = '-';
	else if (S_ISDIR(right))
		right_string[0] = 'd';
	else if (S_ISLNK(right))
		right_string[0] = 'l';
	else if (S_ISCHR(right))
		right_string[0] = 'c';
	else if (S_ISBLK(right))
		right_string[0] = 'b';
	else if (S_ISSOCK(right))
		right_string[0] = 's';
	else if (S_ISFIFO(right))
		right_string[0] = 'p';
	else
		right_string[0] = '-';
	right_string[1] = (right & S_IRUSR) ? 'r' : '-';
	right_string[2] = (right & S_IWUSR) ? 'w' : '-';
	right_string[3] = (right & S_IXUSR) ? 'x' : '-';
	right_string[4] = (right & S_IRGRP) ? 'r' : '-';
	right_string[5] = (right & S_IWGRP) ? 'w' : '-';
	right_string[6] = (right & S_IXGRP) ? 'x' : '-';
	right_string[7] = (right & S_IROTH) ? 'r' : '-';
	right_string[8] = (right & S_IWOTH) ? 'w' : '-';
	right_string[9] = (right & S_IXOTH) ? 'x' : '-';
}

void			ls_handle_attr(char *path, char *attr)
{
	acl_t			acl;
	acl_entry_t		tmp;
	size_t			xattr;

	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &tmp) == -1)
		acl = NULL;
	xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (xattr)
		*attr = '@';
	else if (acl)
		*attr = '+';
	else
		*attr = ' ';
	acl_free(acl);
}
