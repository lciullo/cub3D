/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:21:10 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/11 09:33:54 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	void	count_asset(char *line, t_parsing *utils);
static	int	check_count(t_parsing *utils);

int	is_right_asset_number(char *path, t_parsing *utils)
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
		count_asset(line, utils);
		if (line)
			free(line);
	}
	clean_gnl(fd, line);
	if (check_count(utils) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static	void	count_asset(char *line, t_parsing *utils)
{
	if (ft_strchr(line, 'W') && ft_strchr(line, 'E'))
		utils->west++;
	else if (ft_strchr(line, 'N') && ft_strchr(line, 'O'))
		utils->north++;
	else if (ft_strchr(line, 'S') && ft_strchr(line, 'O'))
		utils->south++;
	else if (ft_strchr(line, 'E') && ft_strchr(line, 'A'))
		utils->east++;
	else if (ft_strchr(line, 'C'))
		utils->c_color++;
	else if (ft_strchr(line, 'F'))
		utils->f_color++;
}

static int	check_count(t_parsing *utils)
{
	if ((utils->west != 1) || (utils->south != 1) \
		|| (utils->north != 1) || (utils->east != 1) \
		|| (utils->c_color != 1) || (utils->f_color != 1))
	{
		ft_dprintf(2, "Error\nWrong number of textures or color\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

char	*copy_asset(char *texture, char *s)
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

int	asset_line_len(char *s)
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
