/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:53:33 by smakni            #+#    #+#             */
/*   Updated: 2018/11/23 15:54:23 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	init_pile(s_pile *tab)
{
	tab->list_a = ft_memalloc(sizeof(int) * tab->len_t);
	tab->len_a = tab->len_t;
	tab->list_b = ft_memalloc(sizeof(int) * tab->len_t);
	tab->len_b = 0;
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
	tab->len_t = len;
	init_pile(tab);
}

void	free_s_tab(s_pile *tab)
{
	int i;

	i = 0;
	while (i < tab->len_t)
		ft_strdel(&(tab->arg[i++]));
	free(tab->list_a);
	free(tab->list_b);
	free(tab->arg);
	free(tab);
}
