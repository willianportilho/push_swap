/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstncpy_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:55:42 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/01 23:46:18 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list_n	*ft_lstncpy_n(t_list_n *lst, int n)
{
	t_list_n	*tmp_new;
	t_list_n	*new;

	if ((!lst) || (n <= 0))
		return (NULL);
	new = ft_lstnew_n(lst->content);
	if (!new)
	{
		ft_lstclear_n(&new);
		return (NULL);
	}
	tmp_new = new;
	while ((lst->next) && (--n > 0))
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
