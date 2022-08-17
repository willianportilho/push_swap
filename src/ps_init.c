/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 01:56:45 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/18 00:41:40 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	stacks(char *av[], t_list **list)
{
	t_list	*node;
	int		i;

	i = 1;
	*list = ft_lstnew(av[i++]);
	node = ft_lstnew(av[i++]);
	(*list)->next = node;
	while (av[i])
	{
		node->next = ft_lstnew(av[i++]);
		node = node->next;
	}
	ft_printf("%s\n", (*list)->content);
	while ((*list)->next)
	{
		ft_printf("%s\n", (*list)->next->content);
		*list = (*list)->next;
	}
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
			ft_error();
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
		if ((av[i][j] == '-') && (av[i][j + 1] != '\0'))
				j++;
		while (av[i][j])
		{
			if ((av[i][j] < '0') || (av[i][j] > '9'))
				ft_error();
			j++;
		}
		n = ft_atol(av[i]);
		if ((n < -2147483648) || (n > 2147483647))
			ft_error();
		check_dup(n, av);
		i++;
		j = 0;
	}
}

void	ps_init(int ac, char *av[], t_list **list)
{
	check_args(ac, av);
	stacks(av, list);
}
