/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:45:57 by smakni            #+#    #+#             */
/*   Updated: 2018/11/29 21:16:26 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	cycle_a(s_pile *tab, s_sol *sol, int p)
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

static void	cycle_b(s_pile *tab, s_sol *sol, int j)
{
	int i;

	i = 0;
	if (j < tab->lb)
	{	
		while (j-- > 0)
			i++;
		sol->rb = i;
	}
	else
	{	
		while (j-- > 0)
			i++;
		sol->rrb = i;
	}
}

static int	analyse_solution(s_sol *tmp)
{
	s_sol *tmp2;

	tmp2 = ft_memalloc(sizeof(s_sol));
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

int		check_solutions(s_pile *tab, s_sol *tmp, int p)
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

void	save_solution(s_sol *sol, s_sol *tmp)
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

void	exc_op(s_pile *tab, s_sol *sol)
{
	while (sol->sa-- > 0)
	{
		ft_operations(tab, "sa");
		ft_printf("sa\n");
	}
	while (sol->sb-- > 0)
	{
		ft_operations(tab, "sb");
		ft_printf("sb\n");
	}
	while (sol->ss-- > 0)
	{
		ft_operations(tab, "ss");
		ft_printf("sa\n");
	}
	while (sol->ra-- > 0)
	{
		ft_operations(tab, "ra");
		ft_printf("ra\n");
	}
	while (sol->rb-- > 0)
	{
		ft_operations(tab, "rb");
		ft_printf("rb\n");
	}
	while (sol->rr-- > 0)
	{
		ft_operations(tab, "rr");
		ft_printf("rr\n");
	}
	while (sol->rra-- > 0)
	{
		ft_operations(tab, "rra");
		ft_printf("rra\n");
	}
	while (sol->rrb-- > 0)
	{
		ft_operations(tab, "rrb");
		ft_printf("rrb\n");
	}
	while (sol->rrr-- > 0)
	{
		ft_operations(tab, "rrr");
		ft_printf("rrr\n");
	}
	//ft_operations(tab, "pb");
	//ft_printf("pb\n");
}
