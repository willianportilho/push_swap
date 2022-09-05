/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 00:47:19 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/05 18:16:58 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	higher_number(t_ps *ps)
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

void	ps_send_to_a(t_ps *ps)
{
	while (ps->b)
	{
		higher_number(ps);
		ps->aux = ps->b;
		ps->higher_distance = 0;
		ps->half_stack = ft_lstsize_n(ps->b) / 2;
		while (ps->aux->content != ps->higher_n)
		{
			ps->aux = ps->aux->next;
			ps->higher_distance++;
		}
		if (ps->higher_distance > ps->half_stack)
		{
			while (ps->b->content != ps->higher_n)
				ps_reverse_rotate("rrb", ps);
			ps_push("pa", ps);
		}
		else
		{
			while (ps->b->content != ps->higher_n)
				ps_rotate("rb", ps);
			ps_push("pa", ps);
		}
	}
}
