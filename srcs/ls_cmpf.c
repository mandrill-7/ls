/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_cmpf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 21:54:50 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/16 13:46:18 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_notsorted(t_finfo *data_ref, t_finfo *item)
{
	(void)data_ref;
	(void)item;
	return (1);
}

int		ls_asciicmp(t_finfo *data_ref, t_finfo *item)
{
	return (ft_strcmp(data_ref->name, item->name));
}

int		ls_mtimecmp(t_finfo *data_ref, t_finfo *item)
{
	if (data_ref->stat.st_mtimespec.tv_sec == item->stat.st_mtimespec.tv_sec)
	{
		if (data_ref->stat.st_mtimespec.tv_nsec == \
				item->stat.st_mtimespec.tv_nsec)
			return (ft_strcmp(data_ref->name, item->name));
		if (data_ref->stat.st_mtimespec.tv_nsec > \
				item->stat.st_mtimespec.tv_nsec)
			return (-1);
	}
	else if (data_ref->stat.st_mtimespec.tv_sec > \
			item->stat.st_mtimespec.tv_sec)
		return (-1);
	return (1);
}

int		ls_atimecmp(t_finfo *data_ref, t_finfo *item)
{
	if (data_ref->stat.st_atimespec.tv_sec == item->stat.st_atimespec.tv_sec)
	{
		if (data_ref->stat.st_atimespec.tv_nsec == \
				item->stat.st_atimespec.tv_nsec)
			return (ft_strcmp(data_ref->name, item->name));
		if (data_ref->stat.st_atimespec.tv_nsec > \
				item->stat.st_atimespec.tv_nsec)
			return (-1);
	}
	else if (data_ref->stat.st_atimespec.tv_sec > \
			item->stat.st_atimespec.tv_sec)
		return (-1);
	return (1);
}

int		ls_birthtimecmp(t_finfo *data_ref, t_finfo *item)
{
	if (data_ref->stat.st_birthtimespec.tv_sec == \
			item->stat.st_birthtimespec.tv_sec)
	{
		if (data_ref->stat.st_birthtimespec.tv_nsec == \
				item->stat.st_birthtimespec.tv_nsec)
			return (ft_strcmp(data_ref->name, item->name));
		if (data_ref->stat.st_birthtimespec.tv_nsec > \
				item->stat.st_birthtimespec.tv_nsec)
			return (-1);
	}
	else if (data_ref->stat.st_birthtimespec.tv_sec > \
			item->stat.st_birthtimespec.tv_sec)
		return (-1);
	return (1);
}
