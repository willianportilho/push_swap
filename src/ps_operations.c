/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 02:24:11 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/19 20:03:23 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(char *op, t_data *data)
{
	if (((ft_strcmp(op, "sa") == 0) || (ft_strcmp(op, "ss") == 0)) \
	&& (ft_lstsize_dup(data->a) > 1))
	{
		data->aux = data->a->next;
		data->a->next = data->aux->next;
		data->aux->next = data->a;
		data->a = data->aux;
		data->aux = NULL;
		data->check = OK;
	}
	if (((ft_strcmp(op, "sb") == 0) || (ft_strcmp(op, "ss") == 0)) \
	&& (ft_lstsize_dup(data->b) > 1))
	{
		data->aux = data->b->next;
		data->b->next = data->aux->next;
		data->aux->next = data->b;
		data->b = data->aux;
		data->aux = NULL;
		data->check = OK;
	}
	if (data->check == OK)
		ps_print(op);
	data->check = N_OK;
}

void	push(char *op, t_data *data)
{
	if ((ft_strcmp(op, "pa") == 0) && (ft_lstsize_dup(data->b) > 0))
	{
		data->aux = data->b;
		data->b = data->b->next;
		data->aux->next = data->a;
		data->a = data->aux;
		data->aux = NULL;
		data->check = OK;
	}
	else if ((ft_strcmp(op, "pb") == 0) && (ft_lstsize_dup(data->a) > 0))
	{
		data->aux = data->a;
		data->a = data->a->next;
		data->aux->next = data->b;
		data->b = data->aux;
		data->aux = NULL;
		data->check = OK;
	}
	if (data->check == OK)
		ps_print(op);
	data->check = N_OK;
}

void	rotate(char *op, t_data *data)
{
	if (((ft_strcmp(op, "ra") == 0) || (ft_strcmp(op, "rr") == 0)) \
	&& (ft_lstsize_dup(data->a) > 1))
	{
		data->aux = ft_lstlast_dup(data->a);
		data->aux->next = data->a;
		data->aux = data->a->next;
		data->a->next = NULL;
		data->a = data->aux;
		data->aux = NULL;
		data->check = OK;
	}
	if (((ft_strcmp(op, "rb") == 0) || (ft_strcmp(op, "rr") == 0)) \
	&& (ft_lstsize_dup(data->b) > 1))
	{
		data->aux = ft_lstlast_dup(data->b);
		data->aux->next = data->b;
		data->aux = data->b->next;
		data->b->next = NULL;
		data->b = data->aux;
		data->aux = NULL;
		data->check = OK;
	}
	if (data->check == OK)
		ps_print(op);
	data->check = N_OK;
}

void	reverse_rotate_one(char *op, t_data *data)
{
	if (ft_lstsize_dup(data->a) > 1)
	{
		data->ind_a = ft_lstsize_dup(data->a);
		data->aux = ft_lstlast_dup(data->a);
		data->aux->next = data->a;
		data->a = data->aux;
		while (data->ind_a-- > 1)
			data->aux = data->aux->next;
		data->aux->next = NULL;
		data->aux = NULL;
		data->check = OK;
	}
	if ((ft_strcmp(op, "rrr") == 0) && (data->check == OK))
	{
		reverse_rotate_two("rrr", data);
		ps_print(op);
	}
	else if (data->check == OK)
		ps_print(op);
	data->check = N_OK;
}

void	reverse_rotate_two(char *op, t_data *data)
{
	if (ft_lstsize_dup(data->b) > 1)
	{
		data->ind_b = ft_lstsize_dup(data->b);
		data->aux = ft_lstlast_dup(data->b);
		data->aux->next = data->b;
		data->b = data->aux;
		while (data->ind_b-- > 1)
			data->aux = data->aux->next;
		data->aux->next = NULL;
		data->aux = NULL;
		data->check = OK;
	}
	if (ft_strcmp(op, "rrr") == 0)
		return ;
	else if (data->check == OK)
		ps_print(op);
	data->check = N_OK;
}
