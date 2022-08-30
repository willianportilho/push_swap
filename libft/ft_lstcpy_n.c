/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:55:42 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/30 21:10:47 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list_n	*ft_lstcpy_n(t_list_n *lst)
{
	t_list_n	*tmp_new;
	t_list_n	*new;

	if (!lst)
		return (NULL);
	new = ft_lstnew_n(lst->content);
	if (!new)
	{
		ft_lstclear_n(&new);
		return (NULL);
	}
	tmp_new = new;
	while (lst->next)
	{
		lst = lst->next;
		tmp_new->next = ft_lstnew_n(lst->content);
		if (!tmp_new)
		{
			ft_lstclear_n(&tmp_new);
			return (NULL);
		}
		tmp_new = tmp_new->next;
	}
	return (new);
}
