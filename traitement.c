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
	tab = ft_sort_int_tab(tab,a);
	if(a % 2)
		x = a/2 + 1;
	else
		x = a/2;
	index = tab[x - 1];
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
		ra(pile,1);
	if(first > second && second > last)
	{
		ra(pile,1);
		swap(pile,1);
	}
	if(first < second && first > last)
	{
		ra(pile,1);
		ra(pile,1);
	}
	if(first < second && second > last && first < last)
	{
		rra(pile,1);
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
		//printf("L %d\n",index);
		while (i < a)
		{
			if(index > pileA->first->nbr)
			{
				push_b(pileA,pileB);
				pileB->first->group = tmp;
			}
			else
				ra(pileA,1);
			i++;
		}
		i = 0;
		tmp++;
		free(tab_tmp);
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
	/*if(a == 5)
	{
		creat_groupA(pileA,pileB);
		if(pileB->first->nbr < pileB->first->next->nbr)
			swap(pileB,0);
		while(i < tail(pileB))
			push_a(pileA,pileB);
	}*/
	else
	{
		/*creat_groupA(pileA,pileB);
		reverse_rotate(pileB,0);
		reverse_rotate(pileB,0);
		reverse_rotate(pileB,0);*/
		creat_groupA(pileA,pileB);
		b = tail(pileB);
		int *tab;
		int index;
		tab = create_tab(pileB);
		tab = ft_sort_int_tab(tab,b);
		index = tab[b - 1];
		int x = 0;
		int z = 0;
		int total = 0;
		while(1)
		{
			b = tail(pileB);
			tab = create_tab(pileB);
			tab = ft_sort_int_tab(tab,b);
			index = tab[b - 1];
			z = ft_mediane(pileB);
			//printf(" M %d\n",z);
			while(x < b)
			{
				//si le plus grand est dans le groupw lw plus grand ra
				//faire autant de rra que de ra
				//si il est pas dedant rra
				//
				if(pileB->first->nbr != index && (total == 0) && (pileB->first->nbr < pileB->first->next->nbr))
				{
					//printf("%d      %d\n",pileB->first->nbr,z);
					ra(pileB,0);
					if(pileB->first->nbr > z)
						total++;
				}
				/*else if(pileB->first->nbr != index && pileB->first->nbr < z)
					rra(pileB,0);*/
				else
				{
					push_a(pileA,pileB);
					//printf("\n%d\n",total);
					while (total > 0)
					{
						rra(pileB,0);
						total--;
					}
					
				}
				x++;
			}
			total = 0;
			x = 0;
			if(b == 0)
			{
				//printf("DONWIOFNOIF");
				break;
			}
			i++;
		}
	}
	afficherListe(pileA);
	printf("pilea\n");
	afficherListe(pileB);
	printf("\npileB\n");
}
