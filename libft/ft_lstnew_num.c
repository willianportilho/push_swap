/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 00:23:19 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/20 01:07:59 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list_num	*ft_lstnew_num(int content)
{
	t_list_num	*n;

	n = malloc(sizeof(t_list));
	if (n == NULL)
		return (NULL);
	(*n).content = content;
	n->next = NULL;
	return (n);
}
