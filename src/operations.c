/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 02:24:11 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/19 03:45:56 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(char c, t_data *data)
{
	if ((c == 'a') || (c == 's'))
	{
		data->ind_a = ft_lstsize_dup(data->a);
		if (data->ind_a > 1)
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
		data->ind_b = ft_lstsize_dup(data->b);
		if (data->ind_b > 1)
		{
			data->aux = data->b->next;
			data->b->next = data->aux->next;
			data->aux->next = data->b;
			data->b = data->aux;
			data->aux = NULL;
		}
	}
}
