/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_color_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 14:22:22 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/18 14:10:49 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_handle_major_disp_color2(t_finfo *finfo)
{
	if (S_IXUSR & finfo->stat.st_mode)
		ft_printf("{RED}%.10v%c %*hu %-*s  %-*s  %2hhu, %3hhu %.12v %s\n", \
				finfo->linfo->right_string, finfo->linfo->attr, \
				g_ls_env.lwidth.nlnk_max, \
				finfo->stat.st_nlink, g_ls_env.lwidth.pn_max, \
				finfo->linfo->uid_str, g_ls_env.lwidth.gr_max, \
				finfo->linfo->gid_str, LS_MAJOR(finfo->stat.st_rdev), \
				LS_MINOR(finfo->stat.st_rdev), finfo->linfo->time_string, \
				finfo->name);
	else
		ft_printf("{GREY}%.10v%c %*hu %-*s  %-*s  %2hhu, %3hhu %.12v %s\n", \
				finfo->linfo->right_string, finfo->linfo->attr, \
				g_ls_env.lwidth.nlnk_max, \
				finfo->stat.st_nlink, g_ls_env.lwidth.pn_max, \
				finfo->linfo->uid_str, g_ls_env.lwidth.gr_max, \
				finfo->linfo->gid_str, LS_MAJOR(finfo->stat.st_rdev), \
				LS_MINOR(finfo->stat.st_rdev), finfo->linfo->time_string, \
				finfo->name);
}

static void		ls_handle_major_disp_color(t_finfo *finfo)
{
	if (S_ISLNK(finfo->stat.st_mode))
	{
		ft_bzero(finfo->linfo->link, PATH_MAX);
		readlink(finfo->path, finfo->linfo->link, PATH_MAX);
		ft_printf("{GREEN}%.10v%c %*hu %-*s  %-*s  %2hhu, %3hhu %.12v %s \
				-> %s\n", finfo->linfo->right_string, finfo->linfo->attr, \
				g_ls_env.lwidth.nlnk_max, \
				finfo->stat.st_nlink, g_ls_env.lwidth.pn_max, \
				finfo->linfo->uid_str, g_ls_env.lwidth.gr_max, \
				finfo->linfo->gid_str, LS_MAJOR(finfo->stat.st_rdev), \
				LS_MINOR(finfo->stat.st_rdev), finfo->linfo->time_string, \
				finfo->name, finfo->linfo->link);
	}
	else if (S_ISDIR(finfo->stat.st_mode))
		ft_printf("{CYAN}%.10v%c %*hu %-*s  %-*s  %2hhu, %3hhu %.12v %s\n", \
				finfo->linfo->right_string, finfo->linfo->attr, \
				g_ls_env.lwidth.nlnk_max, \
				finfo->stat.st_nlink, g_ls_env.lwidth.pn_max, \
				finfo->linfo->uid_str, g_ls_env.lwidth.gr_max, \
				finfo->linfo->gid_str, LS_MAJOR(finfo->stat.st_rdev), \
				LS_MINOR(finfo->stat.st_rdev), finfo->linfo->time_string, \
				finfo->name);
	else
		ls_handle_major_disp_color2(finfo);
}

static void		ls_handle_class_disp_color2(t_finfo *finfo)
{
	if (S_IXUSR & finfo->stat.st_mode)
		ft_printf("{RED}%.10v%c %*hu %-*s  %-*s  %*llu %.12v %s\n", \
				finfo->linfo->right_string, finfo->linfo->attr, \
				g_ls_env.lwidth.nlnk_max, \
				finfo->stat.st_nlink, g_ls_env.lwidth.pn_max, \
				finfo->linfo->uid_str, g_ls_env.lwidth.gr_max, \
				finfo->linfo->gid_str, g_ls_env.lwidth.sz_max, \
				finfo->stat.st_size, finfo->linfo->time_string, \
				finfo->name);
	else
		ft_printf("{GREY}%.10v%c %*hu %-*s  %-*s  %*llu %.12v %s\n", \
				finfo->linfo->right_string, finfo->linfo->attr, \
				g_ls_env.lwidth.nlnk_max, \
				finfo->stat.st_nlink, g_ls_env.lwidth.pn_max, \
				finfo->linfo->uid_str, g_ls_env.lwidth.gr_max, \
				finfo->linfo->gid_str, g_ls_env.lwidth.sz_max, \
				finfo->stat.st_size, finfo->linfo->time_string, \
				finfo->name);
}

static void		ls_handle_class_disp_color(t_finfo *finfo)
{
	if (S_ISLNK(finfo->stat.st_mode))
	{
		ft_bzero(finfo->linfo->link, PATH_MAX);
		readlink(finfo->path, finfo->linfo->link, PATH_MAX);
		ft_printf("{GREEN}%.10v%c %*hu %-*s  %-*s  %*llu %.12v %s -> %s\n", \
				finfo->linfo->right_string, finfo->linfo->attr, \
				g_ls_env.lwidth.nlnk_max, \
				finfo->stat.st_nlink, g_ls_env.lwidth.pn_max, \
				finfo->linfo->uid_str, g_ls_env.lwidth.gr_max, \
				finfo->linfo->gid_str, g_ls_env.lwidth.sz_max, \
				finfo->stat.st_size, finfo->linfo->time_string, finfo->name, \
				finfo->linfo->link);
	}
	else if (S_ISDIR(finfo->stat.st_mode))
		ft_printf("{CYAN}%.10v%c %*hu %-*s  %-*s  %*llu %.12v %s\n", \
				finfo->linfo->right_string, finfo->linfo->attr, \
				g_ls_env.lwidth.nlnk_max, \
				finfo->stat.st_nlink, g_ls_env.lwidth.pn_max, \
				finfo->linfo->uid_str, g_ls_env.lwidth.gr_max, \
				finfo->linfo->gid_str, g_ls_env.lwidth.sz_max, \
				finfo->stat.st_size, finfo->linfo->time_string, \
				finfo->name);
	else
		ls_handle_class_disp_color2(finfo);
}

void			ls_disp_l_color(t_finfo *finfo)
{
	if (finfo->stat.st_rdev)
		ls_handle_major_disp_color(finfo);
	else
		ls_handle_class_disp_color(finfo);
}
