/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:11:52 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/19 20:45:16 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define OK 0
# define N_OK 1

# include "./libft.h"

typedef struct s_data
{
	t_list_dup	*a;
	t_list_dup	*b;
	t_list_dup	*aux;
	t_list		*op;
	t_list		*supp;
	int			ind_a;
	int			ind_b;
	int			check;
}				t_data;

void	push(char *op, t_data *data);
void	reverse_rotate_one(char *op, t_data *data);
void	reverse_rotate_two(char *op, t_data *data);
void	rotate(char *op, t_data *data);
void	swap(char *op, t_data *data);
void	ps_init(int ac, char *av[], t_data *data);
void	ps_error(void);
void	ps_print(char *op);

#endif