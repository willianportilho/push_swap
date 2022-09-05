/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 23:39:08 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/02 02:28:40 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra_or_rra(t_ps *ps)
{
	int	size;
	int	half_stack;

	ps->aux = ps->a;
	size = 0;
	half_stack = ft_lstsize_n(ps->a) / 2;
	while (ps->aux->content >= ps->middle_n)
	{
		ps->aux = ps->aux->next;
		size++;
	}
	if (size > half_stack)
	{
		while (ps->a->content >= ps->middle_n)
			reverse_rotate("rra", ps);
	}
	else
	{
		while (ps->a->content >= ps->middle_n)
			rotate("ra", ps);
	}
}

void	send_to_b(t_ps *ps)
{
	int	times;

	times = ft_lstsize_n(ps->a) / 2;
	while (times > 0)
	{
		if (ps->a->content >= ps->middle_n)
		{
			ps->aux = ft_lstlast_n(ps->a);
			if (ps->aux->content < ps->middle_n)
			{
				reverse_rotate("rra", ps);
				push("pb", ps);
				times--;
			}
			else
				ra_or_rra(ps);
		}
		if (ps->a->content < ps->middle_n)
		{
			push("pb", ps);
			times--;
		}
	}
}

void	middle_point(t_ps *ps)
{
	ps->temp = ft_lstcpy_n(ps->a);
	while (ps->half > 0)
	{
		ps->aux = ps->temp;
		ps->higher_n = ps->temp->content;
		ps->middle_n = ps->temp->content;
		while (ps->aux)
		{
			if (ps->higher_n < ps->aux->content)
				ps->higher_n = ps->aux->content;
			if (ps->middle_n > ps->aux->content)
				ps->middle_n = ps->aux->content;
			ps->aux = ps->aux->next;
		}
		ps->aux = ps->temp;
		while (ps->aux->content != ps->middle_n)
			ps->aux = ps->aux->next;
		ps->aux->content = ps->higher_n;
		ps->half--;
	}
	if (ps->temp)
		ft_lstclear_n(&ps->temp);
}

void	ps_sort(t_ps *ps)
{
	while (ft_lstsize_n(ps->a) > 2)
	{
		ps->half = ft_lstsize_n(ps->a) / 2;
		save_block(ps);
		ps->half++;
		middle_point(ps);
		send_to_b(ps);
	}
	if (ps->a->content > ps->a->next->content)
		swap("sa", ps);
	send_to_a(ps);
}
