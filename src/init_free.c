/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:53:33 by smakni            #+#    #+#             */
/*   Updated: 2018/11/26 17:29:05 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	init_pile(s_pile *tab)
{
	tab->a = ft_memalloc(sizeof(int) * tab->lt);
	tab->la = tab->lt;
	tab->b = ft_memalloc(sizeof(int) * tab->lt);
	tab->lb = 0;
}

void		init_ret(s_pile *tab, s_ret *ret)
{
	ret->ret = ft_memalloc(1);
	ret->tmp = ft_memalloc(1);
	check_min_max(tab, ret);
}

void		init_tab(int ac, char **av, s_pile *tab)
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
	tab->lt = len;
	init_pile(tab);
}

void	free_s_tab(s_pile *tab)
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
