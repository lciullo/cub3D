/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_around.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:09:14 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/03 15:24:46 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_around(t_data *data, int y, int x, char **copy)
{
	if (check_up(data, y, x, copy) == FAILURE)
		return (FAILURE);
	if (check_down(data, y, x, copy) == FAILURE)
		return (FAILURE);
	if (check_left(y, x, copy) == FAILURE)
		return (FAILURE);
	if (check_right(data, y, x, copy) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	check_up(t_data *data, int y, int x, char **copy)
{
	if ((y <= 0) || (x > (data->len_line[y - 1] - 1)))
		return (FAILURE);
	if (copy[y - 1][x] == '1')
		return (3);
	if (copy[y - 1][x] != '0')
		return (FAILURE);
	return (SUCCESS);
}

int	check_down(t_data *data, int y, int x, char **copy)
{
	if (y >= (data->size_map - 1))
		return (FAILURE);
	if (x > (data->len_line[y + 1] - 1))
		return (FAILURE);
	if (copy[y + 1][x] == '1')
		return (3);
	if (copy[y + 1][x] != '0')
		return (FAILURE);
	return (SUCCESS);
}

int	check_left(int y, int x, char **copy)
{
	if (x <= 0)
		return (FAILURE);
	if (copy[y][x - 1] == '1')
		return (3);
	if (copy[y][x - 1] != '0')
		return (FAILURE);
	return (SUCCESS);
}

int	check_right(t_data *data, int y, int x, char **copy)
{
	if ((y <= 0) || (x >= (data->len_line[y] - 1)))
		return (FAILURE);
	if (copy[y][x + 1] == '1')
		return (3);
	if (copy[y][x + 1] != '0')
		return (FAILURE);
	return (SUCCESS);
}
