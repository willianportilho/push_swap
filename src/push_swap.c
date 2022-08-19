/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:51:17 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/19 06:43:40 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char *argv[])
{
	t_data		data;

	ps_init(argc, argv, &data);
	data.aux = data.a;
	while (data.aux->next)
	{
		ft_printf(" antes: %d\n", data.aux->content);
		data.aux = data.aux->next;
	}
	ft_printf(" antes: %d\n\n", data.aux->content);
	data.aux = NULL;
	push('b', &data);
	push('b', &data);
	push('b', &data);
	push('b', &data);
	push('b', &data);
	push('b', &data);
	push('b', &data);
	push('b', &data);
	push('b', &data);
	push('b', &data);
	if (data.a)
	{
		data.aux = data.a;
		while (data.aux->next)
		{
			ft_printf("depois: %d\n", data.aux->content);
			data.aux = data.aux->next;
		}
		ft_printf("depois: %d\n", data.aux->content);
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
