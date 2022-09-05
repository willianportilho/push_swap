/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:40:09 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/05 05:01:06 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ps_print(char *op)
{
	ft_printf("%s\n", op);
}

int	ps_check_sorting(t_ps *ps)
{
	if ((ps->a) && (!ps->b))
	{
		ps->aux = ps->a;
		ps->aux2 = ps->a;
		ps->i = ft_lstsize_n(ps->a);
		while (ps->i-- > 1)
		{
			ps->aux = ps->aux->next;
			if (ps->aux2->content > ps->aux->content)
				return (1);
			ps->aux2 = ps->aux2->next;
		}
	}
	return (0);
}

void	ps_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	ps_clear(t_ps *ps)
{
	if (ps->a)
		ft_lstclear_n(&ps->a);
	if (ps->b)
		ft_lstclear_n(&ps->b);
	if (ps->all_op)
		ft_lstclear_alt(&ps->all_op);
}
