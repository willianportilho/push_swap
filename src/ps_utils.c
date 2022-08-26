/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:40:09 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/26 02:42:35 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ps_save_op(char *op, t_data *data)
{
	if (data->all_op == NULL)
		data->all_op = ft_lstnew(op);
	else
	{
		data->aux_op = ft_lstlast(data->all_op);
		data->aux_op->next = ft_lstnew(op);
	}
}

int	ps_check_sorting(t_data *data)
{
	if ((data->a) && (!data->b))
	{
		data->aux = data->a;
		data->aux2 = data->a;
		data->i = ft_lstsize_n(data->a);
		while (data->i-- > 1)
		{
			data->aux = data->aux->next;
			if (data->aux2->content > data->aux->content)
				return (1);
			data->aux2 = data->aux2->next;
		}
	}
	return (0);
}

void	ps_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	clear(t_data *data)
{
	if (data->a)
		ft_lstclear_n(&data->a);
	if (data->b)
		ft_lstclear_n(&data->b);
	if (data->all_op)
		ft_lstclear_alt(&data->all_op);
}
