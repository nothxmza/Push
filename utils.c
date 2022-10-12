#include "push_swap.h"

int	ft_atoi(char *str)
{
	int			nb;
	int				sign;

	nb = 0;
	sign = 1;
	while (ft_is_space(*str))
		str++;
	if (ft_is_sign(*str))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
		nb = (nb * 10) + (*str++ - '0');
	if (!ft_is_space(*str) && *str)
			exit(-1);
	nb *= sign;
	return (nb);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}
int	ft_is_space(char a)
{
	if ((a >= 9 && a <= 13) || a == ' ')
		return (1);
	return (0);
}

int	ft_is_sign(char a)
{
	if (a == '+' || a == '-')
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	return (0);
}
char	**delete_element_tab(char **argv, int argc, int pos)
{
	int i;

	i = pos;
	while (i < argc)
	{
		argv[i] = argv[i + 1];
		i++;
	}
	return (argv);
}
int	*sort_tab(int *tab, int size)
{
	int	x;
	int	y;
	int	tmp_list;

	x = 0;
	while (x <= size - 1)
	{
		y = 0;
		while (y <= size - 2)
		{
			if (tab[y] > tab[x])
			{
				tmp_list = tab[x];
				tab[x] = tab[y];
				tab[y] = tmp_list;
			}
			y++;
		}
		x++;
	}
	return (tab);
}