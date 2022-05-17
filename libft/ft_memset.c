/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egunar <egunar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:56:12 by egunar            #+#    #+#             */
/*   Updated: 2022/03/14 17:20:52 by egunar           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(unsigned char *)(b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
/*
#include <stdio.h>
int	main()
{
	//0001, 0100, 0101 , 0111
	int i[] = {1, 4, 5, 7, 9};
	ft_memset(i,0,8);
	for(int k = 0; k < 5; k++)
		printf("%d\n",i[k]);

}*/
