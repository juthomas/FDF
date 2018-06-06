/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:30:37 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/11 14:19:25 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_key_2(int keycode, t_var *var)
{
	if (keycode == 16)
		var->modif_z = 0;
	else if (keycode == 3)
		reset_modif(var);
	else if (keycode == 126)
		var->modif_y += 10;
	else if (keycode == 125)
		var->modif_y -= 10;
	else if (keycode == 123)
		var->modif_x += 10;
	else if (keycode == 124)
		var->modif_x -= 10;
	else if (keycode == 13)
		var->modif_zoom += 0.3;
	else if (keycode == 1 && var->modif_zoom > 1)
		var->modif_zoom -= 0.3;
	else if (keycode == 0)
		var->modif_z += 0.3;
	else if (keycode == 2)
		var->modif_z -= 0.3;
	else if (keycode == 12)
		var->modif_persp--;
	else if (keycode == 14)
		var->modif_persp++;
}

int		print_key(int keycode, void *param)
{
	t_var *var;

	var = param;
	print_key_2(keycode, var);
	if (keycode == 15)
		var->blue_ocean = var->blue_ocean == 0 ? 1 : 0;
	if (keycode == 7)
		var->modif_type = var->modif_type == 0 ? 1 : 0;
	if (keycode == 17 && var->font_color < 0x00FFFFFF)
		var->font_color += 0x010101;
	if (keycode == 5 && var->font_color > 0X00000000)
		var->font_color -= 0x010101;
	if (keycode == 53)
	{
		free_t_var(var);
		exit(-1);
	}
	reset_map(var->font_color, var);
	if (var->modif_type == 1)
		print_grid_pers(var);
	else
		print_grid(var);
	mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
	print_legend(var);
	return (0);
}

void	setup_lines_fonc(t_var *var, t_alg *alg)
{
	alg->dx = var->x2 - var->x1 < 0 ? -(var->x2 - var->x1) : var->x2 - var->x1;
	alg->dy = var->y2 - var->y1 < 0 ? -(var->y2 - var->y1) : var->y2 - var->y1;
	alg->sx = var->x1 < var->x2 ? 1 : -1;
	alg->sy = var->y1 < var->y2 ? 1 : -1;
	alg->err = (alg->dx > alg->dy ? alg->dx : -alg->dy) / 2;
	alg->abso = labs(var->x1 - var->x2) > labs(var->y1 - var->y2);
	var->tmp_x = var->x1;
	var->tmp_y = var->y1;
}

void	lines_fonct(t_var *var, t_alg *alg)
{
	var->nothing = 0;
	setup_lines_fonc(var, alg);
	while (1)
	{
		if (alg->abso)
			color_appli_1(var);
		else
			color_appli_2(var);
		if (var->tmp_x == var->x2 && var->tmp_y == var->y2)
			break ;
		alg->e2 = alg->err;
		if (alg->e2 > -alg->dx)
		{
			alg->err -= alg->dy;
			var->tmp_x += alg->sx;
		}
		if (alg->e2 < alg->dy)
		{
			alg->err += alg->dx;
			var->tmp_y += alg->sy;
		}
	}
}

void	print_grid_pers_tab(t_tab *tab, t_var *var)
{
	tab = var->px[var->tmp2_y][var->tmp2_x];
	var->x1 = ((float)tab->x * (float)var->modif_zoom *
			(1.5 + (float)tab->y / (float)var->y_max) / 1.5 +
			(float)var->modif_x + (float)var->modif_persp *
			(float)tab->y / 10) * 0.75;
	var->y1 = ((float)tab->y * (float)var->modif_zoom +
			(float)tab->z * (float)var->modif_z / 40 *
			(float)var->modif_zoom + (float)var->modif_y) * 0.75;
	if (tab->z == 0 && var->blue_ocean == 1)
		var->color1 = 0x0000FF;
	else
		var->color1 = tab->color;
}
