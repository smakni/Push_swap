/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:51:48 by smakni            #+#    #+#             */
/*   Updated: 2018/11/26 15:34:39 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_pile(s_pile *tab)
{
	int i;
	static int count = 0;

	i = tab->lt - 1;
	ft_printf("\n|---------------------|\n");
	while (i >= 0)
	{
		if (i > tab->la - 1)
			ft_printf("%-11.d%d", tab->a[i], i);
		else
			ft_printf("%-11d%d", tab->a[i], i);
		if (i > tab->lb - 1)
			ft_printf("%11.d\n", tab->b[i]);
		else	
			ft_printf("%11d\n", tab->b[i]);
		i--;
	}
	ft_printf("|---------------------|\n");
	ft_printf("|pile_a         pile_b|\n");
	ft_printf("|>>>>>>>[%5d]<<<<<<<|\n", count++);
	ft_printf("|---------------------|\n");
}
