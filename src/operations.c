/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 02:24:11 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/19 04:05:42 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(char c, t_data *data)
{
	if ((c == 'a') || (c == 's'))
	{
		if (ft_lstsize_dup(data->a) > 1)
		{
			data->aux = data->a->next;
			data->a->next = data->aux->next;
			data->aux->next = data->a;
			data->a = data->aux;
			data->aux = NULL;
		}
	}
	if ((c == 'b') || (c == 's'))
	{
		if (ft_lstsize_dup(data->b) > 1)
		{
			data->aux = data->b->next;
			data->b->next = data->aux->next;
			data->aux->next = data->b;
			data->b = data->aux;
			data->aux = NULL;
		}
	}
}

void	rotate(char c, t_data *data)
{
	if ((c == 'a') || (c == 'r'))
	{
		if (ft_lstsize_dup(data->a) > 1)
		{
			data->aux = ft_lstlast_dup(data->a);
			data->aux->next = data->a;
			data->aux = data->a->next;
			data->a->next = NULL;
			data->a = data->aux;
			data->aux = NULL;
		}
	}
	if ((c == 'b') || (c == 'r'))
	{
		if (ft_lstsize_dup(data->b) > 1)
		{
			data->aux = ft_lstlast_dup(data->b);
			data->aux->next = data->b;
			data->aux = data->b->next;
			data->b->next = NULL;
			data->b = data->aux;
			data->aux = NULL;
		}
	}
}
