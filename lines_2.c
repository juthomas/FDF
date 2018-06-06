/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:18:55 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/06 14:24:50 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			by_color_2(t_var *var, t_line *line)
{
	int		color;
	int		c_max;
	int		c_min;
	int		l_max;
	int		l_min;

	color = 0;
	l_max = var->y1 - var->y2;
	l_min = var->y2;
	if (l_max == 0)
		l_max = 1;
	c_max = line->by_color1 - line->by_color2;
	c_min = line->by_color2;
	color = ((var->tmp_y - l_min) * (c_max) / l_max) + c_min;
	return (color);
}

int			by_color_1(t_var *var, t_line *line)
{
	int		color;
	int		c_max;
	int		c_min;
	int		l_max;
	int		l_min;

	color = 0;
	l_max = var->x1 - var->x2;
	if (l_max == 0)
		l_max = 1;
	l_min = var->x2;
	c_max = line->by_color1 - line->by_color2;
	c_min = line->by_color2;
	color = ((var->tmp_x - l_min) * (c_max) / l_max) + c_min;
	return (color);
}
