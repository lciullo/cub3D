/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:56:52 by lciullo           #+#    #+#             */
/*   Updated: 2023/09/12 10:47:52 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	free_array(char **arr)
{
	size_t	row;

	row = 0;
	while (arr[row])
	{
		free(arr[row]);
		row++;
	}
	free(arr);
	arr = NULL;
	return ;
}

void	secure_free_array(char **arr, size_t line)
{
	size_t	row;

	row = 0;
	while (row < line)
	{
		free(arr[row]);
		row++;
	}
	if (line != 0)
		free(arr);
	return ;
}
