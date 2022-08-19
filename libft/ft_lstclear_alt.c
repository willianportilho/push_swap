/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_alt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 04:00:55 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/20 00:37:41 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstclear_alt(t_list **lst)
{
	t_list	*temp;

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
