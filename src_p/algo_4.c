/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:32:52 by smakni            #+#    #+#             */
/*   Updated: 2018/11/29 21:16:24 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	put_b_max_in_a(s_pile *tab, s_sol *sol, int p)
{
	int i;
	int j;

	i = p;
	j = 0;
	if (i >= tab->lb / 2)
	{
		while (i++ < tab->lb - 1)
			j++;
		sol->rb = j;
	}
	else
	{	
		while (i-- >= 0)
			j++;
		sol->rrb = j;
	}
}

static void	algo_1_b(s_pile *tab)
{
	int i;

	i = tab->la - 1;
	if (tab->a[i] > tab->a[i - 1] && tab->a[i] > tab->a[i - 2])
	{
		ft_operations(tab, "ra");
		ft_printf("ra\n");
	}
	if (tab->a[i] > tab->a[i - 1])
	{
		ft_operations(tab, "sa");
		ft_printf("sa\n");
	}
	if (check_pile_a(tab) == 0)
		return ;
	if (tab->a[i] < tab->a[i - 2])
	{
		ft_operations(tab, "rra");
		ft_printf("rra\n");
		ft_operations(tab, "sa");
		ft_printf("sa");
	}
	else
	{		
		ft_operations(tab, "rra");
		ft_printf("rra\n");
	}
}

void	algo_4(s_pile *tab, s_sol *sol)
{
	int i;

	i = 0;			
	init_solution(sol);
	while (tab->la - 1 >= 0)
	{
		ft_operations(tab, "pb");
		ft_printf("pb\n");
	}
	while (tab->lb - 1 >= 0)
	{
		i = 0;
		while (i < 3)
		{
			init_solution(sol);
			put_b_max_in_a(tab, sol, find_i_max_in_b(tab));
			exc_op(tab, sol);
			ft_operations(tab, "pa");
			ft_printf("pa\n");
			i++;
		}
		algo_1_b(tab);
	}
}
