/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:17:32 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/03 15:38:50 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	get_texture(char *line, t_parsing *utils);
static int	len_of_texture_line(char *s);
static char	*copy_texture(char *texture, char *s);
static	int	find_asset(char *line, t_parsing *utils);
static	int	store_direction(char *texture, t_parsing *utils);
static int	get_color(char *s, t_parsing *utils);
static int	check_xpm_format(char *texture);

int	read_map_textures(char *path, t_data *data, t_parsing *utils)
{
	char	*line;
	int		fd;

	line = NULL;
	(void)data;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_dprintf(2, "Error\nThe file couldn't be opened\n"), FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (find_asset(line, utils) == FAILURE)
		{
			free(line);
			return (FAILURE);
		}
		free(line);
	}
	close(fd);
	return (SUCCESS);
}

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

	texture = malloc(sizeof(char) * (len_of_texture_line(s) + 1));
	if (!texture)
		return (FAILURE);
	texture = copy_texture(texture, s);
	store_direction(texture, utils);
	free(texture);
	return (SUCCESS);
}

static int	get_color(char *s, t_parsing *utils)
{
	char	*texture;

	texture = malloc(sizeof(char) * (len_of_texture_line(s) + 1));
	if (!texture)
		return (FAILURE);
	texture = copy_texture(texture, s);
	if (ft_strchr(s, 'C'))
		utils->color_c_path = ft_substr(texture, 1, ft_strlen(texture));
	if (ft_strchr(s, 'F'))
		utils->color_f_path = ft_substr(texture, 1, ft_strlen(texture));
	free(texture);
	return (SUCCESS);
}

static	int	store_direction(char *texture, t_parsing *utils)
{
	if (ft_strchr(texture, 'N'))
		utils->north_path = ft_substr(texture, 2, ft_strlen(texture));
	else if (ft_strchr(texture, 'S'))
		utils->south_path = ft_substr(texture, 2, ft_strlen(texture));
	else if (ft_strchr(texture, 'E'))
		utils->east_path = ft_substr(texture, 2, ft_strlen(texture));
	if (ft_strchr(texture, 'W'))
		utils->west_path = ft_substr(texture, 2, ft_strlen(texture));
	return (SUCCESS);
}

static char	*copy_texture(char *texture, char *s)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		if ((s[i] == ' ' || s[i] == '\t' || s[i] == '\v' || s[i] == '\r'))
			i++;
		else
		{
			texture[index] = s[i];
			index++;
			i++;
		}
	}
	texture[index] = '\0';
	return (texture);
}

static int	len_of_texture_line(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		if ((s[i] != '\0') && (s[i] == ' ' \
			|| s[i] == '\t' || s[i] == '\v' || s[i] == '\r'))
			i++;
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

