/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:40:09 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/31 03:21:10 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ps_save_op(char *op, t_ps *ps)
{
	if (ps->all_op == NULL)
		ps->all_op = ft_lstnew(op);
	else
	{
		ps->aux_op = ft_lstlast(ps->all_op);
		ps->aux_op->next = ft_lstnew(op);
	}
}

void	save_block(t_ps *ps)
{
	if (ps->saved_blk == NULL)
		ps->saved_blk = ft_lstnew_n(ps->half);
	else
	{
		ps->aux = ft_lstlast_n(ps->saved_blk);
		ps->aux->next = ft_lstnew_n(ps->half);
	}
}

int	ps_check_sorting(t_ps *ps)
{
	if ((ps->a) && (!ps->b))
	{
		ps->aux = ps->a;
		ps->aux2 = ps->a;
		ps->i = ft_lstsize_n(ps->a);
		while (ps->i-- > 1)
		{
			ps->aux = ps->aux->next;
			if (ps->aux2->content > ps->aux->content)
				return (1);
			ps->aux2 = ps->aux2->next;
		}
	}
	return (0);
}

void	ps_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	clear(t_ps *ps)
{
	if (ps->a)
		ft_lstclear_n(&ps->a);
	if (ps->b)
		ft_lstclear_n(&ps->b);
	if (ps->saved_blk)
		ft_lstclear_n(&ps->saved_blk);
	if (ps->all_op)
		ft_lstclear_alt(&ps->all_op);
}
