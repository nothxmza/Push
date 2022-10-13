#include "push_swap.h"

static int ft_mediane(t_pile *pile)
{
	int *tab = NULL;
	int a  = tail(pile);
	int x = 0;
	int index = 0;
	if(pile == NULL)
		return(0);
	tab = create_tab(pile);
	tab = sort_tab(tab,a);
	if(a % 2)
		x = a/2 + 1;
	else
		x = a/2;
	index = tab[x - 1];
	free(tab);
	return(index);
}

void ft_trois(t_pile *pile)
{
	int first = pile->first->nbr;
	int second = pile->first->next->nbr;
	int last = pile->first->next->next->nbr;
	if(first > second &&  second < last && first < last)
		swap(pile,1);
	if(first > second &&  second < last && first > last)
		rotate(pile,1);
	if(first > second && second > last)
	{
		rotate(pile,1);
		swap(pile,1);
	}
	if(first < second && first > last)
	{
		rotate(pile,1);
		rotate(pile,1);
	}
	if(first < second && second > last && first < last)
	{
		revers_rotate(pile,1);
		swap(pile,1);
	}
}

static void two_verif(t_pile  *pile)
{
	if(pile->first->nbr < pile->first->next->nbr)
		swap(pile,0);
}

void static creat_groupA(t_pile *pileA, t_pile *pileB)
{
	t_push *t;
	int a;
	int b;
	int x;
	int index;
	int *tab_tmp;
	int tmp;
	int i;

	i = 0;
	x = 0;
	tmp = 1;
	index = 0;
	a = tail(pileA);
	b = tail(pileB);
	tab_tmp =  NULL;
	while(a > 3)
	{
		index = ft_mediane(pileA);
		//afficherListe(pileA);
		while (i < a)
		{
			if(index > pileA->first->nbr)
			{
				push_b(pileA,pileB);
				pileB->first->group = tmp;
			}
			else
				rotate(pileA,1);
			i++;
		}
		i = 0;
		tmp++;
		free(tab_tmp);
		//printf("L %d\n",a);
		a = tail(pileA);
	}
	if(tail(pileA) == 2 && (pileA->first->nbr > pileA->first->next->nbr))
		swap(pileA,1);
	else
		ft_trois(pileA);
}

void traitement(t_pile *pileA,t_pile *pileB)
{
	int a;
	int b;

	a = tail(pileA);
	b = tail(pileB);
	int i = 0;
	if(a < 3)
		swap(pileA,1);
	if(a == 3)
		ft_trois(pileA);
	else
	{
		int	*sorted_tab;
		int	pos_max;

		sorted_tab = NULL;
		pos_max = 0;
		creat_groupA(pileA,pileB);
		
		while(tail(pileB) > 0)
		{
			sorted_tab = create_tab(pileB);
			sorted_tab = sort_tab(sorted_tab,tail(pileB));
			pos_max = search_position(pileB,sorted_tab[tail(pileB) - 1]);
			if(pos_max  <= tail(pileB) / 2)
			{
				while(pos_max > 0)
				{
					rotate(pileB, 0);
					pos_max--;
				}
			}
			else
			{
				pos_max = tail(pileB) - pos_max;
				while(pos_max > 0)
				{
					revers_rotate(pileB,0);
					pos_max--;
				}
			}
			push_a(pileA,pileB);
		}
	}

}
