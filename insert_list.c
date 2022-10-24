/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:32:30 by hterras           #+#    #+#             */
/*   Updated: 2022/10/14 13:35:50 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*insertion_pl2(int *argv, t_pile *pile, int i)
{
	while (i >= 0)
		pile = insertion(pile, argv[i--]);
	return (pile);
}

t_pile	*insertion_pl(char **argv, t_pile *pile, int argc)
{
	int	i;
	int	x;

	i = argc - 2;
	if (argc > 2)
	{
		while (i >= 0)
			pile = insertion(pile, ft_atoi(argv[i--]));
	}
	else
	{
		i = 0;
		x = 0;
		while (argv[i])
			i++;
		i -= 1;
		while (i >= 0)
			pile = insertion(pile, ft_atoi(argv[i--]));
	}
	return (pile);
}

t_pile	*insertion(t_pile *pile, int nbr)
{
	t_push	*new;

	new = malloc(sizeof(*new));
	if (pile == NULL || new == NULL)
		exit(EXIT_FAILURE);
	new->nbr = nbr;
	new->group = 0;
	new->next = pile->first;
	pile->first = new;
	return (pile);
}

void	insertion2(t_pile *pile, int nbr)
{
	t_push	*new;

	new = malloc(sizeof(*new));
	if (pile == NULL || new == NULL)
		exit(EXIT_FAILURE);
	new->nbr = nbr;
	new->next = pile->first;
	pile->first = new;
}
