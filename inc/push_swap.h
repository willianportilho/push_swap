/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:11:52 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/06 00:56:40 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define STACK_A 1
# define STACK_B 2

# include "./libft.h"

typedef struct s_ps
{
	t_list_n	*a;
	t_list_n	*b;
	t_list_n	*aux;
	t_list_n	*aux2;
	t_list		*all_op;
	t_list		*aux_op;
	int			i;
	int			i2;
	int			blk;
	int			times;
	int			size_a;
	int			higher_n;
	int			smaller_n;
	int			middle_n;
	int			half_stack;
	int			higher_distance;
}				t_ps;

int		ps_check_sorting(t_ps *ps);
void	ps_clear(t_ps *ps);
void	ps_double_operation(char *op, t_ps *ps);
void	ps_error(void);
void	ps_init(int ac, char *av[], t_ps *ps);
void	ps_print(char *op);
void	ps_print_operations(t_ps *ps);
void	ps_push(char *op, t_ps *ps);
void	ps_reverse_rotate(char *op, t_ps *ps);
void	ps_rotate(char *op, t_ps *ps);
void	ps_save_op(char *op, t_ps *ps);
void	ps_send_to_a(t_ps *ps);
void	ps_sort(t_ps *ps);
void	ps_sort_small_stack(t_ps *ps);
void	ps_swap(char *op, t_ps *ps);

#endif