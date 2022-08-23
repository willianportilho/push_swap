/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 00:23:19 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/23 00:50:50 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list_n	*ft_lstnew_n(int content)
{
	t_list_n	*n;

	n = malloc(sizeof(t_list));
	if (n == NULL)
		return (NULL);
	(*n).content = content;
	n->next = NULL;
	return (n);
}
