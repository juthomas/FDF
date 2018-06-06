/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:31:18 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/10 18:12:25 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_grid_pers_tmp1(t_tab *tmp, t_var *var, t_alg *alg)
{
	tmp = var->px[var->tmp2_y][var->tmp2_x + 1];
	var->x2 = ((float)tmp->x * (float)var->modif_zoom *
			(1.5 + (float)tmp->y / (float)var->y_max) / 1.5 +
			(float)var->modif_x + (float)var->modif_persp *
			(float)tmp->y / 10) * 0.75;
	var->y2 = ((float)tmp->y * (float)var->modif_zoom +
			(float)tmp->z * (float)var->modif_z / 40 *
			(float)var->modif_zoom + (float)var->modif_y) * 0.75;
	if (tmp->z == 0 && var->blue_ocean == 1)
		var->color2 = 0x0000FF;
	else
		var->color2 = tmp->color;
	out_limit(var);
	lines_fonct(var, alg);
}

void	print_grid_pers_tmp2(t_tab *tmp, t_var *var, t_alg *alg)
{
	if (var->tmp2_y + 1 < var->y_max
			&& (var->tmp2_x < var->x_max[var->tmp2_y + 1]))
	{
		tmp = var->px[var->tmp2_y + 1][var->tmp2_x];
		var->x2 = ((float)tmp->x * (float)var->modif_zoom *
				(1.5 + (float)tmp->y / (float)var->y_max) / 1.5 +
				(float)var->modif_x + (float)var->modif_persp *
				(float)tmp->y / 10) * 0.75;
		var->y2 = ((float)tmp->y * (float)var->modif_zoom +
				(float)tmp->z * (float)var->modif_z / 40 *
				(float)var->modif_zoom +
				(float)var->modif_y) * 0.75;
		if (tmp->z == 0 && var->blue_ocean == 1)
			var->color2 = 0x0000FF;
		else
			var->color2 = tmp->color;
		out_limit(var);
		lines_fonct(var, alg);
	}
}

void	print_grid_pers(t_var *var)
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
			print_grid_pers_tab(tab, var);
			if (var->tmp2_x + 1 < var->x_max[var->tmp2_y])
				print_grid_pers_tmp1(tmp, var, alg);
			print_grid_pers_tmp2(tmp, var, alg);
			var->tmp2_x++;
		}
		var->tmp2_y++;
	}
	free(alg);
}

void	print_grid_tab(t_tab *tab, t_var *var)
{
	tab = var->px[var->tmp2_y][var->tmp2_x];
	var->x1 = ((float)tab->x * (float)var->modif_zoom +
			(float)var->modif_x + (float)var->modif_persp *
			(float)tab->y / 10);
	var->y1 = ((float)tab->y * (float)var->modif_zoom +
			(float)tab->z * (float)var->modif_z / 40 *
			(float)var->modif_zoom + (float)var->modif_y);
	if (tab->z == 0 && var->blue_ocean == 1)
		var->color1 = 0x0000FF;
	else
		var->color1 = tab->color;
}

void	print_grid_tmp1(t_tab *tmp, t_var *var, t_alg *alg)
{
	tmp = var->px[var->tmp2_y][var->tmp2_x + 1];
	var->x2 = ((float)tmp->x * (float)var->modif_zoom +
			(float)var->modif_x + (float)var->modif_persp *
			(float)tmp->y / 10);
	var->y2 = ((float)tmp->y * (float)var->modif_zoom +
			(float)tmp->z * (float)var->modif_z / 40 *
			(float)var->modif_zoom + (float)var->modif_y);
	if (tmp->z == 0 && var->blue_ocean == 1)
		var->color2 = 0x0000FF;
	else
		var->color2 = tmp->color;
	out_limit(var);
	lines_fonct(var, alg);
}
