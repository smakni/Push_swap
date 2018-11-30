/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:54:24 by smakni            #+#    #+#             */
/*   Updated: 2018/11/30 18:22:41 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	algo_2(t_pile *tab, t_sol *sol)
{
	init_solution(sol);
	cycle_a(tab, sol, find_i_min_in_a(tab));
	exc_op(tab, sol);
	if (tab->lt == 5)
	{
		init_solution(sol);
		cycle_a(tab, sol, find_i_min_in_a(tab));
		exc_op(tab, sol);
	}
	algo_1(tab);
	ft_operations(tab, "pa");
	ft_printf("pa\n");
	if (tab->lt == 5)
	{
		ft_operations(tab, "pa");
		ft_printf("pa\n");
	}
}
