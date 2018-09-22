/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_flag_table.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 21:37:43 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/15 21:37:44 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_FLAG_TABLE_H
# define FT_LS_FLAG_TABLE_H

# define LS_FLAG_BIG_R		0x01
# define LS_FLAG_A			0x02
# define LS_FLAG_D			0x04
# define LS_FLAG_F			0x08
# define LS_FLAG_L			0x10
# define LS_FLAG_R			0x20
# define LS_FLAG_T			0x40
# define LS_FLAG_BIG_G		0x80
# define LS_FLAG_BIG_U		0x100
# define LS_FLAG_U			0x200
# define LS_FLAG_1			0x400
# define LS_FLAG_Y			0x800

static const uint16_t	g_flag_table[FT_ASCII_SIZE] =
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, LS_FLAG_1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, LS_FLAG_BIG_G, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, LS_FLAG_BIG_R, 0, 0, LS_FLAG_BIG_U, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, LS_FLAG_A, 0, 0, LS_FLAG_D, 0, LS_FLAG_F, 0, 0,
	0, 0, 0, LS_FLAG_L, 0, 0, 0, 0, 0, LS_FLAG_R, 0, LS_FLAG_T, LS_FLAG_U, 0, 0,
	0, LS_FLAG_Y, 0, 0, 0, 0, 0, 0
};

#endif
