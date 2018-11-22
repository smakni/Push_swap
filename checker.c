/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:32:56 by smakni            #+#    #+#             */
/*   Updated: 2018/11/21 19:44:33 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_nb(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		   i++;	
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

void	check_init(s_tab *tab, s_pile *pile_a)
{
	int 	i;

	i = 0;
	while (i < tab->len)
	{
		check_nb(tab->arg[i]);
		pile_a->list[i] = ft_atoi(tab->arg[i]);
		check_dlb(pile_a->list, pile_a->list[i], i);
		i++;
	}
}

int		checker(s_pile *pile_a, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (pile_a->list[i] < pile_a->list[i + 1])
			i++;
		else
			return (-1);
	}
	return (0);
}

void	print_pile(s_pile *pile_a, s_pile *pile_b)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_printf("len_a = %d / len_b = %d\n", pile_a->len, pile_b->len);
	ft_printf("[a] >> ");
	while (i < pile_a->len)
		ft_printf("[%d]", pile_a->list[i++]);
	ft_printf("\n[b] >> ");
	while (j < pile_b->len)
		ft_printf("[%d]", pile_b->list[j++]);
	ft_printf("\noperation >> ");
}

void		init_tab(int ac, char **av, s_tab *tab)
{
	int len;
	int i;

	len = 0;
	i = 0;
	if (ac == 2)
	{
		tab->arg = ft_strsplit(av[1], ' ');
		while (tab->arg[len] != NULL)
			len++;
	}
	else
	{
		len = ac - 1;
		tab->arg = ft_memalloc(sizeof(char *) * len);
		while (i < len)
		{	
			tab->arg[i] = ft_strdup(av[i + 1]);
			i++;
		}
	}
	tab->len = len;
}

void	init_pile(s_pile *pile_a, s_pile *pile_b, s_tab *tab)
{
	pile_a->list = ft_memalloc(sizeof(int) * tab->len);
	pile_a->len = tab->len;
	pile_b->list = NULL;
	pile_b->len = 0;
}

void	free_s_tab(s_tab *tab)
{
	int i;

	i = 0;
	while (i < tab->len)
		ft_strdel(&(tab->arg[i++]));
	free(tab->arg);
	free(tab);
}

int		main(int ac, char **av)
{
	char	*line;
	s_pile 	*pile_a;
	s_pile	*pile_b;
	s_tab	*tab;
	
	tab = ft_memalloc(sizeof(s_tab));
	pile_a = ft_memalloc(sizeof(s_pile));
	pile_b = ft_memalloc(sizeof(s_pile));
	init_tab(ac, av, tab);
	init_pile(pile_a, pile_b, tab);
	check_init(tab, pile_a);
	print_pile(pile_a, pile_b);
	while (get_next_line(0, &line) > 0)
	{
		ft_operations(pile_a, pile_b, line);
		print_pile(pile_a, pile_b);
		ft_strdel(&line);
	}
	if (checker(pile_a, tab->len) == -1)
		ft_printf("KO");
	else
		ft_printf("OK");
	free(pile_a);
	free(pile_b);
	free_s_tab(tab);
	return (0);
}

