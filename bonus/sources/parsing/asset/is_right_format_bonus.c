/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_right_format_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:09:10 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/18 14:09:13 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_xpm_format(char *texture);

int	type_texture_check(t_parsing *utils, t_data *data)
{
	if ((check_xpm_format(data->north_path) == FAILURE) || \
		(check_xpm_format(data->south_path) == FAILURE) || \
		(check_xpm_format(data->west_path) == FAILURE) || \
		(check_xpm_format(data->east_path) == FAILURE))
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
