/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:49:31 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/11 10:25:46 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

static char	*ft_substr_b(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	i;
	size_t	k;

	if (ft_strlen(&s[start]) > len)
		new_s = malloc(sizeof(char) * (len + 1));
	else
		new_s = malloc(sizeof(char) * (ft_strlen(&s[start]) + 1));
	if (!(new_s))
		return (NULL);
	i = 0;
	k = 0;
	while (i < start)
		i++;
	while (s[i] && k < len)
	{
		new_s[k] = s[i];
		i++;
		k++;
	}
	new_s[k] = '\0';
	return (new_s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	new_s = ft_substr_b(s, start, len);
	return (new_s);
}
