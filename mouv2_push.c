/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv2_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:00:31 by hterras           #+#    #+#             */
/*   Updated: 2022/10/19 13:10:09 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_pile *pileA, t_pile *pileB)
{
	t_push	*tmp;

	tmp = pileA->first;
	pileA->first = pileA->first->next;
	tmp->next = pileB->first;
	pileB->first = tmp;
	ft_putstr_fd("pb\n", 1);
}

void	push_a(t_pile *pileA, t_pile *pileB)
{
	t_push	*tmp;

	tmp = pileB->first;
	pileB->first = pileB->first->next;
	tmp->next = pileA->first;
	pileA->first = tmp;
	ft_putstr_fd("pa\n", 1);
}

void	ft_trois(t_pile *pile)
{
	int	second;
	int	last;

	second = pile->first->next->nbr;
	last = pile->first->next->next->nbr;
	if (pile->first->nbr > second && second < last && pile->first->nbr < last)
		swap(pile, 1);
	if (pile->first->nbr > second && second < last && pile->first->nbr > last)
		rotate(pile, 1);
	if (pile->first->nbr > second && second > last)
	{
		rotate(pile, 1);
		swap(pile, 1);
	}
	if (pile->first->nbr < second && pile->first->nbr > last)
	{
		rotate(pile, 1);
		rotate(pile, 1);
	}
	if (pile->first->nbr < second && second > last && pile->first->nbr < last)
	{
		revers_rotate(pile, 1);
		swap(pile, 1);
	}
}
