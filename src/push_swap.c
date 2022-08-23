/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:51:17 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/23 21:25:11 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*static void	print_test(t_data *data)
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
}*/

int	main(int argc, char *argv[])
{
	t_data		data;

	ps_init(argc, argv, &data);
	/*print_test(&data);
	//push("pb", &data);
	//push("pb", &data);
	//push("pb", &data);
	push("pb", &data);
	push("pb", &data);
	push("pb", &data);
	double_operation("ss", &data);
	//reverse_rotate("rrr", &data);
	print_test(&data);
	if (data.all_op)
	{
		data.aux_op = data.all_op;
		while (data.aux_op->next)
		{
			ft_printf("%s\n", data.aux_op->content);
			data.aux_op = data.aux_op->next;
		}
		ft_printf("%s\n", data.aux_op->content);
	}*/
	if (data.a)
		ft_lstclear_n(&data.a);
	if (data.b)
		ft_lstclear_n(&data.b);
	if (data.all_op)
		ft_lstclear_alt(&data.all_op);
}
