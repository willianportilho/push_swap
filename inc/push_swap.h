/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:11:52 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/24 23:43:51 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "./libft.h"

typedef struct s_data
{
	t_list_n	*a;
	t_list_n	*b;
	t_list_n	*aux;
	t_list_n	*aux2;
	t_list		*all_op;
	t_list		*aux_op;
	int			i;
	int			i2;
}				t_data;

int		ps_check_sorting(t_data *data);
void	double_operation(char *op, t_data *data);
void	push(char *op, t_data *data);
void	reverse_rotate(char *op, t_data *data);
void	rotate(char *op, t_data *data);
void	swap(char *op, t_data *data);
void	ps_sort(t_data *data);
void	ps_init(int ac, char *av[], t_data *data);
void	ps_error(void);
void	ps_save_op(char *op, t_data *data);

#endif