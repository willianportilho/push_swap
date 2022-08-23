/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 01:56:45 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/23 21:58:41 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	stack(char *av[], t_data *data)
{
	int		i;

	i = 1;
	data->a = ft_lstnew_n(ft_atoi(av[i++]));
	if (av[i])
	{
		data->aux = ft_lstnew_n(ft_atoi(av[i++]));
		data->a->next = data->aux;
		while (av[i])
		{
			data->aux->next = ft_lstnew_n(ft_atoi(av[i++]));
			data->aux = data->aux->next;
		}
		data->aux = NULL;
	}
	data->b = NULL;
	data->aux2 = NULL;
}

static void	check_dup(int n, char *av[])
{
	int	i;
	int	amount;

	i = 1;
	amount = 0;
	while (av[i])
	{
		if (n == ft_atoi(av[i++]))
			amount++;
		if (amount > 1)
			ps_error();
	}
}

static void	check_args(int ac, char *av[])
{	
	int		i;
	int		j;
	long	n;

	i = 1;
	j = 0;
	if (ac == 1)
		exit (EXIT_FAILURE);
	while (av[i])
	{
		if (((av[i][j] == '-') || (av[i][j] == '+')) && (av[i][j + 1] != '\0'))
				j++;
		while (av[i][j])
		{
			if ((av[i][j] < '0') || (av[i][j] > '9'))
				ps_error();
			j++;
		}
		n = ft_atol(av[i]);
		if ((n < INT_MIN) || (n > INT_MAX))
			ps_error();
		check_dup(n, av);
		i++;
		j = 0;
	}
}

void	ps_init(int ac, char *av[], t_data *data)
{
	check_args(ac, av);
	stack(av, data);
	if (!ps_check_sorting(data))
		exit(EXIT_SUCCESS);
	data->all_op = NULL;
	data->aux_op = NULL;
}
