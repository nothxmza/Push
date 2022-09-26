#include "push_swap.h"

void ft_trois(t_pile *pile)
{
	if(pile->first->nbr > pile->first->next->nbr &&  pile->first->next->nbr < pile->first->next->next->nbr && pile->first->nbr < pile->first->next->next->nbr)
		swap(pile,1);
	if(pile->first->nbr > pile->first->next->nbr &&  pile->first->next->nbr < pile->first->next->next->nbr && pile->first->nbr > pile->first->next->next->nbr)
		ra(pile,1);
	if(pile->first->nbr > pile->first->next->nbr && pile->first->next->nbr > pile->first->next->next->nbr)
	{
		ra(pile,1);
		swap(pile,1);
	}
	if(pile->first->nbr < pile->first->next->nbr && pile->first->nbr > pile->first->next->next->nbr)
	{
		ra(pile,1);
		ra(pile,1);
	}
	if(pile->first->nbr < pile->first->next->nbr && pile->first->next->nbr > pile->first->next->next->nbr && pile->first->nbr < pile->first->next->next->nbr)
	{
		rra(pile,1);
		swap(pile,1);
	}
}

void traitement(t_pile *pileA,t_pile *pileB)
{
	int a = 0;
	int b = 0;
	t_push *t;

	a = tail(pileA);
	b = tail(pileB);
	int x = 0;
	int index = 0;
	int *tab_tmp =  NULL;


	int tmp = 1;
	int i = 0;
	if(a < 3)
		swap(pileA,1);
	if(a == 3)
		ft_trois(pileA);
	while(a > 3)
	{
		tab_tmp = create_tab(pileA);
		tab_tmp = ft_sort_int_tab(tab_tmp,a);
		x = a/2;
		index = tab_tmp[x- 1];
		while (i < a)
		{
			if(index >= pileA->first->nbr)
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
	if(tail(pileA) == 3)
		ft_trois(pileA);
	if(tail(pileA)== 2)
	{
		if(pileA->first->nbr > pileA->first->next->nbr)
			swap(pileA,0);
	}
	/*i = 0;
	while (i < tail(pileB))
	{
		if (pileB->first->group == tmp - 1)
			push_a(pileA, pileB);
		i++;
	}*/
	//si le nombre en haut de la pile est le plus grand ou et il y a que un nombre dns la pile push_a 
	//si il ya 2 chiffre dans un groupe de la pile b on fait une focntion pour vérifier si le plus grand est first sinon swap
	//remettre les plus grands dans la pileA
	printf("\n");
	afficherListe(pileA);
	printf("%dpileA\n",tmp);
	afficherListe(pileB);
	printf("pileB\n");
} 