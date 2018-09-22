/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 22:05:28 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/17 20:25:21 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static bool		ls_parse_flags(const unsigned char *flag_string)
{
	while (*flag_string)
	{
		if (*flag_string > 127 || g_flag_table[*flag_string] == 0)
		{
			g_ls_env.flags = *flag_string;
			return (LS_INVALID_FLAG);
		}
		else
			g_ls_env.flags |= g_flag_table[*flag_string];
		++flag_string;
	}
	return (0);
}

bool			ls_get_flags(int argc, char **argv, int *arg_index)
{
	while (*arg_index < argc && argv[*arg_index][0] == '-')
	{
		if (argv[*arg_index][1] == '-')
		{
			if (argv[*arg_index][2] == '\0')
			{
				++(*arg_index);
				return (0);
			}
			else
			{
				g_ls_env.flags = argv[*arg_index][2];
				return (LS_INVALID_FLAG);
			}
		}
		else if (ls_parse_flags((const unsigned char *)&argv[*arg_index][1]) ==\
				LS_INVALID_FLAG)
			return (LS_INVALID_FLAG);
		++(*arg_index);
	}
	return (0);
}

static bool		ls_is_linkdir(const char *path)
{
	struct stat		s;

	stat(path, &s);
	return (S_ISDIR(s.st_mode));
}

void			ls_get_operand2(t_finfo *finfo, char **argv, int arg_index)
{
	size_t		tmp;

	finfo->path = ft_strdup(argv[arg_index]);
	finfo->name = finfo->path;
	if ((!(g_ls_env.flags & LS_FLAG_D) && S_ISDIR(finfo->stat.st_mode))\
			|| (S_ISLNK(finfo->stat.st_mode) && \
				!(g_ls_env.flags & LS_FLAG_L) && \
				ls_is_linkdir(argv[arg_index]) == true))
		ft_bt_insert_node(&g_ls_env.dir, finfo, (void *)g_ls_env.cmpf);
	else
	{
		if (g_ls_env.flags & LS_FLAG_L)
			ls_fill_linfo(finfo);
		else
		{
			if ((tmp = ft_strlen(finfo->name)) > \
					g_ls_env.width.width_max)
				g_ls_env.width.width_max = tmp;
			++g_ls_env.width.f_nb;
		}
		ft_bt_insert_node(&g_ls_env.file, finfo, (void *)g_ls_env.cmpf);
	}
}

void			ls_get_operand(int argc, char **argv, int arg_index)
{
	t_finfo			*finfo;

	ls_init_width_tools();
	if (arg_index == argc)
		argv[--arg_index] = ".";
	while (arg_index < argc)
	{
		if (!(finfo = (t_finfo *)malloc(sizeof(*finfo))))
			ls_exit_alloc_fail();
		finfo->linfo = NULL;
		if (lstat(argv[arg_index], &finfo->stat) == -1)
		{
			if (errno == ENOENT)
			{
				ft_bt_insert_node(&g_ls_env.error, argv[arg_index], \
						(void *)&ft_strcmp);
			}
			else
				perror("ft_ls");
			g_ls_env.ret = 1;
			free(finfo);
		}
		else
			ls_get_operand2(finfo, argv, arg_index);
		++arg_index;
	}
}
