/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:12:54 by smakni            #+#    #+#             */
/*   Updated: 2018/11/30 18:23:33 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		main(int ac, char **av)
{
	t_pile	*tab;
	t_sol	*sol;

	tab = ft_memalloc(sizeof(t_pile));
	sol = ft_memalloc(sizeof(t_sol));
	init_tab(ac, av, tab);
	check_init(tab);
	if (check_pile_a(tab) == 0)
	{
		free_s_tab(tab);
		return (0);
	}
	if (tab->lt <= 3)
		algo_1(tab);
	else if (tab->lt <= 5)
		algo_2(tab, sol);
	else if (tab->lt > 5)
		algo_3(tab, sol);
	free_s_tab(tab);
	free(sol);
	return (0);
}
