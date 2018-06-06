/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:29:20 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/10 18:16:25 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	color_by_z(t_var *var, t_tab *tab)
{
	int				z_mid;
	unsigned int	color;

	z_mid = (var->z_max + var->z_min) / 2;
	color = 0;
	if (tab->z < z_mid)
	{
		color += by_color_z_1(var, tab, COL_2 & 0x0000FF, COL_1 & 0x0000FF);
		color += by_color_z_1(var, tab, COL_2 / 256 % 256, COL_1 / 256 % 256)
			* 256;
		color += by_color_z_1(var, tab, COL_2 / 256 / 256 % 256,
				COL_1 / 256 / 256 % 256) * 256 * 256;
	}
	else
	{
		color += by_color_z_2(var, tab, COL_3 % 256, COL_2 % 256);
		color += by_color_z_2(var, tab, COL_3 / 256 % 256, COL_2 / 256 % 256)
			* 256;
		color += by_color_z_2(var, tab, COL_3 / 256 / 256 % 256,
				COL_2 / 256 / 256 % 256) * 256 * 256;
	}
	return (color);
}

void			*create_tab(int x, int y, int z, unsigned int color)
{
	void	*ret;
	t_tab	*tab;

	tab = (t_tab*)malloc(sizeof(*tab));
	tab->x = x;
	tab->y = y;
	tab->z = z;
	tab->color = color;
	ret = tab;
	return (ret);
}

void			create_points_part_2(t_var *var)
{
	var->i = 0;
	var->state = 1;
	if ((var->color = is_color(var->line)) != 0XFC000000)
		var->state = 2;
	while (((var->line[var->i] < '0' || var->line[var->i] > '9') &&
				!(var->line[var->i] == '-' && (var->line[var->i + 1] >= '0'
						&& var->line[var->i + 1] <= '9')))
			&& var->line[var->i] != '\0')
		var->i++;
	var->line = &var->line[var->i];
	if (var->z_min == 2147483647 || var->z_min > ft_atoi(var->line))
		var->z_min = ft_atoi(var->line);
	if (var->z_max == 2147483647 || var->z_max < ft_atoi(var->line))
		var->z_max = ft_atoi(var->line);
	var->list_tab[var->y][var->x] =
		create_tab(var->x, var->y, ft_atoi(var->line), var->color);
	if ((var->line = end_of_number(var->line)) == NULL)
		var->end_line = 0;
	var->x++;
}

void			create_points(t_var *var, char **argv)
{
	create_points_part_3(var, argv);
	var->x_max = (int*)malloc(sizeof(int) * (var->y_max + 1));
	var->list_tab = (void***)malloc(sizeof(void**) * (var->y_max + 1));
	var->y = 0;
	while ((var->ret_gnl = get_next_line(var->fd, &var->line)) == 1)
	{
		var->x_max[var->y] = get_x_of_file(var->line);
		var->list_tab[var->y] = (void**)malloc(sizeof(void*) *
				(var->x_max[var->y] + 1));
		var->end_line = 1;
		var->x = 0;
		while (var->x < var->x_max[var->y] && var->end_line)
			create_points_part_2(var);
		var->y++;
	}
}

void			create_pixel(t_var *var)
{
	var->y = 0;
	var->px = (void***)malloc(sizeof(void**) * (var->y_max + 1));
	while (var->y < var->y_max)
	{
		var->px[var->y] = (void**)malloc(sizeof(void*) *
				var->x_max[var->y] + 1);
		var->y++;
	}
}
