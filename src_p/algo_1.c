/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:44:53 by smakni            #+#    #+#             */
/*   Updated: 2018/11/30 18:22:25 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	algo_1(t_pile *tab)
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
	if (tab->a[2] < tab->a[1] && tab->a[1] < tab->a[0])
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
