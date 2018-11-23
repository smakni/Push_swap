/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:58:16 by smakni            #+#    #+#             */
/*   Updated: 2018/11/23 14:01:19 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		*ft_tabcpy(int *tab, int len, int x)
{
	int i;
	int *tmp;

	i = 0;
	tmp = ft_memalloc(sizeof(int) * len + 1);
	tmp[i++] = x;
	while (i < len + 1)
	{
		tmp[i] = tab[i - 1];
		i++;
	}
	return (tmp);
}

int		*ft_tabcpy_b(int *tab, int len)
{
	int i;
	int *tmp;

	i = 0;
	tmp = ft_memalloc(sizeof(int) * len - 1);
	while (i < len)
	{
		tmp[i] = tab[i + 1];
		i++;
	}
	return (tmp);
}


int		*ft_push_f(int *tab, int len, int x)
{
	int *tmp;

	tmp = ft_tabcpy(tab, len, x);
	free(tab);
	return (tmp);
}

int		*ft_push_b(int *tab, int len, int dif)
{
	int *tmp;

	tmp = ft_tabcpy_b(tab, len - dif);
	free(tab);
	return (tmp);
}

int		*ft_tabdup(int *tab, int len)
{
	int i;
	int *tmp;

	i = 0;
	tmp = ft_memalloc(sizeof(int) * len);
	while (i < len)
	{
		tmp[i] = tab[i];
		i++;
	}
	return (tmp);
}
