/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 23:39:08 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/31 03:21:18 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
			{
				while (ps->a->content >= ps->middle_n)
					rotate("ra", ps);
			}
		}
		if (ps->a->content < ps->middle_n)
		{
			push("pb", ps);
			times--;
		}
	}
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
	print_all(ps);
}
