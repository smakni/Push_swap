/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:32:56 by smakni            #+#    #+#             */
/*   Updated: 2018/11/22 16:52:54 by smakni           ###   ########.fr       */
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

int		check_dlb(int *a, int cur, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (cur == a[j])
		{	
			ft_printf("error");
			exit(-1);
		}
		j++;
	}
	return (0);
}

void	check_init(s_tab *tab, s_pile *a)
{
	int 	i;
	int		j;

	i = tab->len - 1;
	j = 0;
	while (i >= 0)
	{
		check_nb(tab->arg[i]);
		a->list[j] = ft_atoi(tab->arg[i]);
		check_dlb(a->list, a->list[j], j);
		i--;
		j++;
	}
}

int		checker(s_pile *a, int len)
{
	int i;

	i = len;
	while (i > 0)
	{
		if (a->list[i] < a->list[i - 1])
			i--;
		else
			return (-1);
	}
	return (0);
}

void	print_pile(s_pile *a, s_pile *b, s_tab *tab)
{
	int i;

	i = tab->len - 1;
	ft_printf("[len_a = %d]-----------[len_b = %d]\n", a->len, b->len);
	while (i >= 0)
	{
		ft_printf(" a[%d] = %-15db[%d] = %d\n", i, a->list[i], i, b->list[i]);
		i--;
	}
	ft_printf("operation >> ");
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

void	init_pile(s_pile *a, s_pile *b, s_tab *tab)
{
	a->list = ft_memalloc(sizeof(int) * tab->len);
	a->len = tab->len;
	b->list = ft_memalloc(sizeof(int) * tab->len);;
	b->len = 0;
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
	s_pile 	*a;
	s_pile	*b;
	s_tab	*tab;
	
	tab = ft_memalloc(sizeof(s_tab));
	a = ft_memalloc(sizeof(s_pile));
	b = ft_memalloc(sizeof(s_pile));
	init_tab(ac, av, tab);
	init_pile(a, b, tab);
	check_init(tab, a);
	print_pile(a, b, tab);
	while (get_next_line(0, &line) > 0)
	{
		ft_operations(a, b, line);
		print_pile(a, b, tab);
		ft_strdel(&line);
	}
	if (checker(a, tab->len) == -1)
		ft_printf("KO");
	else
		ft_printf("OK");
	free(a);
	free(b);
	free_s_tab(tab);
	return (0);
}

