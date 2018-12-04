/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:58:16 by smakni            #+#    #+#             */
/*   Updated: 2018/12/04 14:59:49 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		*ft_tabdup(int *tab, int len)
{
	int i;
	int *tmp;

	i = 0;
	if ((!tmp = ft_memalloc(sizeof(int) * len)))
		return (0);
	while (i < len)
	{
		tmp[i] = tab[i];
		i++;
	}
	return (tmp);
}
