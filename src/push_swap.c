/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:51:17 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/19 04:07:45 by wportilh         ###   ########.fr       */
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
	rotate('a', &data);
	data.aux = data.a;
	while (data.aux->next)
	{
		ft_printf("depois: %d\n", data.aux->content);
		data.aux = data.aux->next;
	}
	ft_printf("depois: %d\n", data.aux->content);
	data.aux = NULL;
	ft_lstclear_dup(&data.a);
}
