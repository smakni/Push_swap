/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_executer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:38:03 by smakni            #+#    #+#             */
/*   Updated: 2018/11/30 18:26:27 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static	void	smart_rotate(t_pile *tab, t_sol *sol)
{
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
}

static	void	smart_reverse_rotate(t_pile *tab, t_sol *sol)
{
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
}

void			exc_op(t_pile *tab, t_sol *sol)
{
	smart_rotate(tab, sol);
	smart_reverse_rotate(tab, sol);
	ft_operations(tab, "pb");
	ft_printf("pb\n");
}
