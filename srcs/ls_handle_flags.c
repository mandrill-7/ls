/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_handle_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 21:46:16 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/18 14:21:07 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_hf1(void)
{
	if (g_ls_env.flags & LS_FLAG_F)
	{
		g_ls_env.flags |= LS_FLAG_A;
		g_ls_env.cmpf = &ls_notsorted;
		g_ls_env.disp_tree = &ft_bt_apply_asc;
	}
	else
	{
		if (g_ls_env.flags & LS_FLAG_T)
		{
			if (g_ls_env.flags & LS_FLAG_U)
				g_ls_env.cmpf = &ls_atimecmp;
			else if (g_ls_env.flags & LS_FLAG_BIG_U)
				g_ls_env.cmpf = &ls_birthtimecmp;
			else
				g_ls_env.cmpf = &ls_mtimecmp;
		}
		else
			g_ls_env.cmpf = &ls_asciicmp;
		if (g_ls_env.flags & LS_FLAG_R)
			g_ls_env.disp_tree = &ft_bt_apply_desc;
		else
			g_ls_env.disp_tree = &ft_bt_apply_asc;
	}
}

static void		ls_handle_win_size(void)
{
	struct winsize	ws;

	ioctl(1, TIOCGWINSZ, &ws);
	g_ls_env.width.win_width = ws.ws_col;
	if (g_ls_env.flags & LS_FLAG_BIG_G)
		g_ls_env.disp_elem = &ls_disp_col_color;
	else
		g_ls_env.disp_elem = &ls_disp_col;
}

static void		ls_hf2(void)
{
	if (g_ls_env.flags & LS_FLAG_Y)
	{
		if (g_ls_env.flags & LS_FLAG_BIG_G)
			g_ls_env.disp_elem = &ls_disp_y_color;
		else
			g_ls_env.disp_elem = &ls_disp_y;
	}
	else if (g_ls_env.flags & LS_FLAG_L)
	{
		if (g_ls_env.flags & LS_FLAG_BIG_G)
			g_ls_env.disp_elem = &ls_disp_l_color;
		else
			g_ls_env.disp_elem = &ls_disp_l;
	}
	else if (g_ls_env.flags & LS_FLAG_1)
	{
		if (g_ls_env.flags & LS_FLAG_BIG_G)
			g_ls_env.disp_elem = &ls_disp_line_color;
		else
			g_ls_env.disp_elem = &ls_disp_line;
	}
	else
		ls_handle_win_size();
}

static void		ls_hf3(void)
{
	if ((g_ls_env.flags & LS_FLAG_A) && !(g_ls_env.flags & LS_FLAG_L) && \
			!(g_ls_env.flags & LS_FLAG_BIG_R))
		g_ls_env.parse_dir = &ls_parse_dir_a;
	else if ((g_ls_env.flags & LS_FLAG_L) && !(g_ls_env.flags & LS_FLAG_A) && \
			!(g_ls_env.flags & LS_FLAG_BIG_R))
		g_ls_env.parse_dir = &ls_parse_dir_l;
	else if ((g_ls_env.flags & LS_FLAG_BIG_R) && !(g_ls_env.flags & LS_FLAG_L) \
			&& !(g_ls_env.flags & LS_FLAG_A))
		g_ls_env.parse_dir = &ls_parse_dir_big_r;
	else if ((g_ls_env.flags & LS_FLAG_A) && (g_ls_env.flags & LS_FLAG_L) && \
			!(g_ls_env.flags & LS_FLAG_BIG_R))
		g_ls_env.parse_dir = &ls_parse_dir_a_l;
	else if ((g_ls_env.flags & LS_FLAG_A) && (g_ls_env.flags & LS_FLAG_BIG_R) \
			&& !(g_ls_env.flags & LS_FLAG_L))
		g_ls_env.parse_dir = &ls_parse_dir_a_big_r;
	else if ((g_ls_env.flags & LS_FLAG_L) && (g_ls_env.flags & LS_FLAG_BIG_R) \
			&& !(g_ls_env.flags & LS_FLAG_A))
		g_ls_env.parse_dir = &ls_parse_dir_l_big_r;
	else if ((g_ls_env.flags & LS_FLAG_L) && (g_ls_env.flags & LS_FLAG_BIG_R) \
			&& (g_ls_env.flags & LS_FLAG_A))
		g_ls_env.parse_dir = &ls_parse_dir_a_l_big_r;
	else
		g_ls_env.parse_dir = &ls_parse_dir;
}

void			ls_handle_flags(void)
{
	g_ls_env.flags |= LS_FLAG_BIG_G;
	if (g_ls_env.flags & LS_FLAG_Y)
	{
		g_ls_env.flags |= LS_FLAG_A | LS_FLAG_1;
		g_ls_env.flags &= ~LS_FLAG_L;
	}
	ls_hf1();
	ls_hf2();
	ls_hf3();
	if (g_ls_env.flags & LS_FLAG_A)
		g_ls_env.is_dir = &ls_is_dir_a;
	else
		g_ls_env.is_dir = &ls_is_dir;
}
