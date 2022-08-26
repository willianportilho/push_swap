/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 23:39:08 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/26 03:03:54 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	amount(int position, int n, t_data *data)
{
	data->times = 0;
	data->aux = data->a;
	while (data->aux)
	{
		data->str = ft_itoa(data->aux->content);
		if ((data->str[ft_strlen(data->str) - position] - 48) == n)
			data->times++;
		data->aux = data->aux->next;
	}
}

void	ps_sort(t_data *data)
{
	int	n;

	n = 0;
	while (n <= 9)
	{
		amount(1, n, data);
		data->size = ft_lstsize_n(data->a);
		data->aux = data->a;
		while ((data->size > 0) && (data->times > 0))
		{
			data->str = ft_itoa(data->aux->content);
			if ((data->str[ft_strlen(data->str) - 1] - 48) == n)
			{
				data->size--;
				data->times--;
				push("pb", data);
			}
			else
			{
				rotate("ra", data);
				data->size--;
			}
			free(data->str);
			data->aux = data->a;
		}
		n++;
	}
	print_test(data, 1);
}
