/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:53:33 by smakni            #+#    #+#             */
/*   Updated: 2018/12/03 14:21:34 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static	void	init_pile(t_pile *tab)
{
	tab->a = ft_memalloc(sizeof(long) * tab->lt);
	tab->la = tab->lt;
	tab->b = ft_memalloc(sizeof(long) * tab->lt);
	tab->lb = 0;
}

static	int		check_visu(int ac, char **av)
{
	if (ft_strequ("-v", av[ac - 1]) == 1
		|| ft_strequ("-v1", av[ac - 1]) == 1
		|| ft_strequ("-v2", av[ac - 1]) == 1
		|| ft_strequ("-v3", av[ac - 1]) == 1)
		ac--;
	return (ac);
}

void			init_tab(int ac, char **av, t_pile *tab)
{
	int len;
	int i;

	len = 0;
	i = 0;
	ac = check_visu(ac, av);
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
	tab->lt = len;
	init_pile(tab);
}

void			free_s_tab(t_pile *tab)
{
	int i;

	i = 0;
	while (i < tab->lt)
		ft_strdel(&(tab->arg[i++]));
	free(tab->a);
	free(tab->b);
	free(tab->arg);
	free(tab);
}

void			init_solution(t_sol *sol)
{
	sol->sa = 0;
	sol->sb = 0;
	sol->ss = 0;
	sol->ra = 0;
	sol->rb = 0;
	sol->rr = 0;
	sol->rra = 0;
	sol->rrb = 0;
	sol->rrr = 0;
}
