/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:25:54 by hterras           #+#    #+#             */
/*   Updated: 2022/10/17 15:57:57 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*init_pile(void)
{
	t_pile	*pile;
	t_push	*element;

	pile = malloc(sizeof(*pile));
	element = malloc(sizeof(*element));
	if (pile == NULL || element == NULL)
	{
		exit(EXIT_FAILURE);
	}
	element->nbr = 0;
	element->next = NULL;
	pile->first = element;
	return (pile);
}

void	clear(t_pile *p)
{
	t_push	*sup;

	while (p->first->next != NULL)
	{
		sup = p->first;
		p->first = p->first->next;
		free(sup);
	}
}

t_pile	*creat_pile(char **argv, int argc)
{
	t_pile	*pilea;

	pilea = init_pile();
	pilea = insertion_pl(argv, pilea, argc);
	return (pilea);
}

void	afficherliste(t_pile *pile)
{
	t_push	*actuel;

	if (pile == NULL)
		exit(EXIT_FAILURE);
	actuel = pile->first;
	while (actuel->next != NULL)
	{
		printf("T %d : GROUPE :%d\n", actuel->nbr, actuel->group);
		actuel = actuel->next;
	}
}
