/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egunar <egunar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:41:25 by egunar            #+#    #+#             */
/*   Updated: 2022/03/14 17:18:57 by egunar           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = 0;
	free(s1);
	return (str);
}

char	*just_line(char *full_str)
{
	int		j;
	char	*str;

	j = 0;
	if (!full_str[j])
		return (NULL);
	while (full_str[j] && full_str[j] != '\n')
		j++;
	str = malloc(sizeof(char) * (j + 2));
	if (!str)
		return (NULL);
	j = 0;
	while (full_str[j] && full_str[j] != '\n')
	{
		str[j] = full_str[j];
		j++;
	}
	if (full_str[j] == '\n')
	{
		str[j] = full_str[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*destroy_before_nl(char *full_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (full_str[i] && full_str[i] != '\n')
		i++;
	if (!full_str[i])
	{
		free(full_str);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(full_str) - i + 1));
	if (!str)
		return (NULL);
	j = 0;
	i++;
	while (full_str[i])
		str[j++] = full_str[i++];
	str[j] = 0;
	free(full_str);
	return (str);
}
