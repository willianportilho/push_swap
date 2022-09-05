/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:11:52 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/02 00:50:34 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "./libft.h"

typedef struct s_ps
{
	t_list_n	*a;
	t_list_n	*b;
	t_list_n	*temp;
	t_list_n	*aux;
	t_list_n	*aux2;
	t_list_n	*aux_temp;
	t_list_n	*saved_blk;
	t_list		*all_op;
	t_list		*aux_op;
	int			i;
	int			i2;
	int			half;
	int			higher_n;
	int			middle_n;
}				t_ps;

void	print_a(t_ps *ps); //Apagar depois;
void	print_b(t_ps *ps); //Apagar depois;
void	print_all(t_ps *ps); //Apagar depois;
void	print_block(t_ps *ps); //Apagar depois;

void	clear(t_ps *ps);
int		ps_check_sorting(t_ps *ps);
void	double_operation(char *op, t_ps *ps);
void	push(char *op, t_ps *ps);
void	reverse_rotate(char *op, t_ps *ps);
void	rotate(char *op, t_ps *ps);
void	swap(char *op, t_ps *ps);
void	middle_point(t_ps *ps);
void	ps_sort(t_ps *ps);
void	ps_init(int ac, char *av[], t_ps *ps);
void	ps_error(void);
void	save_block(t_ps *ps);
void	send_to_a(t_ps *ps);
void	ps_save_op(char *op, t_ps *ps);

#endif