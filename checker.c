/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:32:56 by smakni            #+#    #+#             */
/*   Updated: 2018/11/21 14:57:12 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_nb(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1)
		{
			ft_printf("error");
			exit(-1);
		}
		i++;
	}
	return (0);
}

int		check_dlb(int *pile_a, int cur, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (cur == pile_a[j])
		{	
			ft_printf("error");
			exit(-1);
		}
		j++;
	}
	return (0);
}

int		*check_init(int ac, char **av, int *pile_a)
{
	int 	i;

	i = 0;
	while (i < ac - 1)
	{
		check_nb(av[i + 1]);
		pile_a[i] = ft_atoi(av[i + 1]);
		check_dlb(pile_a, pile_a[i], i);
		i++;
	}
	i = 0;
	return (pile_a);
}

int		checker(int *pile_a, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (pile_a[i] < pile_a[i + 1])
			i++;
		else
			return (-1);
	}
	return (0);
}

void	print_pile(int *pile_a, int *pile_b, int len)
{
	int i;

	i = 0;
	while (i < len)
	{	
		ft_printf("%d	%d\n", pile_a[i], pile_b[i]);
		i++;
	}
	ft_printf("=========\na	b\n");
}

void	ft_swap(int *pile_a)
{
	int tmp;

	tmp = pile_a[0];
	pile_a[0] = pile_a[1];
	pile_a[1] = tmp;
}

int		main(int ac, char **av)
{
	int		i;
	char	*line;
	int 	*pile_a;
	int		*pile_b;

	line = NULL;
	pile_a = ft_memalloc(sizeof(int) * (ac - 1));
	pile_b = ft_memalloc(sizeof(int) * (ac - 1));
	pile_a = check_init(ac, av, pile_a);
	print_pile(pile_a, pile_b, ac - 1);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strequ("sa", line) == 1)
			ft_swap(pile_a);
		print_pile(pile_a, pile_b, ac - 1);
		ft_strdel(&line);
	}
	if (checker(pile_a, ac - 1) == -1)
		ft_printf("KO");
	else
		ft_printf("OK");
	free(pile_a);
	free(pile_b);
	return (0);
}

