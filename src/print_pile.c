/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:51:48 by smakni            #+#    #+#             */
/*   Updated: 2018/11/23 15:52:58 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_pile(s_pile *tab)
{
	int i;
	static int count = 0;

	i = tab->len_t - 1;
	ft_printf("\n|---------------------|\n");
	while (i >= 0)
	{
		if (i > tab->len_a - 1)
			ft_printf("%-11.d|", tab->list_a[i]);
		else
			ft_printf("%-11d|", tab->list_a[i]);
		if (i > tab->len_b - 1)
			ft_printf("%11.d\n", tab->list_b[i]);
		else	
			ft_printf("%11d\n", tab->list_b[i]);
		i--;
	}
	ft_printf("|---------------------|\n");
	ft_printf("|pile_a         pile_b|\n");
	ft_printf("|>>>>>>>[%5d]<<<<<<<|\n", count++);
	ft_printf("|---------------------|\n");
	ft_printf("|operation >> ");
}
