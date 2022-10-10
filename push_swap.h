#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
typedef struct s_push
{
	int  nbr;
	int group;
	struct s_push *next;
}				t_push;

typedef struct s_pile
{
	t_push *first;
}				t_pile;

//init pill
t_pile *init_pile();
t_pile *insertion(t_pile *liste, int nbr);
void afficherListe(t_pile *liste);
t_pile *insertion_pl(char **argv, t_pile *pile,int argc);
t_pile *creat_pile(char **argv,int argc);
t_pile *insertion_pl2(int *argv, t_pile *pile,int argc);
void insertion2(t_pile *pile, int nbr);

//parsing
void check_doublon(char **argv);
void ft_ordre(char **argv,int argc);

//utils
char	**delete_element_tab(char **argv, int argc, int pos);
int		ft_atoi(char *str);
int		ft_isdigit(int c);
int		ft_is_space(char a);
int		ft_is_sign(char a);
int		ft_isalnum(int c);
char	**ft_split(char const *s, char c);
int 	tail(t_pile *pile);
void 	clear(t_pile *p);
int	*ft_sort_int_tab(int *tab, int size);
int *create_tab(t_pile *pile);
void	ft_putstr_fd(char *s, int fd);

//MOUV
void rotate(t_pile *pile,int h);
void revers_rotate(t_pile *pile,int h);
void swap(t_pile *p,int i);
void sswap(t_pile *p,t_pile *b);
void push_b(t_pile *pileA, t_pile *pileB);
void push_a(t_pile *pileA,t_pile *pileB);
void	reverse_rotate(t_pile *stack, int i);

//traitement
void traitement(t_pile *pileA,t_pile *pileB);
void ft_trois(t_pile *pile);

#endif