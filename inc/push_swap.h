/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:11:52 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/19 03:46:13 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft.h"

typedef struct s_data
{
	t_list_dup	*a;
	t_list_dup	*b;
	t_list_dup	*aux;
	int			ind_a;
	int			ind_b;
}				t_data;

void	swap(char c, t_data *data);
void	ps_init(int ac, char *av[], t_data *data);
void	ft_error(void);

#endif