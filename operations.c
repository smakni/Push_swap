/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:42:44 by smakni            #+#    #+#             */
/*   Updated: 2018/11/22 17:04:17 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int		*ft_tabdup(int *tab, int len);

void	ft_operations(s_pile *a, s_pile *b, char *line)
{
	if (ft_strequ("sa", line) == 1 || ft_strequ("sb", line) == 1
			|| ft_strequ("ss", line) == 1)
		ft_swap(a, b, line);
	if (ft_strequ("pa", line) == 1 || ft_strequ("pb", line) == 1)
		ft_push(a, b, line);
	if (ft_strequ("ra", line) == 1 || ft_strequ("rb", line) == 1
	   		|| ft_strequ("rr", line) == 1)
		ft_rotate(a, b, line);
	if (ft_strequ("rra", line) == 1 || ft_strequ("rrb", line) == 1
	   		|| ft_strequ("rrr", line) == 1)
		ft_rotate_r(a, b, line);


}

void	ft_swap(s_pile *a, s_pile *b, char *line)
{
	int tmp;

	tmp = 0;
	if (a->len > 1 && (line[1] == 'a' || line[1] == 's'))
	{
		tmp = a->list[a->len - 1];
		a->list[a->len - 1] = a->list[a->len - 2];
		a->list[a->len - 2] = tmp;
	}
	if (b->len > 1 && (line[1] == 'b' || line[1] == 's'))
	{
		tmp = b->list[b->len - 1];
		b->list[b->len - 1] = b->list[b->len - 2];
		b->list[b->len - 2] = tmp;
	}
}

void	ft_push(s_pile *a, s_pile *b, char *line)
{
	ft_printf("OP1\n");
	if (line[1] == 'a' && b->len > 0)
	{
		b->len--;
		a->list[a->len] = b->list[b->len];
		b->list[b->len] = 0;
		a->len++;
	}
	if (line[1] == 'b'&& a->len > 0)
	{
		a->len--;
		b->list[b->len] = a->list[a->len];
		a->list[a->len] = 0;
		b->len++;
	}
}

void	ft_rotate(s_pile *a, s_pile *b, char *line)
{
	int *tmp;
	int i;

	if (a->len > 0 && (line[1] == 'a' || line[1] == 'r'))
	{
		i = -1;
		tmp = ft_tabdup(a->list, a->len);
		while (++i < a->len - 1)
			a->list[i + 1] = tmp[i];
		a->list[0] = tmp[a->len - 1];
		free(tmp);
	}
	if (b->len > 0 && (line[1] == 'b' || line[1] == 'r'))
	{
		i = -1;
		tmp = ft_tabdup(b->list, b->len);
		while (++i < b->len - 1)
			b->list[i + 1] = tmp[i];
		b->list[0] = tmp[b->len - 1];
		free(tmp);
	}
}		

void	ft_rotate_r(s_pile *a, s_pile *b, char *line)
{
	int *tmp;
	int i;

	if (a->len > 0 && (line[2] == 'a' || line[2] == 'r'))
	{
		i = a->len - 1;
		tmp = ft_tabdup(a->list, a->len);
		while (i > 0)
		{
			a->list[i - 1] = tmp[i];
			i--;
		}
		a->list[a->len - 1] = tmp[0];
		free(tmp);
	}
	if (b->len > 0 && (line[2] == 'b' || line[2] == 'r'))
	{
		i = b->len - 1;
		tmp = ft_tabdup(b->list, b->len);
		while (i > 0)
		{
			b->list[i - 1] = tmp[i];
			i--;
		}
		b->list[b->len - 1] = tmp[0];
		free(tmp);
	}
}		


