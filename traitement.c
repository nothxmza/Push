/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:43:42 by hterras           #+#    #+#             */
/*   Updated: 2022/10/24 13:26:26 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	mid(int a)
{
	int	x;

	x = 0;
	if (a < 101)
	{
		if (a % 2)
			x = a / 2 + 1;
		else
			x = a / 2;
	}
	else
	{
		if (a % 2)
			x = a / 6 + 1;
		else
			x = a / 6;
	}
	return (x);
}

int	ft_mediane(t_pile *pile)
{
	int	*tab;
	int	a;
	int	x;
	int	index;

	index = 0;
	x = 0;
	a = tail(pile);
	tab = NULL;
	if (pile == NULL)
		return (0);
	tab = create_tab(pile);
	tab = sort_tab(tab, a);
	x = mid(a);
	index = tab[x - 1];
	free(tab);
	return (index);
}

static void	traitement3(t_pile *pileB, int pos_max)
{
	if (pos_max <= tail(pileB) / 2)
	{
		while (pos_max > 0)
		{
			rotate(pileB, 0);
			pos_max--;
		}
	}
	else
	{
		pos_max = tail(pileB) - pos_max;
		while (pos_max > 0)
		{
			revers_rotate(pileB, 0);
			pos_max--;
		}
	}
}

static void	traitement2(t_pile *pileA, t_pile *pileB)
{
	int	*sorted_tab;
	int	pos_max;

	pos_max = 0;
	sorted_tab = create_tab(pileB);
	sorted_tab = sort_tab(sorted_tab, tail(pileB));
	pos_max = search_position(pileB, sorted_tab[tail(pileB) - 1]);
	traitement3(pileB, pos_max);
	push_a(pileA, pileB);
	free(sorted_tab);
}

void	traitement(t_pile *pileA, t_pile *pileB)
{
	int	a;
	int	b;
	int	i;

	a = tail(pileA);
	b = tail(pileB);
	i = 0;
	if (a < 3)
		swap(pileA, 1);
	if (a == 3)
		ft_trois(pileA);
	else
	{
		creat_groupa(pileA, pileB);
		while (tail(pileB) > 0)
		{
			traitement2(pileA, pileB);
		}
	}
}
