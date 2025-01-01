/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfelix-d <vfelix-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:25:05 by vfelix-d          #+#    #+#             */
/*   Updated: 2025/01/01 19:19:18 by vfelix-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_and_return(char **buffer, char *ret)
{
	if (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (ret);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!to_find[0])
		return (str);
	while (str[i])
	{
		while (str[i + j] == to_find[j] && to_find[j])
			j++;
		if (!to_find[j])
			return (&str[i]);
		j = 0;
		i++;
	}
	return (NULL);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	i = 0;
	if (!src)
		return (NULL);
	dup = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
