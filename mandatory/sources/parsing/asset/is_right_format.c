/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_right_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:08:15 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/19 10:59:00 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_xpm_format(char *texture);

int	type_texture_check(t_parsing *utils, t_data *data)
{
	if ((check_xpm_format(data->path.north) == FAILURE) || \
		(check_xpm_format(data->path.south) == FAILURE) || \
		(check_xpm_format(data->path.west) == FAILURE) || \
		(check_xpm_format(data->path.east) == FAILURE))
	{
		free_asset(utils, data);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	check_xpm_format(char *texture)
{
	size_t	len;

	len = 0;
	if (!texture)
	{
		ft_dprintf(2, "Error\nCould not find texture\n");
		return (FAILURE);
	}
	if (texture)
		len = ft_strlen(texture);
	if (texture[len - 1] != 'm' || texture[len - 2] != 'p' \
		|| texture[len - 3] != 'x'\
		|| texture[len - 4] != '.')
	{
		ft_dprintf(2, "Error\nTexture name must be finished by .xpm\n");
		return (FAILURE);
	}
	return (SUCCESS);
}
