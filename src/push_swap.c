/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:51:17 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/26 02:46:32 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_test(t_data *data, int check)
{
	if (data->a)
	{
		data->aux = data->a;
		while (data->aux->next)
		{
			ft_printf("a: %d\n", data->aux->content);
			data->aux = data->aux->next;
		}
		ft_printf("a: %d\n\n", data->aux->content);
	}
	if (data->b)
	{
		data->aux = data->b;
		while (data->aux->next)
		{
			ft_printf("b: %d\n", data->aux->content);
			data->aux = data->aux->next;
		}
		ft_printf("b: %d\n\n", data->aux->content);
	}
	if (check == 1)
	{
		if (data->all_op)
		{
		data->aux_op = data->all_op;
		while (data->aux_op->next)
		{
			ft_printf("%s\n", data->aux_op->content);
			data->aux_op = data->aux_op->next;
		}
		if (data->aux_op->content)
			ft_printf("%s\n", data->aux_op->content);
		}
	}
}

int	main(int argc, char *argv[])
{
	t_data		data;

	ps_init(argc, argv, &data);
	//print_test(&data, 1);
	ps_sort(&data);
	//print_test(&data, 1);
	clear(&data);
}
