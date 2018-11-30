/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:12:54 by smakni            #+#    #+#             */
/*   Updated: 2018/11/30 15:00:06 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


static void	step_0(s_pile *tab)
{
	ft_operations(tab, "pb");
	ft_operations(tab, "pb");
	ft_printf("pb\n");
	ft_printf("pb\n");
}

void	place_a(s_pile *tab, s_sol *sol)
{
	int i;
	int save;
	int	turns;
	s_sol *tmp;

	tmp = ft_memalloc(sizeof(s_sol));
	init_solution(tmp);
	i = tab->la - 1;
	save = check_solutions(tab, tmp, i--);
	save_solution(tmp, sol);
	while (i >= 0)
	{
		if ((turns = check_solutions(tab, tmp, i)) < save)
		{
			save = turns;
			save_solution(tmp, sol);
		}
		i--;
	}
}

static	void final_step(s_pile *tab)
{
	int i;
	int max;

	i = tab->lb - 1;
	max = find_max_in_b(tab);
	while (tab->b[i] != max)
		i--;
	if (i > (tab->lb - 1) / 2)
	{
		i = tab->lb - 1;
		while (tab->b[i] != max)
		{
			ft_operations(tab, "rb");
			ft_printf("rb\n");
		}
	}
	else
	{
		i = tab->lb - 1;	
		while (tab->b[i] != max)
		{
			ft_operations(tab, "rrb");
			ft_printf("rrb\n");
		}
	}
	while (tab->lb > 0)
	{
		ft_operations(tab, "pa");
		ft_printf("pa\n");
	}
}

void	algo_1(s_pile *tab)
{
	if (tab->a[2] > tab->a[1] && tab->a[2] > tab->a[0])
	{
		ft_operations(tab, "ra");
		ft_printf("ra\n");
	}
	if (tab->a[2] > tab->a[1])
	{
		ft_operations(tab, "sa");
		ft_printf("sa\n");
	}
	if (check_pile_a(tab) == 0 || (tab->a[2] < tab->a[1] && tab->a[1] < tab->a[0]))
		return ;
	if (tab->a[2] < tab->a[0])
	{
		ft_operations(tab, "rra");
		ft_printf("rra\n");
		ft_operations(tab, "sa");
		ft_printf("sa\n");
	}
	else
	{		
		ft_operations(tab, "rra");
		ft_printf("rra\n");
	}
}

void	algo_2(s_pile *tab, s_sol *sol)
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

void	algo_3(s_pile *tab, s_sol *sol)
{
	step_0(tab);
	while (tab->la > 0)
	{
		place_a(tab, sol);
		exc_op(tab, sol);
	}
	final_step(tab);
}

int 	main(int ac, char **av)
{
	s_pile 	*tab;
	s_sol 	*sol;
	
	tab = ft_memalloc(sizeof(s_pile));
	sol = ft_memalloc(sizeof(s_sol));
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

