/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:12:54 by smakni            #+#    #+#             */
/*   Updated: 2018/11/28 16:54:05 by smakni           ###   ########.fr       */
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
	save = first_a(tab, tmp, i--);
	save_solution(tmp, sol);
	while (i >= 0)
	{
		if ((turns = first_a(tab, tmp, i)) < save)
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
	max = check_max(tab);
	while (tab->b[i] != max)
		i--;
	if (i > tab->lb / 2)
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

int 	main(int ac, char **av)
{
	s_pile 	*tab;
	s_sol 	*sol;
	int		i;
	
	i = 0;
	tab = ft_memalloc(sizeof(s_pile));
	sol = ft_memalloc(sizeof(s_sol));
	init_tab(ac, av, tab);
	check_init(tab);
	if (check_pile_a(tab) == 0)
	{
		free_s_tab(tab);
		return (0);
	}
	else
	{
		step_0(tab);
		while (i < tab->la)
		{
			place_a(tab, sol);
			exc_op(tab, sol);
		}
	}
	final_step(tab);
	free_s_tab(tab);
	return (0);
}

