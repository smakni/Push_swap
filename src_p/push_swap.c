/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:12:54 by smakni            #+#    #+#             */
/*   Updated: 2018/11/23 17:34:22 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int main (int ac, char **av)
{
	char	*ret;
	int		i;
	int		j;
	s_pile 	*tab;
	
	ret = ft_memalloc(1);
	tab = ft_memalloc(sizeof(s_pile));
	init_tab(ac, av, tab);
	check_init(tab);
	i = tab->len_a - 1;
	while (tab->list_a[i])
	{
		j = i - 1;
		while (tab->list_a[i] < tab->list[j])
			j--;

	}
	print_pile(tab);
	return (0);
}

