/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arachda <arachda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:49:12 by arachda           #+#    #+#             */
/*   Updated: 2023/12/24 20:50:24 by arachda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *stash, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!stash)
	{
		stash = malloc(1);
		stash[0] = '\0';
	}
	if (!stash || !buffer)
		return (NULL);
	str = malloc(ft_strlen(stash) + ft_strlen(buffer) + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (stash[++i])
		str[i] = stash[i];
	while (buffer[j])
		str[i++] = buffer[j++];
	str[ft_strlen(stash) + ft_strlen(buffer)] = '\0';
	free(stash);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *) s + i);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *) s + i);
	return (NULL);
}

char	*ft_first(char *stash)
{
	int		i;
	char	*str;

	if (!*(stash))
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
		str = malloc(i + 1);
	else
		str = malloc(i + 2);
	if (!str)
		return (0);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		str[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		str[i++] = '\n';
	str[i] = 0;
	return (str);
}

char	*ft_save(char *stash)
{
	int		i;
	size_t	len;
	char	*str;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (0);
	}
	len = ft_strlen(stash);
	str = malloc (len - i + 1);
	if (!str)
		return (0);
	len = 0;
	i++;
	while (stash[i])
		str[len++] = stash[i++];
	str [len] = 0;
	free(stash);
	return (str);
}
