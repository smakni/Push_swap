/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:42:44 by smakni            #+#    #+#             */
/*   Updated: 2018/11/21 20:13:25 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int		*ft_push_f(int *tab, int len, int x);
int		*ft_push_b(int *tab, int len, int dif);


void	ft_operations(s_pile *pile_a, s_pile *pile_b, char *line)
{
	if (ft_strequ("sa", line) == 1 || ft_strequ("sb", line) == 1
			|| ft_strequ("ss", line) == 1)
		ft_swap(pile_a, pile_b, line);
	if (ft_strequ("pa", line) == 1 || ft_strequ("pb", line) == 1)
		ft_push(pile_a, pile_b, line);
}

void	ft_swap(s_pile *pile_a, s_pile *pile_b, char *line)
{
	int tmp;

	tmp = 0;
	if (pile_a->len > 1 && (line[1] == 'a' || line[1] == 's'))
	{
		tmp = pile_a->list[0];
		pile_a->list[0] = pile_a->list[1];
		pile_a->list[1] = tmp;
	}
	if (pile_b->len > 1 && (line[1] == 'b' || line[1] == 's'))
	{
		tmp = pile_b->list[0];
		pile_b->list[0] = pile_b->list[1];
		pile_b->list[1] = tmp;
	}
}

void	ft_push(s_pile *pile_a, s_pile *pile_b, char *line)
{
	if (pile_b->len != 0 && line[1] == 'a')
	{
		if (pile_a->list == NULL)
			pile_a->list = ft_memalloc(sizeof(int) * 1 + pile_a->len++);
		else
			pile_a->len++;
		if (pile_a->len == 1)
			pile_a->list[0] = pile_b->list[0];
		else
			pile_a->list = ft_push_f(pile_a->list, pile_a->len - 1, pile_b->list[0]);
		pile_b->list = ft_push_b(pile_b->list, pile_b->len--, 1);
	}
	if (pile_a->len != 0 && line[1] == 'b')
	{
		if (pile_b->list == NULL)
			pile_b->list = ft_memalloc(sizeof(int) * 1 + pile_b->len++);
		else
			pile_b->len++;
		if (pile_b->len == 1)
			pile_b->list[0] = pile_a->list[0];
		else
			pile_b->list = ft_push_f(pile_b->list, pile_b->len - 1, pile_a->list[0]);
		pile_a->list = ft_push_b(pile_a->list, pile_a->len--, 1);
	}
}

	/*
	int i = 0;
	while (i < pile_b->len)
	{
		ft_printf("pile_b[%d] = %d\n", i, pile_b->list[i]);
		i++;
	}
	*/
