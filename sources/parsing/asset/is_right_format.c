/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_right_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:08:15 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/05 12:01:42 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_xpm_format(char *texture);

int	type_texture_check(t_parsing *utils)
{
	if ((check_xpm_format(utils->north_path) == FAILURE) || \
		(check_xpm_format(utils->south_path) == FAILURE) || \
		(check_xpm_format(utils->west_path) == FAILURE) || \
		(check_xpm_format(utils->east_path) == FAILURE))
	{
		ft_dprintf(2, "Error\nTexture must be on .xpm format\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	check_xpm_format(char *texture)
{
	size_t	len;

	len = 0;
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
