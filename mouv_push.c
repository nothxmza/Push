#include "push_swap.h"

int *
create_tab(t_pile *pile)
{
	t_push	*current;
	int			i;
	int			j;
	int			*tri_tab;

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
	int taile = tail(pile);
	while (taile >= j)
	{
		tri_tab[j] = current->nbr;
		current = current->next;
		j++;
	}
	return (tri_tab);
}
void ra(t_pile *pile,int h)
{
	int *tab = create_tab(pile);
	int *tab2;
	int tmp = 0;
	int i = 0;
	clear(pile);
	while(tab[i])
		i++;
	tmp = tab[0];
	tab2 = NULL;
	tab2 = malloc(sizeof(int) * i);
	int j = 0;
	int x = 1;
	//printf("%d\n",i);
	while(x < i)
	{
		tab2[j++] = tab[x++];
	}
	tab2[j] = tmp;
	
	//printf("%d %d\n",tab2[2],tab[2]);
	pile = insertion_pl2(tab2,pile, j);
	//afficherListe(pile);
	free(tab);
	free(tab2);
	if(h)
		printf("ra\n");
	else
		printf("rb\n");
	//return (pile);
	//tab2[i] = tmp;
}
void rra(t_pile *pile,int h)
{
	int *tab = create_tab(pile);
	int *tab2;
	int tmp = 0;
	int i = 0;
	clear(pile);
	while(tab[i])
		i++;
	tmp = tab[i - 1];
	tab2 = NULL;
	tab2 = malloc(sizeof(int) * i);
	int j = 1;
	int x = 0;
	//printf("%d\n",i);
	tab2[0] = tmp;
	while(x < i - 1)
	{
		tab2[j++] = tab[x++];
	}
	pile = insertion_pl2(tab2,pile, j - 1);
	free(tab);
	free(tab2);
	//afficherListe(pile);
	if(h)
		printf("rra\n");
	else
		printf("rrb\n");
	//tab2[i] = tmp;
}

void swap(t_pile *p, int i)
{
	int tmp = 0;
	
	tmp = p->first->nbr;
	p->first->nbr = p->first->next->nbr;
	p->first->next->nbr = tmp;
	//afficherListe(p);
	if(i)
		printf("sa\n");
	else
		printf("sb\n");
}

void sswap(t_pile *pileA,t_pile *pileB)
{
	swap(pileA,1);
	swap(pileB,0);
}

void push_b(t_pile *pileA,t_pile *pileB)
{
	t_push *tmp;

	tmp = pileA->first;
	pileA->first = pileA->first->next;
	tmp->next = pileB->first;
	pileB->first = tmp;
	printf("pb\n");

}
void push_a(t_pile *pileA,t_pile *pileB)
{
	t_push *tmp;

	tmp = pileB->first;
	pileB->first = pileB->first->next;
	tmp->next = pileA->first;
	pileA->first = tmp;
	printf("pa\n");

}
void	reverse_rotate(t_pile *stack, int i)
{
	t_push	*tmp;
	t_push	*dsp;

	dsp = stack->first;
	while (dsp->next)
	{
		tmp = dsp;
		dsp = dsp->next;
	}
	dsp->next = stack->first->next;
	stack->first->nbr = dsp->nbr;
	tmp->next = NULL;
	if (i == 1)
		printf("rra\n");
	else if (i == 0)
		printf("rrb\n");
}

/*t_push *t = NULL;
	int i = tail(pileA);
	int x = 1;
	int value = 0;
	int *tab2;
	int *tab = create_tab(pileB);
	int j = 0;
	value = tab[0];
	tab2 = malloc(sizeof(int) * i);
	if(i == 1)
	{
		while(x < i)
		{
			printf("L%d\n",tab[x]);
			tab2[j++] = tab[x++];
		}
	}
	while(x <= i)
	{
		//printf("L%d\n",tab[x]);
		tab2[j++] = tab[x++];
	}
	clear(pileB);
	pileB = insertion_pl2(tab2,pileB,j);
	free(tab);
	free(tab2);
	insertion2(pileA,value);
	//afficherListe(pileA);
	printf("pa\n");*/
