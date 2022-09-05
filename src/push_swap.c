/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:51:17 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/05 18:26:52 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char *argv[])
{
	t_ps		ps;

	ps_init(argc, argv, &ps);
	ps_sort(&ps);
	ps_print_operations(&ps);
	/*int	i;
	i = ft_lstsize(ps.all_op);
	ft_printf("Total: %d\n", i);*/
	ps_clear(&ps);
}
