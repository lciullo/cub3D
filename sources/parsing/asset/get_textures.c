/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:17:32 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/03 11:28:14 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	get_texture(char *line);
static int	len_of_texture_line(char *s);
static char	*copy_texture(char *texture, char *s);
static	int	find_texture(char *line, t_parsing *utils);

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
		if (find_texture(line, utils) == FAILURE)
		{
			free(line);
			return (FAILURE);
		}
		free(line);
	}
	close(fd);
	return (SUCCESS);
}

static	int	find_texture(char *line, t_parsing *utils)
{
	if (ft_strchr(line, 'W') && ft_strchr(line, 'E'))
	{
		get_texture(line);
		utils->west++;
	}
	else if (ft_strchr(line, 'N') && ft_strchr(line, 'O'))
	{
		get_texture(line);
		utils->north++;
	}
	else if (ft_strchr(line, 'S') && ft_strchr(line, 'O'))
	{
		get_texture(line);
		utils->south++;
	}
	else if (ft_strchr(line, 'E') && ft_strchr(line, 'A'))
	{
		get_texture(line);
		utils->east++;
	}
	return (SUCCESS);
}

static void	get_texture(char *s)
{
	char	*texture;

	texture = malloc(sizeof(char) * (len_of_texture_line(s) + 1));
	if (!texture)
		return ;
	texture = copy_texture(texture, s);
	ft_dprintf(1, "texture %s\n", texture);
	free(texture);
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

