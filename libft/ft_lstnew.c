/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egunar <egunar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:24:26 by egunar            #+#    #+#             */
/*   Updated: 2022/03/14 17:20:39 by egunar           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	if (!ret)
		return ((void *)0);
	ret->content = content;
	ret->next = (void *)0;
	return (ret);
}
/*
#include <stdio.h>
int main()
{
	t_list *emre;

	emre = ft_lstnew("askldhf");
	printf("%s",emre->content);
}*/
