/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:40:53 by hterras           #+#    #+#             */
/*   Updated: 2022/10/14 14:00:58 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_tab(t_pile *pile)
{
	t_push		*current;
	int			i;
	int			j;
	int			*tri_tab;
	int			taile;

	i = 0;
	j = 0;
	tri_tab = NULL;
	current = pile->first;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	current = pile->first;
	tri_tab = malloc(sizeof(int) * i);
	taile = tail(pile);
	while (taile >= j)
	{
		tri_tab[j] = current->nbr;
		current = current->next;
		j++;
	}
	return (tri_tab);
}

void	rotate(t_pile *pile, int h)
{
	int	*tab;
	int	*tab2;
	int	tmp;
	int	j;
	int	x;

	tab = create_tab(pile);
	tmp = tab[0];
	tab2 = malloc(sizeof(int) * tail(pile));
	j = 0;
	x = 1;
	while (x < tail(pile))
		tab2[j++] = tab[x++];
	tab2[j] = tmp;
	clear(pile);
	pile = insertion_pl2(tab2, pile, j);
	free(tab);
	free(tab2);
	if (h)
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
}

void	revers_rotate(t_pile *pile, int h)
{
	int	*tab;
	int	*tab2;
	int	tmp;
	int	j;
	int	x;

	j = 1;
	x = 0;
	tmp = 0;
	tab = create_tab(pile);
	tmp = tab[tail(pile) - 1];
	tab2 = NULL;
	tab2 = malloc(sizeof(int) * tail(pile));
	tab2[0] = tmp;
	while (x < tail(pile) - 1)
		tab2[j++] = tab[x++];
	clear(pile);
	pile = insertion_pl2(tab2, pile, j - 1);
	free(tab);
	free(tab2);
	if (h)
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
}

void	swap(t_pile *p, int i)
{
	int	tmp;

	tmp = 0;
	tmp = p->first->nbr;
	p->first->nbr = p->first->next->nbr;
	p->first->next->nbr = tmp;
	if (i)
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}

void	sswap(t_pile *pileA, t_pile *pileB)
{
	swap(pileA, 1);
	swap(pileB, 0);
}
