/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 00:47:19 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/05 03:49:17 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	higher_number(t_ps *ps)
{
	ps->aux = ps->b;
	ps->higher_n = ps->b->content;
	while (ps->aux)
	{
		if (ps->higher_n < ps->aux->content)
			ps->higher_n = ps->aux->content;
		ps->aux = ps->aux->next;
	}
}

void	send_to_a(t_ps *ps)
{
	int	size;
	int	half_stack;

	while (ps->b)
	{
		higher_number(ps);
		ps->aux = ps->b;
		size = 0;
		half_stack = ft_lstsize_n(ps->b) / 2;
		while (ps->aux->content != ps->higher_n)
		{
			ps->aux = ps->aux->next;
			size++;
		}
		if (size > half_stack)
		{
			while (ps->b->content != ps->higher_n)
				reverse_rotate("rrb", ps);
			push("pa", ps);
		}
		else
		{
			while (ps->b->content != ps->higher_n)
				rotate("rb", ps);
			push("pa", ps);
		}
	}
}