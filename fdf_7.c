/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:36:52 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/11 14:14:41 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_grid_tmp2(t_tab *tmp, t_var *var, t_alg *alg)
{
	if (var->tmp2_y + 1 < var->y_max
			&& (var->tmp2_x < var->x_max[var->tmp2_y + 1]))
	{
		tmp = var->px[var->tmp2_y + 1][var->tmp2_x];
		var->x2 = ((float)tmp->x * (float)var->modif_zoom +
				(float)var->modif_x + (float)var->modif_persp *
				(float)tmp->y / 10);
		var->y2 = ((float)tmp->y * (float)var->modif_zoom +
				(float)tmp->z * (float)var->modif_z / 40 *
				(float)var->modif_zoom +
				(float)var->modif_y);
		if (tmp->z == 0 && var->blue_ocean == 1)
			var->color2 = 0x0000FF;
		else
			var->color2 = tmp->color;
		out_limit(var);
		lines_fonct(var, alg);
	}
}

void	print_grid(t_var *var)
{
	t_tab	*tab;
	t_tab	*tmp;
	t_alg	*alg;

	tab = NULL;
	tmp = NULL;
	alg = NULL;
	var->tmp_y = 0;
	var->tmp2_y = 0;
	alg = (t_alg*)malloc(sizeof(*alg));
	while (var->tmp2_y < var->y_max)
	{
		var->tmp2_x = 0;
		while (var->tmp2_x < var->x_max[var->tmp2_y])
		{
			print_grid_tab(tab, var);
			if (var->tmp2_x + 1 < var->x_max[var->tmp2_y])
				print_grid_tmp1(tmp, var, alg);
			print_grid_tmp2(tmp, var, alg);
			var->tmp2_x++;
		}
		var->tmp2_y++;
	}
	free(alg);
}

void	*modify_px(void *px, t_tab *tab)
{
	px = create_tab(tab->x, tab->y, tab->z, tab->color);
	return (px);
}

void	new_pixel(t_var *var)
{
	t_tab	*tab;

	var->tmp_y = 0;
	while (var->tmp_y < var->y_max)
	{
		var->tmp_x = 0;
		while (var->tmp_x < var->x_max[var->tmp_y])
		{
			tab = var->list_tab[var->tmp_y][var->tmp_x];
			var->px[var->tmp_y][var->tmp_x] = modify_px(
					var->px[var->tmp_y][var->tmp_x], tab);
			var->tmp_x++;
		}
		var->tmp_y++;
	}
}

void	appli_patch_color(t_var *var)
{
	t_tab	*tab;

	var->tmp_y = 0;
	while (var->tmp_y < var->y_max)
	{
		var->tmp_x = 0;
		while (var->tmp_x < var->x_max[var->tmp_y])
		{
			tab = var->list_tab[var->tmp_y][var->tmp_x];
			if (tab->color == 0XFC000000)
				tab->color = color_by_z(var, tab);
			var->tmp_x++;
		}
		var->tmp_y++;
	}
}
