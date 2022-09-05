/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 00:47:19 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/06 01:36:00 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	higher_number(int stack, t_ps *ps)
{
	if (stack == STACK_A)
	{
		ps->aux = ps->a;
		ps->higher_n = ps->a->content;
	}
	else
	{
		ps->aux = ps->b;
		ps->higher_n = ps->b->content;
	}
	while (ps->aux)
	{
		if (ps->higher_n < ps->aux->content)
			ps->higher_n = ps->aux->content;
		ps->aux = ps->aux->next;
	}
}

static void	smaller_number(t_ps *ps)
{
	ps->aux = ps->a;
	ps->smaller_n = ps->a->content;
	while (ps->aux)
	{
		if (ps->smaller_n > ps->aux->content)
			ps->smaller_n = ps->aux->content;
		ps->aux = ps->aux->next;
	}
}

static void	send_to_b(t_ps *ps)
{
	while (ft_lstsize_n(ps->a) > 3)
	{
		smaller_number(ps);
		ps->aux = ps->a;
		ps->higher_distance = 0;
		ps->half_stack = ft_lstsize_n(ps->a) / 2;
		while (ps->aux->content != ps->smaller_n)
		{
			ps->aux = ps->aux->next;
			ps->higher_distance++;
		}
		if (ps->higher_distance > ps->half_stack)
		{
			while (ps->a->content != ps->smaller_n)
				ps_reverse_rotate("rra", ps);
			ps_push("pb", ps);
		}
		else
		{
			while (ps->a->content != ps->smaller_n)
				ps_rotate("ra", ps);
			ps_push("pb", ps);
		}
	}
}

void	ps_sort_small_stack(t_ps *ps)
{
	if (ft_lstsize_n(ps->a) == 2)
	{
		if (ps->a->content > ps->a->next->content)
			ps_swap("sa", ps);
	}
	else if (ft_lstsize_n(ps->a) > 2)
	{
		send_to_b(ps);
		higher_number(STACK_A, ps);
		if (ps->a->content == ps->higher_n)
			ps_rotate("ra", ps);
		else if (ps->a->next->content == ps->higher_n)
			ps_reverse_rotate("rra", ps);
		if (ps->a->content > ps->a->next->content)
			ps_swap("sa", ps);
		while (ps->b)
			ps_push("pa", ps);
	}
}

void	ps_send_to_a(t_ps *ps)
{
	while (ps->b)
	{
		higher_number(STACK_B, ps);
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
