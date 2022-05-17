/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egunar <egunar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:22:54 by egunar            #+#    #+#             */
/*   Updated: 2022/03/14 17:10:19 by egunar           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../push_swap.h"

void	move_checker(t_ps *ps, int op)
{
	if (op == O_SA)
		sx(ps->a);
	else if (op == O_SB)
		sx(ps->b);
	else if (op == O_SS)
		ss(ps);
	else if (op == O_PA)
		pa(ps);
	else if (op == O_PB)
		pb(ps);
	else if (op == O_RA)
		rx(ps->a);
	else if (op == O_RB)
		rx(ps->b);
	else if (op == O_RR)
		rr(ps);
	else if (op == O_RRA)
		rrx(ps->a);
	else if (op == O_RRB)
		rrx(ps->b);
	else if (op == O_RRR)
		rrr(ps);
}

void	checker(t_ps *ps)
{
	char		*line;
	const char	*op[12] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n",
		"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n", NULL};
	int			i;

	line = get_next_line(0);
	while (line)
	{
		i = 0;
		while (op[i] && ft_strncmp(op[i], line, ft_strlen(op[i]) + 1))
			i++;
		if (i == 11)
		{
			free(line);
			error_exit(ps);
		}
		else
			move_checker(ps, i);
		line = get_next_line(0);
	}
	if (!ps->b->size && check_sorted(ps->a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_ps	*ps;
	char	**args;

	if (argc < 2)
		return (0);
	a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	ps = (t_ps *)ft_calloc(1, sizeof(t_ps));
	ps->a = a;
	ps->b = b;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		parse_arg(ps, args, argc);
	}
	else if (argc > 2)
		parse_arg(ps, argv, argc);
	check_dup(ps);
	ps->size = a->size;
	ps->is_chk = 1;
	checker(ps);
	return (free_all(ps));
}
