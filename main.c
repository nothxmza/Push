/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:05:33 by hterras           #+#    #+#             */
/*   Updated: 2022/10/24 13:29:35 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check(char **argv)
{
	int			i;
	int			x;
	long long	tmp;

	i = 0;
	x = 0;
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		if (tmp > 2147483647)
			ft_exit_error();
		if (tmp < -2147483648)
			ft_exit_error();
		while (argv[i][x])
		{
			if (!ft_isalnum(argv[i][x]) || \
				(argv[i][x] == '-' && !argv[i][x + 1]))
				ft_exit_error();
			if (argv[i][x] == '-' && argv[i][x + 1] == '-')
				ft_exit_error();
			x++;
		}
		x = 0;
		i++;
	}
}

void	check_doublon(char **argv)
{
	int	i;
	int	x;
	int	j;
	int	total;

	i = 0;
	j = 0;
	total = 0;
	x = 0;
	while (argv[i])
	{
		while (argv[x])
		{
			if (strcmp(argv[i], argv[x]) == 0)
				j += 1;
			if (j > 1)
				total++;
			x++;
		}
		j = 0;
		x = 0;
		i++;
	}
	if (total > 1)
		ft_exit_error();
}

void	ft_ordre(char **argv)
{
	int	i;
	int	x;
	int	total;

	i = 0;
	x = 0;
	total = 0;
	while (argv[x])
		x++;
	while (argv[i])
	{
		if (i + 1 != x)
		{
			if (ft_atoi(argv[i]) < ft_atoi(argv[i + 1]))
				total++;
		}
		i++;
	}
	if (total + 1 == x)
		exit(0);
}

int	main(int argc, char **argv)
{
	t_pile	*pilea;
	t_pile	*pileb;

	if (argc < 2)
		exit(0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = delete_element_tab(argv, argc, 0);
	ft_check(argv);
	check_doublon(argv);
	ft_ordre(argv);
	pilea = creat_pile(argv, argc);
	pileb = init_pile();
	traitement(pilea, pileb);
}
