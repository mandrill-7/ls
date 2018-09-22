/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 21:37:58 by fchanal           #+#    #+#             */
/*   Updated: 2017/06/18 13:01:23 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/ioctl.h>
# include <sys/xattr.h>
# include <sys/acl.h>

# include "libft.h"
# include "ft_printf.h"
# include "ft_ls_flag_table.h"

# define LS_MAJOR(dev) ((int32_t)(((u_int32_t)(dev) >> 24) & 0xff))
# define LS_MINOR(dev) ((int32_t)((dev) & 0xffffff))
# define LS_INVALID_FLAG	1

typedef struct s_linfo	t_linfo;
struct	s_linfo
{
	char				right_string[10];
	char				attr;
	struct passwd		*uid;
	char				*uid_str;
	struct group		*gid;
	char				*gid_str;
	struct timespec		t;
	time_t				actual_time;
	char				*time_string;
	char				link[PATH_MAX];
};

typedef struct s_finfo	t_finfo;
struct	s_finfo
{
	const char		*name;
	char			*path;
	struct stat		stat;
	t_linfo			*linfo;
};

typedef struct s_width	t_width;
struct	s_width
{
	size_t		width_max;
	size_t		f_nb;
	size_t		win_width;
	size_t		total_width;
};

typedef struct s_lwidth	t_lwidth;
struct	s_lwidth
{
	size_t		nlnk_max;
	size_t		pn_max;
	size_t		gr_max;
	size_t		sz_max;
};

typedef struct s_ls_env	t_ls_env;
struct	s_ls_env
{
	uint16_t	flags;
	t_btree		*file;
	t_btree		*dir;
	t_btree		*error;
	int			(*cmpf)(t_finfo *, t_finfo *);
	void		(*disp_tree)(t_btree *, void (*)(void *));
	void		(*disp_elem)(t_finfo *);
	void		(*parse_dir)(t_finfo *);
	void		(*is_dir)(t_finfo *);
	bool		dispname;
	bool		newline;
	t_width		width;
	t_lwidth	lwidth;
	bool		ret;
};

t_ls_env	g_ls_env;

bool	ls_fill_finfo(t_finfo **finfo, struct dirent *sett, char *dir_path);
bool	ls_init_dir(DIR **dir, char *path);
void	ls_handle_attr(char *path, char *attr);
void	ls_handle_flags(void);
void	ls_is_dir_a(t_finfo *finfo);
void	ls_is_dir(t_finfo *finfo);
bool	ls_get_path(t_finfo *finfo, const char *dirpath, const char *filename);
void	ls_is_dir(t_finfo *finfo);
void	ls_parse_dir(t_finfo *finfo);
void	ls_parse_dir_a(t_finfo *finfo);
void	ls_parse_dir_l(t_finfo *finfo);
void	ls_parse_dir_big_r(t_finfo *finfo);
void	ls_parse_dir_a_l(t_finfo *finfo);
void	ls_parse_dir_a_big_r(t_finfo *finfo);
void	ls_parse_dir_l_big_r(t_finfo *finfo);
void	ls_parse_dir_a_l_big_r(t_finfo *finfo);
void	ls_handle_layout(const char *path);
void	ls_init_width_tools(void);
void	ls_fill_linfo(t_finfo *item);
void	ls_get_right(char right_string[10], uint16_t right);
bool	ls_get_flags(int argc, char **argv, int *arg_index);
void	ls_get_operand(int argc, char **argv, int arg_index);
int		ls_atimecmp(t_finfo *data_ref, t_finfo *item);
int		ls_birthtimecmp(t_finfo *data_ref, t_finfo *item);
int		ls_mtimecmp(t_finfo *item, t_finfo *data_ref);
int		ls_asciicmp(t_finfo *item, t_finfo *data_ref);
int		ls_notsorted(t_finfo *data_ref, t_finfo *item);
void	ls_disp_y(t_finfo *finfo);
void	ls_disp_y_color(t_finfo *finfo);
void	ls_disp_line(t_finfo *finfo);
void	ls_disp_line_color(t_finfo *finfo);
void	ls_disp_col(t_finfo *finfo);
void	ls_disp_col_color(t_finfo *finfo);
void	ls_disp_l(t_finfo *finfo);
void	ls_disp_l_color(t_finfo *finfo);
void	ls_disp_dir(t_finfo *finfo);
void	ls_fdel(t_btree **node);
void	ls_exit_invalid_flag(void);
void	ls_put_invalid_path(const char *path);
void	ls_exit_alloc_fail(void);

#endif
