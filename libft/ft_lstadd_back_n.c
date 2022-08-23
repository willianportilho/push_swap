/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_n.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 04:36:51 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/23 00:50:29 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstadd_back_n(t_list_n **lst, t_list_n *new)
{
	t_list_n	*temp;

	temp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	else if (temp->next == NULL)
	{
		temp->next = new;
		return ;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->next == NULL)
		{
			temp->next = new;
			return ;
		}
	}
}
