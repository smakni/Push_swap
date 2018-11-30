/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:45:57 by smakni            #+#    #+#             */
/*   Updated: 2018/11/30 18:25:26 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void		cycle_a(t_pile *tab, t_sol *sol, int p)
{
	int i;
	int j;

	i = p;
	j = 0;
	if (i >= tab->la / 2)
	{
		while (i++ < tab->la - 1)
			j++;
		sol->ra = j;
	}
	else
	{
		while (i-- >= 0)
			j++;
		sol->rra = j;
	}
}

static void	cycle_b(t_pile *tab, t_sol *sol, int j)
{
	int i;

	i = 0;
	if (j >= tab->lb / 2)
	{
		while (j++ < tab->lb - 1)
			i++;
		sol->rb = i;
	}
	else
	{
		while (j-- >= 0)
			i++;
		sol->rrb = i;
	}
}

static int	analyse_solution(t_sol *tmp)
{
	t_sol *tmp2;

	tmp2 = ft_memalloc(sizeof(t_sol));
	save_solution(tmp, tmp2);
	if (tmp2->rb > 0 && tmp2->ra > 0)
	{
		while (tmp->rb > 0 && tmp->ra > 0)
		{
			tmp->rr++;
			tmp->ra--;
			tmp->rb--;
		}
	}
	if (tmp2->rrb > 0 && tmp2->rra > 0)
	{
		while (tmp->rrb > 0 && tmp->rra > 0)
		{
			tmp->rrr++;
			tmp->rra--;
			tmp->rrb--;
		}
	}
	return (tmp->ra + tmp->rb + tmp->rr + tmp->rra + tmp->rrb + tmp->rrr);
}

int			check_solutions(t_pile *tab, t_sol *tmp, int p)
{
	int j;
	int min_frame;
	int max_frame;

	init_solution(tmp);
	min_frame = find_min_frame(tab, tab->a[p]);
	max_frame = find_max_frame(tab, tab->a[p]);
	j = check_frames(tab, min_frame, max_frame, p);
	cycle_a(tab, tmp, p);
	cycle_b(tab, tmp, j);
	return (analyse_solution(tmp));
}

void		save_solution(t_sol *sol, t_sol *tmp)
{
	tmp->sa = sol->sa;
	tmp->sb = sol->sb;
	tmp->ss = sol->ss;
	tmp->ra = sol->ra;
	tmp->rb = sol->rb;
	tmp->rr = sol->rr;
	tmp->rra = sol->rra;
	tmp->rrb = sol->rrb;
	tmp->rrr = sol->rrr;
}
