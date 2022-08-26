/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 23:39:08 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/26 02:49:44 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//int	amount(int i, t_data *data)
//{
	
//}

void	ps_sort(t_data *data)
{
	int	n;
	//int	times;

	n = 0;
	while (n <= 9)
	{
		//times = amount(1, data)
		data->size = ft_lstsize_n(data->a);
		data->aux = data->a;
		while (data->size > 0)
		{
			data->str = ft_itoa(data->aux->content);
			if ((data->str[ft_strlen(data->str) - 1] - 48) == n)
			{
				data->size--;
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
