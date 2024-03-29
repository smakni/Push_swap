/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:27:21 by smakni            #+#    #+#             */
/*   Updated: 2018/11/30 18:20:31 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		check_pile_a(t_pile *tab)
{
	int i;

	if (tab->la != tab->lt)
		return (-1);
	i = tab->la - 1;
	while (i > 0)
	{
		if (tab->a[i] < tab->a[i - 1])
			i--;
		else
			return (-1);
	}
	return (0);
}
