/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_n.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 04:00:55 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/23 00:50:37 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstclear_n(t_list_n **lst)
{
	t_list_n	*temp;

	temp = *lst;
	if (temp == NULL)
		return ;
	while (*lst)
	{
		*lst = (*lst)->next;
		free(temp);
		temp = *lst;
	}
	*lst = NULL;
}
