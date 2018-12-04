/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:12:54 by smakni            #+#    #+#             */
/*   Updated: 2018/12/04 15:07:18 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static	void	chose_algo(t_pile *tab, t_sol *sol)
{
	if (tab->lt <= 3)
		algo_1(tab);
	else if (tab->lt <= 5)
		algo_2(tab, sol);
	else if (tab->lt > 5)
		algo_3(tab, sol);
}

int				main(int ac, char **av)
{
	t_pile	*tab;
	t_sol	*sol;

	if (ac == 1)
		return (0);
	if (!(tab = ft_memalloc(sizeof(t_pile))))
		exit(-1);
	if (!(sol = ft_memalloc(sizeof(t_sol))))
		exit(-1);
	init_tab(ac, av, tab);
	check_init(tab);
	if (check_pile_a(tab) == 0)
	{
		free(sol);
		free_s_tab(tab);
		return (0);
	}
	chose_algo(tab, sol);
	free_s_tab(tab);
	free(sol);
	return (0);
}
