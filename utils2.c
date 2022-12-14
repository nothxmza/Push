/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:53:54 by hterras           #+#    #+#             */
/*   Updated: 2022/10/18 11:56:35 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_countwords(char const *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	ft_countalphas(char const *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

static char	**ft_fill(char const *s, char c, int a, int w)
{
	int		i;
	int		j;
	char	**str;

	w = ft_countwords(s, c);
	str = (char **)malloc(sizeof(char *) * (w + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < w)
	{
		while (*s == c)
			s++;
		a = ft_countalphas(s, c);
		str[i] = (char *)malloc(sizeof(char) * (a + 1));
		if (!str[i])
			return (NULL);
		j = 0;
		while (j < a)
			str[i][j++] = *s++;
		str[i][j] = '\0';
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		countwords;
	int		countalphas;

	str = 0;
	countwords = 0;
	countalphas = 0;
	if (!s)
		return (NULL);
	str = ft_fill(s, c, countalphas, countwords);
	return (str);
}

int	tail(t_pile *pile)
{
	int		n;
	t_push	*actuel;

	n = 0;
	if (pile == NULL)
		exit(EXIT_FAILURE);
	actuel = pile->first;
	while (actuel->next != NULL)
	{
		n++;
		actuel = actuel->next;
	}
	return (n);
}
