/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitement2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:48:35 by hterras           #+#    #+#             */
/*   Updated: 2022/10/17 15:56:13 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	tri_a(t_pile *pileA)
{
	if (tail(pileA) == 2 && (pileA->first->nbr > pileA->first->next->nbr))
		swap(pileA, 1);
	else
		ft_trois(pileA);
}

static void	operation_pilea(t_pile *pileA, t_pile *pileB, int tmp, int index)
{
	if (index > pileA->first->nbr)
	{
		push_b(pileA, pileB);
		pileB->first->group = tmp;
	}
	else
		rotate(pileA, 1);
}

void	creat_groupa(t_pile *pileA, t_pile *pileB)
{
	int		a;
	int		index;
	int		tmp;
	int		i;

	i = 0;
	tmp = 1;
	index = 0;
	a = tail(pileA);
	while (a > 3)
	{
		index = ft_mediane(pileA);
		while (i < a)
		{
			operation_pilea(pileA, pileB, tmp, index);
			i++;
		}
		i = 0;
		tmp++;
		a = tail(pileA);
	}
	tri_a(pileA);
}
