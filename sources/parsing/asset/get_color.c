/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:13:38 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/08 20:30:40 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	convert_rgb_to_int(char *color, t_parsing *utils);
static int is_valid_color_format(char *color);

int	get_colors(t_parsing *utils, t_data *data)
{
	data->celling = convert_rgb_to_int(utils->color_c_path, utils);
	if (data->celling == FAILURE)
	{
		free_asset(utils);
		return (FAILURE);
	}
	data->floor = convert_rgb_to_int(utils->color_f_path, utils);
	if (data->floor == FAILURE)
	{	
		free_asset(utils);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int is_valid_color_format(char *color)
{
	int	i;
	int	comma;
	
	i = 0;
	comma = 0;
	while (color[i])
	{
		if (ft_isdigit(color[i]) == 0)
			return (FAILURE);
		if (color[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		return (FAILURE);
	return (SUCCESS);
}

static	int	convert_rgb_to_int(char *color, t_parsing *utils)
{
	int		r;
	int		g;
	int		b;
	int		res;
	char	**array;

	r = 0;
	g = 0;
	b = 0;
	res = 0;
	if (is_valid_color_format(color) == FAILURE)
	{
		ft_dprintf(2, "Error\nWrong color format\n");
		free_asset(utils);
		return (FAILURE);
	}
	array = ft_split(color, ',');
	if (!array)
	{
		ft_dprintf(2, "Error\nMalloc failed in convert rgb to int\n");
		free_asset(utils);
		return (FAILURE);
	}
	r = ft_atoi(array[0]);
	g = ft_atoi(array[1]);
	b = ft_atoi(array[2]);
	if ((r < 0) || (g < 0) || (b < 0) || (r > 255) || (g > 255) || (b > 255))
	{
		ft_dprintf(2, "Error\nAdd only interger from 0 to 255\n");
		secure_free_array(array, 4);
		free_asset(utils);
		return (FAILURE);
	}
	res = 256 * 256 * r + 256 * g + b;
	secure_free_array(array, 4);
	return (res);
}
