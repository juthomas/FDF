/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:10:25 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/11 14:18:17 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "get_next_line.h"
# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# define COL_1 0X001FA055
# define COL_2 0X00582900
# define COL_3 0X00FFFFFF
# define X_IMG 1400
# define Y_IMG 1400
# define X_WIN 1400
# define Y_WIN 1400

typedef struct		s_tab
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}					t_tab;

typedef struct		s_square
{
	int				x;
	int				y;
	int				hei;
	int				len;
	unsigned int	color;
}					t_square;

typedef struct		s_line
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	unsigned int	by_color1;
	unsigned int	by_color2;
	unsigned int	color1;
	unsigned int	color2;
	int				color_tmp;
	int				t;
	int				x;
}					t_line;

typedef struct		s_alg
{
	int				dx;
	int				dy;
	int				sy;
	int				sx;
	int				err;
	int				e2;
	int				abso;
}					t_alg;

typedef struct		s_var
{
	char			nothing;
	int				z_to_zero;
	int				modif_x;
	int				modif_y;
	float			modif_z;
	float			modif_zoom;
	int				modif_persp;
	short			blue_ocean;
	int				modif_zoom_0;
	float			modif_type;
	unsigned int	font_color;
	int				tmp_x;
	int				tmp_y;
	int				tmp2_x;
	int				tmp2_y;
	unsigned int	palet_color_1;
	unsigned int	palet_color_2;
	unsigned int	palet_color_3;
	int				z_min;
	int				z_max;
	int				fd;
	int				ret_gnl;
	char			*line;
	int				y;
	int				x;
	int				end_line;
	unsigned int	color;
	int				state;
	int				i;
	char			*addr;
	int				bpp;
	int				sizeline;
	int				endian;
	void			*mlx;
	void			*win;
	void			*img;
	long int		x1;
	long int		x2;
	long int		y1;
	long int		y2;
	unsigned int	color1;
	unsigned int	color2;
	void			***px;
	void			***list_tab;
	int				y_max;
	int				*x_max;
}					t_var;

void				print_legend(t_var *var);
void				create_points_part_3(t_var *var, char **argv);
void				out_limit(t_var *var);
void				setup_beg(t_var *var);
int					error_display(int msg);
unsigned int		is_color(char *str);
char				*end_of_number(char *str);
int					get_x_of_file(char *str);
unsigned int		by_color_z_2(t_var *var, t_tab *tab, int c1, int c2);
unsigned int		by_color_z_1(t_var *var, t_tab *tab, int c1, int c2);
unsigned int		color_by_z(t_var *var, t_tab *tab);
void				*create_tab(int x, int y, int z, unsigned int color);
void				create_points_part_2(t_var *var);
void				create_points(t_var *var, char **argv);
void				create_pixel(t_var *var);
void				image_put_int(unsigned int *addr, unsigned int img_color,
		t_var *var);
char				*reset_map(unsigned int color, t_var *var);
void				reset_modif(t_var *var);
void				new_windows(t_var *var);
void				free_t_var(t_var *var);
void				print_key_2(int keycode, t_var *var);
int					print_key(int keycode, void *param);
void				setup_lines_fonc(t_var *var, t_alg *alg);
void				lines_fonct(t_var *var, t_alg *alg);
void				print_grid_pers_tab(t_tab *tab, t_var *var);
void				print_grid_pers_tmp1(t_tab *tmp, t_var *var, t_alg *alg);
void				print_grid_pers_tmp2(t_tab *tmp, t_var *var, t_alg *alg);
void				print_grid_pers(t_var *var);
void				print_grid_tab(t_tab *tab, t_var *var);
void				print_grid_tmp1(t_tab *tab, t_var *var, t_alg *alg);
void				print_grid_tmp2(t_tab *tab, t_var *var, t_alg *alg);
void				print_grid(t_var *var);
void				*modify_px(void *px, t_tab *tab);
void				new_pixel(t_var *var);
void				appli_patch_color(t_var *var);
void				color_appli_1(t_var *var);
void				color_appli_2(t_var *var);
int					by_color_2(t_var *var, t_line *line);
int					by_color_1(t_var *var, t_line *line);
void				color_appli_2_1(t_var *var, t_line *line);
void				color_appli_1_1(t_var *var, t_line *line);
void				image_put_int(unsigned int *addr,
		unsigned int img_color, t_var *var);
#endif
