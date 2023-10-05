/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:13:38 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/05 12:14:41 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	convert_rgb_to_int(char *color);

int	get_colors(t_parsing *utils, t_data *data)
{
	data->celling = convert_rgb_to_int(utils->color_c_path);
	if (data->celling == FAILURE)
		return (FAILURE);
	data->floor = convert_rgb_to_int(utils->color_f_path);
	if (data->floor == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static	int	convert_rgb_to_int(char *color)
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
	array = malloc(sizeof(char *) * (3 + 1));
	if (!array)
		return (FAILURE);
	array = ft_split(color, ',');
	if (!array)
		return (FAILURE);
	r = ft_atoi(array[0]);
	g = ft_atoi(array[1]);
	b = ft_atoi(array[2]);
	res = 256 * 256 * r + 256 * g + b;
	secure_free_array(array, 4);
	return (res);
}
