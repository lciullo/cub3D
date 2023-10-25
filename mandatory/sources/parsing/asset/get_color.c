/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:13:38 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/19 18:33:54 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	convert_rgb_to_int(char *color, t_parsing *utils, t_data *data);
static int	is_valid_color_format(char *color);
static int	get_res(t_parsing *utils, int res, char **array, t_data *data);

int	get_colors(t_parsing *utils, t_data *data)
{
	data->celling = convert_rgb_to_int(utils->color_c_path, utils, data);
	if (data->celling == ERROR)
	{
		free_asset(utils, data);
		return (ERROR);
	}
	data->floor = convert_rgb_to_int(utils->color_f_path, utils, data);
	if (data->floor == ERROR)
	{
		free_asset(utils, data);
		return (ERROR);
	}
	return (SUCCESS);
}

static int	is_valid_color_format(char *color)
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
		if (color[i] == ',' && ((color[i + 1] == ',') \
			|| (color[i + 1] == '\0')))
			return (FAILURE);
		i++;
	}
	if (comma != 2)
		return (FAILURE);
	return (SUCCESS);
}

static	int	convert_rgb_to_int(char *color, t_parsing *utils, t_data *data)
{
	int		res;
	char	**array;

	res = 0;
	if (!color)
		return (FAILURE);
	if (is_valid_color_format(color) == FAILURE)
	{
		ft_dprintf(2, "Error\nWrong color format usage : 0,0,0\n");
		free_asset(utils, data);
		return (ERROR);
	}
	array = ft_split(color, ',');
	if (!array)
	{
		ft_dprintf(2, "Error\nMalloc failed in convert rgb to int\n");
		free_asset(utils, data);
		return (ERROR);
	}
	res = get_res(utils, res, array, data);
	if (res == ERROR)
		return (ERROR);
	secure_free_array(array, 4);
	return (res);
}

static int	get_res(t_parsing *utils, int res, char **array, t_data *data)
{
	int	i;

	i = 0;
	utils->r = ft_atoi(array[0]);
	utils->g = ft_atoi(array[1]);
	utils->b = ft_atoi(array[2]);
	if ((utils->r < 0) || (utils->g < 0) || (utils->b < 0) \
		|| (utils->r > 255) || (utils->g > 255) || (utils->b > 255))
	{
		ft_dprintf(2, "Error\nAdd only positif interger from 0 to 255\n");
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
		array = NULL;
		free_asset(utils, data);
		return (ERROR);
	}
	res = 256 * 256 * utils->r + 256 * utils->g + utils->b;
	return (res);
}
