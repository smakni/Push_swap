/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:02:29 by smakni            #+#    #+#             */
/*   Updated: 2018/12/03 16:01:47 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static	void	step_0(t_pile *tab)
{
	ft_operations(tab, "pb");
	ft_operations(tab, "pb");
	ft_printf("pb\n");
	ft_printf("pb\n");
}

void			place_a(t_pile *tab, t_sol *sol)
{
	int		i;
	int		save;
	int		turns;
	t_sol	*tmp;

	tmp = ft_memalloc(sizeof(t_sol));
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
	free(tmp);
}

static	void	reorganize_b(t_pile *tab, int max, int i)
{
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
}

static	void	final_step(t_pile *tab)
{
	int i;
	int max;

	i = tab->lb - 1;
	max = find_max_in_b(tab);
	while (tab->b[i] != max)
		i--;
	reorganize_b(tab, max, i);
	while (tab->lb > 0)
	{
		ft_operations(tab, "pa");
		ft_printf("pa\n");
	}
}

void			algo_3(t_pile *tab, t_sol *sol)
{
	step_0(tab);
	while (tab->la > 0)
	{
		place_a(tab, sol);
		exc_op(tab, sol);
	}
	final_step(tab);
}
