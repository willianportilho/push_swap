/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 23:39:08 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/06 01:35:26 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ra_or_rra(t_ps *ps)
{
	ps->aux = ps->a;
	ps->higher_distance = 0;
	ps->half_stack = ft_lstsize_n(ps->a) / 2;
	while (ps->aux->content >= ps->middle_n)
	{
		ps->aux = ps->aux->next;
		ps->higher_distance++;
	}
	if (ps->higher_distance > ps->half_stack)
	{
		while (ps->a->content >= ps->middle_n)
			ps_reverse_rotate("rra", ps);
	}
	else
	{
		while (ps->a->content >= ps->middle_n)
			ps_rotate("ra", ps);
	}
}

static void	send_to_b(t_ps *ps)
{
	ps->times = ps->blk - 1;
	while (ps->times > 0)
	{
		if (ps->a->content >= ps->middle_n)
		{
			ps->aux = ft_lstlast_n(ps->a);
			if (ps->aux->content < ps->middle_n)
			{
				ps_reverse_rotate("rra", ps);
				ps_push("pb", ps);
				ps->times--;
			}
			else
				ra_or_rra(ps);
		}
		if (ps->a->content < ps->middle_n)
		{
			ps_push("pb", ps);
			ps->times--;
		}
	}
}

static void	middle_point(t_ps *ps)
{
	ps->times = ps->blk;
	ps->aux2 = ft_lstcpy_n(ps->a);
	while (ps->times > 0)
	{
		ps->aux = ps->aux2;
		ps->higher_n = ps->aux2->content;
		ps->middle_n = ps->aux2->content;
		while (ps->aux)
		{
			if (ps->higher_n < ps->aux->content)
				ps->higher_n = ps->aux->content;
			if (ps->middle_n > ps->aux->content)
				ps->middle_n = ps->aux->content;
			ps->aux = ps->aux->next;
		}
		ps->aux = ps->aux2;
		while (ps->aux->content != ps->middle_n)
			ps->aux = ps->aux->next;
		ps->aux->content = ps->higher_n;
		ps->times--;
	}
	if (ps->aux2)
		ft_lstclear_n(&ps->aux2);
}

static void	size_blk(t_ps *ps)
{
	ps->size_a = ft_lstsize_n(ps->a);
	if (ps->size_a < 18)
		ps->blk = ps->size_a;
	else if (ps->size_a <= 100)
		ps->blk = 18;
	else if (ps->size_a <= 500)
		ps->blk = 38;
	else if (ps->size_a <= 2500)
		ps->blk = 80;
	else if (ps->size_a <= 10000)
		ps->blk = 169;
	else if (ps->size_a <= 50000)
		ps->blk = 357;
	else if (ps->size_a <= 250000)
		ps->blk = 755;
	else if (ps->size_a <= 1000000)
		ps->blk = 1593;
	else if (ps->size_a <= 5000000)
		ps->blk = 3363;
	else if (ps->size_a <= 25000000)
		ps->blk = 7099;
	else if (ps->size_a <= 100000000)
		ps->blk = 14985;
	else
		ps->blk = 50000;
}

void	ps_sort(t_ps *ps)
{
	if (ft_lstsize_n(ps->a) <= 5)
	{
		ps_sort_small_stack(ps);
		return ;
	}
	while (ft_lstsize_n(ps->a) > 1)
	{
		size_blk(ps);
		middle_point(ps);
		send_to_b(ps);
	}
	ps_send_to_a(ps);
}
