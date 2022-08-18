/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_dup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 04:00:55 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/19 00:38:00 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstclear_dup(t_list_dup **lst)
{
	t_list_dup	*temp;

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
