#include "push_swap.h"

t_pile *init_pile()
{
	t_pile *pile = malloc(sizeof(*pile));
	t_push *element = malloc(sizeof(*element));

	if (pile == NULL || element == NULL)
	{
		exit(EXIT_FAILURE);
	}
	element->nbr = 0;
	element->next = NULL;
	pile->first = element;
	return (pile);
}

t_pile *insertion(t_pile *pile, int nbr)
{
	t_push *new = malloc(sizeof(*new));
	if (pile == NULL || new == NULL)
		exit(EXIT_FAILURE);
	new->nbr = nbr;
	new->group = 0;
	new->next = pile->first;
	pile->first = new;
	return(pile);
}

void insertion2(t_pile *pile, int nbr)
{
	t_push *new = malloc(sizeof(*new));
	if (pile == NULL || new == NULL)
		exit(EXIT_FAILURE);
	new->nbr = nbr;
	new->next = pile->first;
	pile->first = new;
}

void afficherListe(t_pile *pile)
{
	if (pile == NULL)
		exit(EXIT_FAILURE);
	t_push *actuel = pile->first;
	while (actuel->next != NULL)
	{
		printf("T %d : GROUPE :%d\n", actuel->nbr, actuel->group);
		actuel = actuel->next;
	}
}
t_pile *insertion_pl2(int *argv, t_pile *pile,int i)
{
	
	   while(i >= 0)
	   {
			pile = insertion(pile,argv[i--]);
	   }
	return(pile);
}
t_pile *insertion_pl(char **argv, t_pile *pile,int argc)
{
	int i = argc - 2;
	if(argc > 2)
	{
		while(i >= 0)
			pile = insertion(pile,ft_atoi(argv[i--]));
	}
	else
	{
		i = 0;
		int x = 0;
		while(argv[i])
			i++;
	   // printf(" t%d\n",i);.
		i -=1;
		while(i >= 0)
			pile = insertion(pile,ft_atoi(argv[i--]));
	}
	return(pile);
}

t_pile *creat_pile(char **argv,int argc)
{
	t_pile *pileA;
	pileA = init_pile();
	pileA = insertion_pl(argv,pileA,argc);
	return(pileA);
}
void clear(t_pile *p)
{
	while(p->first->next != NULL)
	{
		t_push *sup = p->first;
		p->first = p->first->next;
		free(sup);
	}
}