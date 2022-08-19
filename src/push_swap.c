/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:51:17 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/19 20:44:44 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char *argv[])
{
	t_data		data;

	ps_init(argc, argv, &data);
	push("pb", &data);
	push("pb", &data);
	push("pb", &data);
	swap("sb", &data);
	//swap("sb", &data);
	//reverse_rotate_two("rrb", &data);
	//reverse_rotate_one("rrr", &data);
	if (data.a)
	{
		data.aux = data.a;
		while (data.aux->next)
		{
			ft_printf("a: %d\n", data.aux->content);
			data.aux = data.aux->next;
		}
		ft_printf("a: %d\n\n", data.aux->content);
	}
	if (data.b)
	{
		data.aux = data.b;
		while (data.aux->next)
		{
			ft_printf("b: %d\n", data.aux->content);
			data.aux = data.aux->next;
		}
		ft_printf("b: %d\n", data.aux->content);
	}
	ft_lstclear_dup(&data.a);
	ft_lstclear_dup(&data.b);
}
