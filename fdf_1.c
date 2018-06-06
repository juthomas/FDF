/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:53:57 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/11 14:13:32 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_points_part_3(t_var *var, char **argv)
{
	var->z_min = 2147483647;
	var->z_max = 2147483647;
	if ((var->ret_gnl = get_next_line(var->fd, &var->line)) <= 0)
	{
		free_t_var(var);
		exit(error_display(2));
	}
	free(var->line);
	var->y_max++;
	while ((var->ret_gnl = get_next_line(var->fd, &var->line)) == 1)
	{
		var->y_max++;
		free(var->line);
	}
	free(var->line);
	close(var->fd);
	if (var->ret_gnl == -1 || var->y_max == 0)
	{
		free_t_var(var);
		exit(error_display(1));
	}
	var->fd = open(argv[1], O_RDONLY);
}

void	out_limit(t_var *var)
{
	if (var->x1 < -2147483 || var->x1 > 2147483)
		var->x1 = 53687;
	if (var->x2 < -2147483 || var->x2 > 2147483)
		var->x2 = 53687;
	if (var->y1 < -2147483 || var->y1 > 2147483)
		var->y1 = 53687;
	if (var->y2 < -2147483 || var->y2 > 2147483)
		var->y2 = 53687;
}

void	setup_beg(t_var *var)
{
	var->palet_color_1 = COL_1;
	var->palet_color_2 = COL_2;
	var->palet_color_3 = COL_3;
	var->nothing = 1;
	var->ret_gnl = 1;
	var->y_max = 0;
}

int		error_display(int msg)
{
	if (msg == 2)
		ft_putstr_fd("Bad file or empty file \n", 2);
	else if (msg == 1)
		ft_putstr_fd("Unknow file \n", 2);
	ft_putstr_fd("usage : ./fdf target_file.fdf \n", 2);
	return (-1);
}

int		main(int argc, char **argv)
{
	t_var	*var;

	if (argc == 2)
	{
		var = (t_var*)malloc(sizeof(*var));
		setup_beg(var);
		if ((var->fd = open(argv[1], O_RDONLY)) <= 0)
			return (error_display(1));
		create_points(var, argv);
		create_pixel(var);
		appli_patch_color(var);
		new_pixel(var);
		new_windows(var);
		reset_modif(var);
		print_grid(var);
		mlx_hook(var->win, 2, 1, &print_key, var);
		mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
		print_legend(var);
		mlx_loop(var->mlx);
		free_t_var(var);
	}
	else
		error_display(0);
	return (0);
}
