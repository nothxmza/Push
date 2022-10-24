/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:52:55 by hterras           #+#    #+#             */
/*   Updated: 2022/10/18 12:07:23 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_position(t_pile *pile, int value)
{
	int			position;
	t_push		*now;

	now = pile->first;
	position = 0;
	while (now->next != NULL)
	{
		if (now->nbr == value)
			break ;
		position++;
		now = now->next;
	}
	return (position);
}

void	ft_exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

char	**delete_element_tab(char **argv, int argc, int pos)
{
	int	i;

	i = pos;
	while (i < argc)
	{
		argv[i] = argv[i + 1];
		i++;
	}
	return (argv);
}

int	*sort_tab(int *tab, int size)
{
	int	x;
	int	y;
	int	tmp_list;

	x = 0;
	while (x <= size - 1)
	{
		y = 0;
		while (y <= size - 2)
		{
			if (tab[y] > tab[x])
			{
				tmp_list = tab[x];
				tab[x] = tab[y];
				tab[y] = tmp_list;
			}
			y++;
		}
		x++;
	}
	return (tab);
}

void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		write(fd, s, i);
	}
}
