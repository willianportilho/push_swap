/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 02:24:11 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/23 01:32:36 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(char *op, t_data *data)
{
	data->i = ft_lstsize_n(data->a);
	if (((!ft_strcmp(op, "sa")) || (!ft_strcmp(op, "ss"))) && (data->i > 1))
	{
		data->aux = data->a->next;
		data->a->next = data->aux->next;
		data->aux->next = data->a;
		data->a = data->aux;
		data->aux = NULL;
		if (ft_strcmp(op, "ss") != 0)
			ps_save_op(op, data);
	}
	data->i2 = ft_lstsize_n(data->b);
	if (((!ft_strcmp(op, "sb")) || (!ft_strcmp(op, "ss"))) && (data->i2 > 1))
	{
		data->aux = data->b->next;
		data->b->next = data->aux->next;
		data->aux->next = data->b;
		data->b = data->aux;
		data->aux = NULL;
		ps_save_op(op, data);
	}
}

void	push(char *op, t_data *data)
{
	data->i2 = ft_lstsize_n(data->b);
	if ((!ft_strcmp(op, "pa")) && (data->i2 > 0))
	{
		data->aux = data->b;
		data->b = data->b->next;
		data->aux->next = data->a;
		data->a = data->aux;
		data->aux = NULL;
		ps_save_op(op, data);
	}
	data->i = ft_lstsize_n(data->a);
	if ((!ft_strcmp(op, "pb")) && (data->i > 0))
	{
		data->aux = data->a;
		data->a = data->a->next;
		data->aux->next = data->b;
		data->b = data->aux;
		data->aux = NULL;
		ps_save_op(op, data);
	}
}

void	rotate(char *op, t_data *data)
{
	data->i = ft_lstsize_n(data->a);
	if (((!ft_strcmp(op, "ra")) || (!ft_strcmp(op, "rr"))) && (data->i > 1))
	{
		data->aux = ft_lstlast_n(data->a);
		data->aux->next = data->a;
		data->aux = data->a->next;
		data->a->next = NULL;
		data->a = data->aux;
		data->aux = NULL;
		if (ft_strcmp(op, "rr") != 0)
			ps_save_op(op, data);
	}
	data->i2 = ft_lstsize_n(data->b);
	if (((!ft_strcmp(op, "rb")) || (!ft_strcmp(op, "rr"))) && (data->i2 > 1))
	{
		data->aux = ft_lstlast_n(data->b);
		data->aux->next = data->b;
		data->aux = data->b->next;
		data->b->next = NULL;
		data->b = data->aux;
		data->aux = NULL;
		ps_save_op(op, data);
	}
}

void	reverse_rotate(char *op, t_data *data)
{
	data->i = ft_lstsize_n(data->a);
	if (((!ft_strcmp(op, "rra")) || (!ft_strcmp(op, "rrr"))) && (data->i > 1))
	{
		data->aux = ft_lstlast_n(data->a);
		data->aux->next = data->a;
		data->a = data->aux;
		while (data->i-- > 1)
			data->aux = data->aux->next;
		data->aux->next = NULL;
		data->aux = NULL;
		if (ft_strcmp(op, "rrr") != 0)
			ps_save_op(op, data);
	}
	data->i2 = ft_lstsize_n(data->b);
	if (((!ft_strcmp(op, "rrb")) || (!ft_strcmp(op, "rrr"))) && (data->i2 > 1))
	{
		data->aux = ft_lstlast_n(data->b);
		data->aux->next = data->b;
		data->b = data->aux;
		while (data->i2-- > 1)
			data->aux = data->aux->next;
		data->aux->next = NULL;
		data->aux = NULL;
		ps_save_op(op, data);
	}
}

void	double_operation(char *op, t_data *data)
{
	data->i = ft_lstsize_n(data->a);
	data->i2 = ft_lstsize_n(data->b);
	if ((!ft_strcmp(op, "ss")) && (data->i > 1) && (data->i2 > 1))
		swap(op, data);
	if ((!ft_strcmp(op, "rr")) && (data->i > 1) && (data->i2 > 1))
		rotate(op, data);
	if ((!ft_strcmp(op, "rrr")) && (data->i > 1) && (data->i2 > 1))
		reverse_rotate(op, data);
}
