/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_asset_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:38:08 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/19 10:38:48 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
