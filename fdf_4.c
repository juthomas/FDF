/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:29:59 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/11 14:02:52 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	image_put_int(unsigned int *addr, unsigned int img_color, t_var *var)
{
	if (var->tmp_x < X_IMG && var->tmp_y < Y_IMG
			&& var->tmp_x >= 0 && var->tmp_y > 0)
		addr[(var->tmp_y * var->sizeline + var->tmp_x * var->bpp / 8) / 4] =
			img_color;
}

char	*reset_map(unsigned int color, t_var *var)
{
	int		x;
	int		y;

	y = 0;
	while (y < Y_IMG)
	{
		x = 0;
		while (x < X_IMG)
		{
			var->tmp_x = x;
			var->tmp_y = y;
			image_put_int((unsigned int*)var->addr, color, var);
			x++;
		}
		y++;
	}
	return (var->addr);
}

void	reset_modif(t_var *var)
{
	int		i;
	int		u;

	var->modif_zoom_0 = 1;
	var->modif_x = 0;
	var->modif_y = 0;
	var->modif_z = -1;
	var->modif_zoom = var->modif_zoom_0;
	var->modif_persp = 3;
	var->blue_ocean = 0;
	var->modif_type = 0;
	var->font_color = 0x00000000;
	i = 0;
	u = 0;
	while (u < var->y_max)
		var->x_max[u] > i ? i = var->x_max[u++] : u++;
	while (i * var->modif_zoom_0 < X_IMG && var->y_max *
			var->modif_zoom_0 < Y_IMG)
		var->modif_zoom_0++;
	var->modif_zoom_0 > 1 ? var->modif_zoom_0-- : var->modif_zoom_0;
	var->modif_zoom = var->modif_zoom_0;
	var->modif_x = ((X_IMG - (i * var->modif_zoom_0)) / 2);
	var->modif_y = ((Y_IMG - (var->y_max * var->modif_zoom_0)) / 2);
}

void	new_windows(t_var *var)
{
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, X_WIN, Y_WIN, "Ferrum Filum");
	var->img = mlx_new_image(var->mlx, X_IMG, Y_IMG);
	var->addr = mlx_get_data_addr(var->img, &var->bpp,
			&var->sizeline, &var->endian);
}

void	free_t_var(t_var *var)
{
	int		i;

	i = 0;
	while (i < var->y_max)
	{
		free(var->px[i]);
		free(var->list_tab[i]);
		i++;
	}
	free(var->x_max);
	free(var->px);
	free(var->list_tab);
	free(var->line);
	free(var->addr);
	free(var->mlx);
	free(var->win);
	free(var->img);
	free(var);
}
