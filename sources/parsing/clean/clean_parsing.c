/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_asset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:35:28 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/17 16:05:38 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_textures(t_data *data)
{
	if (data->north_path != NULL)
	{
		free(data->north_path);
		data->north_path = NULL;
	}
	if (data->south_path != NULL)
	{
		free(data->south_path);
		data->south_path = NULL;
	}
	if (data->east_path != NULL)
	{
		free(data->east_path);
		data->east_path = NULL;
	}
	if (data->west_path != NULL)
	{
		free(data->west_path);
		data->west_path = NULL;
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
