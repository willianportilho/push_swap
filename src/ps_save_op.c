/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_save_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 06:51:09 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/20 00:51:53 by wportilh         ###   ########.fr       */
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
