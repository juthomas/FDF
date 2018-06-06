/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:28:27 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/10 18:13:56 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	is_color(char *str)
{
	unsigned int	i;

	i = 0;
	while (((str[i] < '0' || str[i] > '9') && !(str[i] == '-' &&
					(str[i + 1] >= '0' && str[i + 1] <= '9')))
			&& str[i] != '\0')
		i++;
	while (((str[i] >= '0' && str[i] <= '9') || (str[i] == '-' &&
					(str[i + 1] >= '0' && str[i + 1] <= '9')))
			&& str[i] != '\0')
		i++;
	if (str[i] == ',' && str[i + 1] == '0' && str[i + 2] == 'x')
		return (ft_atoi_base(&str[i + 3], "0123456789ABCDEF"));
	else
		return (0XFC000000);
}

char			*end_of_number(char *str)
{
	unsigned int	i;

	i = 0;
	while (((str[i] < '0' || str[i] > '9') && !(str[i] == '-' &&
				(str[i + 1] >= '0' && str[i + 1] <= '9'))) && str[i] != '\0')
		i++;
	while (((str[i] >= '0' && str[i] <= '9') || (str[i] == '-' &&
				(str[i + 1] >= '0' && str[i + 1] <= '9'))) && str[i] != '\0')
		i++;
	if (str[i] == ',' && str[i + 1] == '0' && str[i + 2] == 'x')
	{
		i += 3;
		while ((str[i] >= '0' && str[i] <= '9')
				|| (str[i] >= 'A' && str[i] <= 'F'))
			i++;
	}
	while (((str[i] < '0' || str[i] > '9') && !(str[i] == '-' &&
				(str[i + 1] >= '0' && str[i + 1] <= '9'))) && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (NULL);
	else
		return (&str[i]);
}

int				get_x_of_file(char *str)
{
	int		len;
	char	*cpy;
	int		state;

	cpy = ft_strdup(str);
	len = 0;
	while (((str[len] < '0' || str[len] > '9') && !(str[len] == '-' &&
			(str[len + 1] >= '0' && str[len + 1] <= '9'))) && str[len] != '\0')
		len++;
	if ((cpy[len] >= '0' && cpy[len] <= '9') || (str[len] == '-' &&
				(str[len + 1] >= '0' && str[len + 1] <= '9')))
		len = 1;
	else
		len = 0;
	state = 1;
	if (is_color(cpy) != 0XFC000000)
		state = 2;
	while ((cpy = end_of_number(cpy)) != NULL)
	{
		state = 1 && len++;
		if (is_color(cpy) != 0XFC000000)
			state = 2;
	}
	free(cpy);
	return (len);
}

unsigned int	by_color_z_2(t_var *var, t_tab *tab, int c1, int c2)
{
	int		z_mid;
	int		c_max;
	int		c_min;
	int		l_max;
	int		l_min;

	z_mid = (var->z_max + var->z_min) / 2;
	l_max = var->z_max - z_mid;
	l_min = z_mid;
	c_max = c1 - c2;
	c_min = c2;
	if (var->blue_ocean == 1)
		c1 = 0x0000FF;
	else if (var->z_min != var->z_max)
		c1 = ((tab->z - l_min) * (c_max) / l_max) + c_min;
	else
		c1 = c2;
	return (c1);
}

unsigned int	by_color_z_1(t_var *var, t_tab *tab, int c1, int c2)
{
	int		z_mid;
	int		c_max;
	int		c_min;
	int		l_max;
	int		l_min;

	z_mid = (var->z_max + var->z_min) / 2;
	l_max = z_mid - var->z_min;
	l_min = var->z_min;
	c_max = c1 - c2;
	c_min = c2;
	c1 = ((tab->z - l_min) * (c_max) / l_max) + c_min;
	return (c1);
}
