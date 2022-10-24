/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:47:41 by hterras           #+#    #+#             */
/*   Updated: 2022/10/19 13:11:55 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_push
{
	int				nbr;
	int				group;
	struct s_push	*next;
}					t_push;

typedef struct s_pile
{
	t_push	*first;
}				t_pile;

//init pill
t_pile			*init_pile(void);
t_pile			*insertion(t_pile *liste, int nbr);
void			afficherliste(t_pile *liste);
t_pile			*insertion_pl(char **argv, t_pile *pile, int argc);
t_pile			*creat_pile(char **argv, int argc);
t_pile			*insertion_pl2(int *argv, t_pile *pile, int argc);
void			insertion2(t_pile *pile, int nbr);

//parsing
void			check_doublon(char **argv);
void			ft_ordre(char **argv);

//utils
char			**delete_element_tab(char **argv, int argc, int pos);
long long		ft_atoi(char *str);
int				ft_isdigit(int c);
int				ft_is_space(char a);
int				ft_is_sign(char a);
int				ft_isalnum(int c);
char			**ft_split(char const *s, char c);
int				tail(t_pile *pile);
void			clear(t_pile *p);
int				*sort_tab(int *tab, int size);
int				*create_tab(t_pile *pile);
void			ft_putstr_fd(char *s, int fd);
int				search_position(t_pile *pile, int value);
void			ft_exit_error(void);

//MOUV
void			rotate(t_pile *pile, int h);
void			revers_rotate(t_pile *pile, int h);
void			swap(t_pile *p, int i);
void			sswap(t_pile *p, t_pile *b);
void			push_b(t_pile *pileA, t_pile *pileB);
void			push_a(t_pile *pileA, t_pile *pileB);
void			reverse_rotate(t_pile *stack, int i);
void			push(t_pile *pile, int value);

//traitement
void			traitement(t_pile *pileA, t_pile *pileB);
int				ft_mediane(t_pile *pile);
void			ft_trois(t_pile *pile);
void			creat_groupa(t_pile *pileA, t_pile *pileB);

#endif