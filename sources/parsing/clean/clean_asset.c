/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_asset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:35:28 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/09 11:35:44 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_textures(t_parsing *utils)
{
	if (utils->north_path != NULL)
	{
		free(utils->north_path);
		utils->north_path = NULL;
	}
	if (utils->south_path != NULL)
	{
		free(utils->south_path);
		utils->south_path = NULL;
	}
	if (utils->east_path != NULL)
	{
		free(utils->east_path);
		utils->east_path = NULL;
	}
	if (utils->west_path != NULL)
	{
		free(utils->west_path);
		utils->west_path = NULL;
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

void	free_color_c_path(t_parsing *utils, char *texture)
{
	free_texture(texture);
	if (utils->color_f_path)
	{
		free(utils->color_f_path);
		utils->color_f_path = NULL;
	}
	free_textures(utils);
}

void	free_color_f_path(t_parsing *utils, char *texture)
{
	free_texture(texture);
	if (utils->color_c_path)
	{
		free(utils->color_c_path);
		utils->color_c_path = NULL;
	}
	free_textures(utils);
}

void	free_asset(t_parsing *utils)
{
	free_textures(utils);
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
