/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egunar <egunar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:23:42 by egunar            #+#    #+#             */
/*   Updated: 2022/01/12 20:37:50 by egunar           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

char	*oku_ve_al(int fd, char *full_str)
{
	char	*buff;
	int		read_buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_buff = 1;
	while (!(ft_strchr(full_str, '\n')) && read_buff != 0)
	{
		read_buff = read(fd, buff, BUFFER_SIZE);
		if (read_buff == -1)
		{
			free(full_str);
			free(buff);
			return (NULL);
		}
		buff[read_buff] = '\0';
		full_str = ft_strjoin(full_str, buff);
	}
	free(buff);
	return (full_str);
}

char	*get_next_line(int fd)
{
	static char	*full_str;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	full_str = oku_ve_al(fd, full_str);
	if (full_str == NULL)
		return (NULL);
	str = just_line(full_str);
	full_str = destroy_before_nl(full_str);
	return (str);
}
