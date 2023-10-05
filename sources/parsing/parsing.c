/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:09:03 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/05 13:57:20 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	parse_map(char *path, t_parsing *utils, t_data *data);
static int	parse_file(char *file);
static int	parse_textures(char *path, t_data *data, t_parsing *utils);

int	parsing(char *file, t_data *data, t_parsing *utils)
{
	if (parse_file(file) == FAILURE)
		return (FAILURE);
	if (parse_textures(file, data, utils) == FAILURE)
		return (FAILURE);
	if (parse_map(file, utils, data) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static	int	parse_file(char *file)
{
	char	*line;

	line = NULL;
	if (type_file_check(file) == FAILURE)
		return (FAILURE);
	if (is_empty_map(file, line) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int	parse_textures(char *path, t_data *data, t_parsing *utils)
{
	if (is_right_asset_number(path, utils) == FAILURE)
		return (FAILURE);
	if (read_to_get_asset(path, utils) == FAILURE)
		return (FAILURE);
	if (type_texture_check(utils) == FAILURE)
		return (FAILURE);
	if (get_colors(utils, data) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int	parse_map(char *path, t_parsing *utils, t_data *data)
{
	char	*line;

	line = NULL;
	if (get_size_map(path, data, line) == FAILURE)
		return (FAILURE);
	if (fill_map(path, data, line) == FAILURE)
		return (FAILURE);
	if (fill_len_line_array(data) == FAILURE)
		return (FAILURE);
	if (is_one_player(data, utils) == FAILURE)
		return (FAILURE);
	get_pos(data);
	if (is_map_closed(data, utils) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}


