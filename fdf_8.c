/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 14:14:59 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/11 14:19:50 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_legend(t_var *var)
{
	mlx_string_put(var->mlx, var->win, 10, 10, 0x00FFFFFF,
			"[W] or [S] to zoom or zoom out");
	mlx_string_put(var->mlx, var->win, 10, 25, 0x00FFFFFF,
			"[A] or [D] to rotate");
	mlx_string_put(var->mlx, var->win, 10, 40, 0x00FFFFFF,
			"[Q] or [E] to modify height");
	mlx_string_put(var->mlx, var->win, 10, 55, 0x00FFFFFF,
			"[Arrows] to move");
	mlx_string_put(var->mlx, var->win, 10, 80, 0x00FFFFFF,
			"[F] to reset map");
	mlx_string_put(var->mlx, var->win, 10, 95, 0x00FFFFFF,
			"[R] to set water level blue (IGN maps)");
	mlx_string_put(var->mlx, var->win, 10, 110, 0x00FFFFFF,
			"[T] or [G] to change background");
	mlx_string_put(var->mlx, var->win, 10, 125, 0x00FFFFFF,
			"[Y] to get a flat map");
	if (var->nothing)
	{
		mlx_string_put(var->mlx, var->win, 500, 550, 0x00FF0000,
			"NOTHING TO PUT-OUT");
		mlx_string_put(var->mlx, var->win, 501, 550, 0x00FF0000,
			"NOTHING TO PUT-OUT");
	}
}
