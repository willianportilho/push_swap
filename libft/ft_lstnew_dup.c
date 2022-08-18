/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 00:23:19 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/18 19:40:49 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list_dup	*ft_lstnew_dup(int content)
{
	t_list_dup	*n;

	n = malloc(sizeof(t_list));
	if (n == NULL)
		return (NULL);
	(*n).content = content;
	n->next = NULL;
	return (n);
}
