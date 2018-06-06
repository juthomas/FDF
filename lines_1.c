/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:24:47 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/06 14:27:37 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			color_appli_2_1(t_var *var, t_line *line)
{
	if ((var->color1 % 256 < var->color2 % 256 && var->y1 < var->y2) ||
			(!(var->color1 % 256 < var->color2 % 256) && !(var->y1 < var->y2)))
		line->color_tmp += by_color_2(var, line);
	else
		line->color_tmp += by_color_2(var, line);
	line->by_color1 = var->color1 / 256 % 256;
	line->by_color2 = var->color2 / 256 % 256;
	if ((var->color1 / 256 % 256 < var->color2 / 256 % 256 &&
				var->y1 < var->y2) ||
			(!(var->color1 / 256 % 256 < var->color2 / 256 % 256) &&
			!(var->y1 < var->y2)))
		line->color_tmp += by_color_2(var, line) * 256;
	else
		line->color_tmp += by_color_2(var, line) * 256;
	line->by_color1 = var->color1 / 256 / 256 % 256;
	line->by_color2 = var->color2 / 256 / 256 % 256;
	if ((var->color1 / 256 / 256 % 256 < var->color2 / 256 / 256 % 256 &&
				var->y1 < var->y2) ||
			(!(var->color1 / 256 / 256 % 256 < var->color2 / 256 / 256 % 256)
			&& !(var->y1 < var->y2)))
		line->color_tmp += by_color_2(var, line) * 256 * 256;
	else
		line->color_tmp += by_color_2(var, line) * 256 * 256;
}

void			color_appli_2(t_var *var)
{
	t_line *line;

	line = (t_line*)malloc(sizeof(*line));
	line->by_color1 = 0;
	line->by_color2 = 0;
	line->color_tmp = 0;
	if (var->color1 == 0XFC000000)
		var->color1 = 0X00FFFF00;
	if (var->color2 == 0XFC000000)
		var->color2 = 0X00FFFF00;
	line->by_color1 = var->color1 % 256;
	line->by_color2 = var->color2 % 256;
	color_appli_2_1(var, line);
	image_put_int((unsigned int*)var->addr, line->color_tmp, var);
	free(line);
}

void			color_appli_1_1(t_var *var, t_line *line)
{
	if ((var->color1 % 256 < var->color2 % 256 && var->x1 < var->x2)
			|| (!(var->color1 % 256 < var->color2 % 256)
				&& !(var->x1 < var->x2)))
		line->color_tmp += by_color_1(var, line);
	else
		line->color_tmp += by_color_1(var, line);
	line->by_color1 = var->color1 / 256 % 256;
	line->by_color2 = var->color2 / 256 % 256;
	if ((var->color1 / 256 % 256 < var->color2 / 256 % 256 &&
				var->x1 < var->x2)
			|| (!(var->color1 / 256 % 256 < var->color2 / 256 % 256) &&
				!(var->x1 < var->x2)))
		line->color_tmp += by_color_1(var, line) * 256;
	else
		line->color_tmp += by_color_1(var, line) * 256;
	line->by_color1 = var->color1 / 256 / 256 % 256;
	line->by_color2 = var->color2 / 256 / 256 % 256;
	if ((var->color1 / 256 / 256 % 256 < var->color2 / 256 / 256 % 256 &&
				var->x1 < var->x2) || (!(var->color1 / 256 / 256 % 256 <
			var->color2 / 256 / 256 % 256) && !(var->x1 < var->x2)))
		line->color_tmp += by_color_1(var, line) * 256 * 256;
	else
		line->color_tmp += by_color_1(var, line) * 256 * 256;
}

void			color_appli_1(t_var *var)
{
	t_line *line;

	line = (t_line*)malloc(sizeof(*line));
	line->by_color1 = 0;
	line->by_color2 = 0;
	line->color_tmp = 0;
	if (var->color1 == 0XFC000000)
		var->color1 = 0X00FFFF00;
	if (var->color2 == 0XFC000000)
		var->color2 = 0X00FFFF00;
	line->by_color1 = var->color1 % 256;
	line->by_color2 = var->color2 % 256;
	color_appli_1_1(var, line);
	image_put_int((unsigned int*)var->addr, line->color_tmp, var);
	free(line);
}
