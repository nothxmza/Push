#include "push_swap.h"

static void ft_check(char **argv)
{
	int i = 0;
	int x = 0;
	while(argv[i])
	{
		while(argv[i][x])
		{
			if(!ft_isalnum(argv[i][x]) || (argv[i][x] == '-' && !argv[i][x + 1]))
			{
				printf("error: not only digit");
				exit(0);
			}
			if(argv[i][x] == '-' && argv[i][x + 1] == '-')
			{
				printf("error: not only digit");
				exit(0);
			}
			x++;
		}
		x = 0;
		i++;
	}
}

void check_doublon(char **argv)
{
	int i;
	int x;
	int j;
	int total;

	i = 0;
	j = 0;
	total = 0;
	x = 0;
	while(argv[i])
	{
		while(argv[x])
		{
			if(strcmp(argv[i],argv[x]) == 0)
				j+=1;
			if(j > 1)
				total++;
			x++;
		}
		j = 0;
		x = 0;
		i++;
	}
	if(total > 1)
	{
		printf("ERROR  TOTAL = %d\n",total);
		exit(0);
	}
}

void ft_ordre(char **argv, int argc)
{
	int i = 0;
	int x= 0;
	int j = 0;
	int total = 0;
	while(argv[x])
		x++;
	while(argv[i])
	{
		if(i + 1 != x)
		{
			if(ft_atoi(argv[i]) < ft_atoi(argv[i + 1]))
			{
				//printf("%s < %s %d\n",argv[i],argv[i+1],argc);
				total++;
			}
		}
		/*while(argv[x])
		{
			if(ft_atoi(argv[i]) < ft_atoi(argv[x]) && ft_atoi(argv[i]) != ft_atoi(argv[x]))
				j++;
			if(ft_atoi(argv[i]) > ft_atoi(argv[x]) && ft_atoi(argv[i]) != ft_atoi(argv[x]))
				j--;
			printf("%d < %d  J=(%d) %d\n",ft_atoi(argv[i]),ft_atoi(argv[x]),j,argc);
			if(j < 0)
				total =1;
			x++;
		}
		x = 0;*/
		i++;
	}
	if(total + 1 == x)
	{
		printf("ERROR dans l'ordre");
		exit(0);
	}
	//printf("\nTOTAL : %d\n",total);
}

int main(int argc,char **argv)
{
	t_pile *pileA;
	t_pile *pileB;


	if(argc < 2)
		exit(0);
	if(argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = delete_element_tab(argv,argc,0);
	ft_check(argv);
	check_doublon(argv);
	ft_ordre(argv,argc);
	pileA = creat_pile(argv,argc);
	pileB = init_pile(pileB);
	//afficherListe(pileA);
	traitement(pileA,pileB);
	//printf("%lu\n", strlen(nbr));
}