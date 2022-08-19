/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 02:24:11 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/20 01:05:04 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(char *op, t_data *data)
{
	if ((ft_strcmp(op, "sa") == 0) || (ft_strcmp(op, "ss") == 0))
	{
		data->aux = data->a->next;
		data->a->next = data->aux->next;
		data->aux->next = data->a;
		data->a = data->aux;
		data->aux = NULL;
	}
	if ((ft_strcmp(op, "sb") == 0) || (ft_strcmp(op, "ss") == 0))
	{
		data->aux = data->b->next;
		data->b->next = data->aux->next;
		data->aux->next = data->b;
		data->b = data->aux;
		data->aux = NULL;
	}
	ps_save_op(op, data);
}

void	push(char *op, t_data *data)
{
	if (ft_strcmp(op, "pa") == 0)
	{
		data->aux = data->b;
		data->b = data->b->next;
		data->aux->next = data->a;
		data->a = data->aux;
		data->aux = NULL;
	}
	else if (ft_strcmp(op, "pb") == 0)
	{
		data->aux = data->a;
		data->a = data->a->next;
		data->aux->next = data->b;
		data->b = data->aux;
		data->aux = NULL;
	}
	ps_save_op(op, data);
}

void	rotate(char *op, t_data *data)
{
	if ((ft_strcmp(op, "ra") == 0) || (ft_strcmp(op, "rr") == 0))
	{
		data->aux = ft_lstlast_num(data->a);
		data->aux->next = data->a;
		data->aux = data->a->next;
		data->a->next = NULL;
		data->a = data->aux;
		data->aux = NULL;
	}
	if ((ft_strcmp(op, "rb") == 0) || (ft_strcmp(op, "rr") == 0))
	{
		data->aux = ft_lstlast_num(data->b);
		data->aux->next = data->b;
		data->aux = data->b->next;
		data->b->next = NULL;
		data->b = data->aux;
		data->aux = NULL;
	}
	ps_save_op(op, data);
}

void	reverse_rotate(char *op, t_data *data)
{
	if ((ft_strcmp(op, "rra") == 0) || (ft_strcmp(op, "rrr") == 0))
	{
		data->ind_a = ft_lstsize_num(data->a);
		data->aux = ft_lstlast_num(data->a);
		data->aux->next = data->a;
		data->a = data->aux;
		while (data->ind_a-- > 1)
			data->aux = data->aux->next;
		data->aux->next = NULL;
		data->aux = NULL;
	}
	if ((ft_strcmp(op, "rrb") == 0) || (ft_strcmp(op, "rrr") == 0))
	{
		data->ind_b = ft_lstsize_num(data->b);
		data->aux = ft_lstlast_num(data->b);
		data->aux->next = data->b;
		data->b = data->aux;
		while (data->ind_b-- > 1)
			data->aux = data->aux->next;
		data->aux->next = NULL;
		data->aux = NULL;
	}
	ps_save_op(op, data);
}
