/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:42:44 by smakni            #+#    #+#             */
/*   Updated: 2018/11/23 15:47:42 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_operations(s_pile *tab, char *line)
{
	if (ft_strequ("sa", line) == 1 || ft_strequ("sb", line) == 1
			|| ft_strequ("ss", line) == 1)
		ft_swap(tab, line);
	if (ft_strequ("pa", line) == 1 || ft_strequ("pb", line) == 1)
		ft_push(tab, line);
	if (ft_strequ("ra", line) == 1 || ft_strequ("rb", line) == 1
	   		|| ft_strequ("rr", line) == 1)
		ft_rotate(tab, line);
	if (ft_strequ("rra", line) == 1 || ft_strequ("rrb", line) == 1
	   		|| ft_strequ("rrr", line) == 1)
		ft_rotate_r(tab, line);
}

void	ft_swap(s_pile *tab, char *line)
{
	int tmp;

	tmp = 0;
	if (tab->len_a > 1 && (line[1] == 'a' || line[1] == 's'))
	{
		tmp = tab->list_a[tab->len_a - 1];
		tab->list_a[tab->len_a - 1] = tab->list_a[tab->len_a - 2];
		tab->list_a[tab->len_a - 2] = tmp;
	}
	if (tab->len_b > 1 && (line[1] == 'b' || line[1] == 's'))
	{
		tmp = tab->list_b[tab->len_b - 1];
		tab->list_b[tab->len_b - 1] = tab->list_b[tab->len_b - 2];
		tab->list_b[tab->len_b - 2] = tmp;
	}
}

void	ft_push(s_pile *tab, char *line)
{
	if (tab->len_b > 0 && line[1] == 'a')
	{
		tab->len_b--;
		tab->list_a[tab->len_a] = tab->list_b[tab->len_b];
		tab->list_b[tab->len_b] = 0;
		tab->len_a++;
	}
	if (tab->len_a > 0 && line[1] == 'b')
	{
		tab->len_a--;
		tab->list_b[tab->len_b] = tab->list_a[tab->len_a];
		tab->list_a[tab->len_a] = 0;
		tab->len_b++;
	}
}

void	ft_rotate(s_pile *tab, char *line)
{
	int *tmp;
	int i;

	if (tab->len_a > 0 && (line[1] == 'a' || line[1] == 'r'))
	{
		i = -1;
		tmp = ft_tabdup(tab->list_a, tab->len_a);
		while (++i < tab->len_a - 1)
			tab->list_a[i + 1] = tmp[i];
		tab->list_a[0] = tmp[tab->len_a - 1];
		free(tmp);
	}
	if (tab->len_b > 0 && (line[1] == 'b' || line[1] == 'r'))
	{
		i = -1;
		tmp = ft_tabdup(tab->list_b, tab->len_b);
		while (++i < tab->len_b - 1)
			tab->list_b[i + 1] = tmp[i];
		tab->list_b[0] = tmp[tab->len_b - 1];
		free(tmp);
	}
}		

void	ft_rotate_r(s_pile *tab, char *line)
{
	int *tmp;
	int i;

	if (tab->len_a > 0 && (line[2] == 'a' || line[2] == 'r'))
	{
		i = tab->len_a - 1;
		tmp = ft_tabdup(tab->list_a, tab->len_a);
		while (i > 0)
		{
			tab->list_a[i - 1] = tmp[i];
			i--;
		}
		tab->list_a[tab->len_a - 1] = tmp[0];
		free(tmp);
	}
	if (tab->len_b > 0 && (line[2] == 'b' || line[2] == 'r'))
	{
		i = tab->len_b - 1;
		tmp = ft_tabdup(tab->list_b, tab->len_b);
		while (i > 0)
		{
			tab->list_b[i - 1] = tmp[i];
			i--;
		}
		tab->list_b[tab->len_b - 1] = tmp[0];
		free(tmp);
	}
}		
