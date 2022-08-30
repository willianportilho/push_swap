/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 02:24:11 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/26 21:34:38 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(char *op, t_ps *ps)
{
	ps->i = ft_lstsize_n(ps->a);
	if (((!ft_strcmp(op, "sa")) || (!ft_strcmp(op, "ss"))) && (ps->i > 1))
	{
		ps->aux = ps->a->next;
		ps->a->next = ps->aux->next;
		ps->aux->next = ps->a;
		ps->a = ps->aux;
		ps->aux = NULL;
		if (ft_strcmp(op, "ss") != 0)
			ps_save_op(op, ps);
	}
	ps->i2 = ft_lstsize_n(ps->b);
	if (((!ft_strcmp(op, "sb")) || (!ft_strcmp(op, "ss"))) && (ps->i2 > 1))
	{
		ps->aux = ps->b->next;
		ps->b->next = ps->aux->next;
		ps->aux->next = ps->b;
		ps->b = ps->aux;
		ps->aux = NULL;
		ps_save_op(op, ps);
	}
}

void	push(char *op, t_ps *ps)
{
	ps->i2 = ft_lstsize_n(ps->b);
	if ((!ft_strcmp(op, "pa")) && (ps->i2 > 0))
	{
		ps->aux = ps->b;
		ps->b = ps->b->next;
		ps->aux->next = ps->a;
		ps->a = ps->aux;
		ps->aux = NULL;
		ps_save_op(op, ps);
	}
	ps->i = ft_lstsize_n(ps->a);
	if ((!ft_strcmp(op, "pb")) && (ps->i > 0))
	{
		ps->aux = ps->a;
		ps->a = ps->a->next;
		ps->aux->next = ps->b;
		ps->b = ps->aux;
		ps->aux = NULL;
		ps_save_op(op, ps);
	}
}

void	rotate(char *op, t_ps *ps)
{
	ps->i = ft_lstsize_n(ps->a);
	if (((!ft_strcmp(op, "ra")) || (!ft_strcmp(op, "rr"))) && (ps->i > 1))
	{
		ps->aux = ft_lstlast_n(ps->a);
		ps->aux->next = ps->a;
		ps->aux = ps->a->next;
		ps->a->next = NULL;
		ps->a = ps->aux;
		ps->aux = NULL;
		if (ft_strcmp(op, "rr") != 0)
			ps_save_op(op, ps);
	}
	ps->i2 = ft_lstsize_n(ps->b);
	if (((!ft_strcmp(op, "rb")) || (!ft_strcmp(op, "rr"))) && (ps->i2 > 1))
	{
		ps->aux = ft_lstlast_n(ps->b);
		ps->aux->next = ps->b;
		ps->aux = ps->b->next;
		ps->b->next = NULL;
		ps->b = ps->aux;
		ps->aux = NULL;
		ps_save_op(op, ps);
	}
}

void	reverse_rotate(char *op, t_ps *ps)
{
	ps->i = ft_lstsize_n(ps->a);
	if (((!ft_strcmp(op, "rra")) || (!ft_strcmp(op, "rrr"))) && (ps->i > 1))
	{
		ps->aux = ft_lstlast_n(ps->a);
		ps->aux->next = ps->a;
		ps->a = ps->aux;
		while (ps->i-- > 1)
			ps->aux = ps->aux->next;
		ps->aux->next = NULL;
		ps->aux = NULL;
		if (ft_strcmp(op, "rrr") != 0)
			ps_save_op(op, ps);
	}
	ps->i2 = ft_lstsize_n(ps->b);
	if (((!ft_strcmp(op, "rrb")) || (!ft_strcmp(op, "rrr"))) && (ps->i2 > 1))
	{
		ps->aux = ft_lstlast_n(ps->b);
		ps->aux->next = ps->b;
		ps->b = ps->aux;
		while (ps->i2-- > 1)
			ps->aux = ps->aux->next;
		ps->aux->next = NULL;
		ps->aux = NULL;
		ps_save_op(op, ps);
	}
}

void	double_operation(char *op, t_ps *ps)
{
	ps->i = ft_lstsize_n(ps->a);
	ps->i2 = ft_lstsize_n(ps->b);
	if ((!ft_strcmp(op, "ss")) && (ps->i > 1) && (ps->i2 > 1))
		swap(op, ps);
	if ((!ft_strcmp(op, "rr")) && (ps->i > 1) && (ps->i2 > 1))
		rotate(op, ps);
	if ((!ft_strcmp(op, "rrr")) && (ps->i > 1) && (ps->i2 > 1))
		reverse_rotate(op, ps);
}
