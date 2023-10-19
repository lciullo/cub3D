/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_parsing_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:35:28 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/19 10:58:58 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	free_textures(t_data *data)
{
	if (data->path.north != NULL)
	{
		free(data->path.north);
		data->path.north = NULL;
	}
	if (data->path.south != NULL)
	{
		free(data->path.south);
		data->path.south = NULL;
	}
	if (data->path.east != NULL)
	{
		free(data->path.east);
		data->path.east = NULL;
	}
	if (data->path.west != NULL)
	{
		free(data->path.west);
		data->path.west = NULL;
	}
}

void	free_texture(char *texture)
{
	if (texture)
	{
		free(texture);
		texture = NULL;
	}
}

void	free_all_colors(t_parsing *utils)
{
	if (utils->color_f_path)
	{
		free(utils->color_f_path);
		utils->color_f_path = NULL;
	}
	if (utils->color_c_path)
	{
		free(utils->color_c_path);
		utils->color_c_path = NULL;
	}
}

void	free_asset(t_parsing *utils, t_data *data)
{
	free_textures(data);
	if (utils->color_c_path)
	{
		free(utils->color_c_path);
		utils->color_c_path = NULL;
	}
	if (utils->color_f_path)
	{
		free(utils->color_f_path);
		utils->color_f_path = NULL;
	}
}

void	clean_gnl(int fd, char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
	if (fd > 2)
		close(fd);
}
