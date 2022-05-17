/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egunar <egunar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:24:28 by egunar            #+#    #+#             */
/*   Updated: 2022/03/14 17:16:18 by egunar           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char	f(unsigned int a, char c)
{
	c -=32;
	return(c);
}
#include <stdio.h>
int main()
{
	char *s;

	s = malloc(sizeof(char) * 6);
	s[0] = 'a';
	s[1] = 'h';
	s[2] = 'm';
	s[3] = 'e';
	s[4] = 't';
	s[5] = 0;
	printf("%s\n",s);
	s = ft_strmapi(s,f);
	printf("%s",s);
	
}*/
