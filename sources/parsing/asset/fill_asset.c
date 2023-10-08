/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_asset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:17:32 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/08 12:33:31 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	get_texture(char *line, t_parsing *utils);
static	int	find_asset(char *line, t_parsing *utils);
static	int	store_direction(char *texture, t_parsing *utils);
static int	get_color(char *s, t_parsing *utils);

int	read_to_get_asset(char *path, t_parsing *utils)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open(path, O_RDONLY);
	if (fd == ERROR)
		return (ft_dprintf(2, "Error\nThe file couldn't be opened\n"), FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (find_asset(line, utils) == FAILURE)
		{
			clean_gnl(fd, line);
			return (FAILURE);
		}
		if (line)
			free(line);
	}
	clean_gnl(fd, line);
	return (SUCCESS);
}

static	int	find_asset(char *line, t_parsing *utils)
{
	if ((ft_strchr(line, 'W') && ft_strchr(line, 'E')) || \
		(ft_strchr(line, 'N') && ft_strchr(line, 'O')) || \
		(ft_strchr(line, 'S') && ft_strchr(line, 'O')) || \
		(ft_strchr(line, 'E') && ft_strchr(line, 'A')))
	{
		if (get_texture(line, utils) == FAILURE)	
			return (FAILURE);
	}
	else if (ft_strchr(line, 'C') || ft_strchr(line, 'F'))
	{
		if (get_color(line, utils) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

static int	get_texture(char *s, t_parsing *utils)
{
	char	*texture;

	texture = malloc(sizeof(char) * (asset_line_len(s) + 1));
	if (!texture)
	{
		ft_dprintf(2, "Error\nMalloc failed in get_texture\n");
		return (FAILURE);
	}
	texture = copy_asset(texture, s);
	if (store_direction(texture, utils) == FAILURE)
	{
		if (texture)
		{
			free(texture);
			texture = NULL;
		}
		ft_dprintf(2, "Error\nMalloc failed in store_texture\n");
		return (FAILURE);
	}
	if (texture)
	{
		free(texture);
		texture = NULL;
	}
	return (SUCCESS);
}

static int	get_color(char *s, t_parsing *utils)
{
	char	*texture;

	texture = malloc(sizeof(char) * (asset_line_len(s) + 1));
	if (!texture)
		return (FAILURE);
	texture = copy_asset(texture, s);
	if (ft_strchr(s, 'C'))
		utils->color_c_path = ft_substr(texture, 1, ft_strlen(texture));
	if (!utils->color_c_path)
	{
		free_color_c_path(utils, texture);
		return (FAILURE);
	}
	else if (ft_strchr(s, 'F'))
		utils->color_f_path = ft_substr(texture, 1, ft_strlen(texture));
	if (!utils->color_f_path)
	{
		free_color_f_path(utils, texture);
		return (FAILURE);
	}
	if (texture)
		free(texture);
	return (SUCCESS);
}

static	int	store_direction(char *texture, t_parsing *utils)
{
	if (texture && texture[0] == 'N')
	{
		utils->north_path = ft_substr(texture, 2, ft_strlen(texture));
		if (!utils->north_path)
				return (FAILURE);
	}
	if (texture && texture[0] == 'S')
	{
		utils->south_path = ft_substr(texture, 2, ft_strlen(texture));
		if (!utils->south_path)
			return (FAILURE);
	}
	if (texture && texture[0] == 'E')
	{
		utils->east_path = ft_substr(texture, 2, ft_strlen(texture));
		if (!utils->east_path)
			return (FAILURE);
	}
	if (texture && texture[0] == 'W')
	{
		utils->west_path = ft_substr(texture, 2, ft_strlen(texture));
		if (!utils->west_path)
			return (FAILURE);
	}
	return (SUCCESS);
}
