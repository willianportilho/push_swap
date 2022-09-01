/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:51:17 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/01 21:23:08 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_a(t_ps *ps)
{
	if (ps->a)
	{
		ps->aux = ps->a;
		while (ps->aux->next)
		{
			ft_printf("a: %d\n", ps->aux->content);
			ps->aux = ps->aux->next;
		}
		ft_printf("a: %d\n\n", ps->aux->content);
	}
}

void	print_b(t_ps *ps)
{
	if (ps->b)
	{
		ps->aux = ps->b;
		while (ps->aux->next)
		{
			ft_printf("b: %d\n", ps->aux->content);
			ps->aux = ps->aux->next;
		}
		ft_printf("b: %d\n\n", ps->aux->content);
	}
}

void	print_all(t_ps *ps)
{
	if (ps->all_op)
	{
		ps->aux_op = ps->all_op;
		while (ps->aux_op->next)
		{
			ft_printf("%s\n", ps->aux_op->content);
			ps->aux_op = ps->aux_op->next;
		}
		if (ps->aux_op->content)
			ft_printf("%s\n", ps->aux_op->content);
	}
}

void	print_block(t_ps *ps)
{
	if (ps->saved_blk)
	{
		ps->aux = ps->saved_blk;
		while (ps->aux->next)
		{
			ft_printf("block: %d\n", ps->aux->content);
			ps->aux = ps->aux->next;
		}
		ft_printf("block: %d\n", ps->aux->content);
	}
}

int	main(int argc, char *argv[])
{
	t_ps		ps;
	int			n;

	ps_init(argc, argv, &ps);
	ps_sort(&ps);
	n = ft_lstsize(ps.all_op);
	print_a(&ps);
	print_b(&ps);
	ft_printf("nº de operações: %d\n", n);
	clear(&ps);
}
