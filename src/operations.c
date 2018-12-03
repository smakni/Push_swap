/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:42:44 by smakni            #+#    #+#             */
/*   Updated: 2018/12/03 17:33:14 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		ft_operations(t_pile *tab, char *line)
{
	if (ft_strequ("sa", line) == 1 || ft_strequ("sb", line) == 1
			|| ft_strequ("ss", line) == 1)
		ft_swap(tab, line);
	else if (ft_strequ("pa", line) == 1 || ft_strequ("pb", line) == 1)
		ft_push(tab, line);
	else if (ft_strequ("ra", line) == 1 || ft_strequ("rb", line) == 1
			|| ft_strequ("rr", line) == 1)
		ft_rotate(tab, line);
	else if (ft_strequ("rra", line) == 1 || ft_strequ("rrb", line) == 1
			|| ft_strequ("rrr", line) == 1)
		ft_rotate_r(tab, line);
	else
	{
		ft_printf("Error");
		exit(-1);
	}
	return (0);
}

void	ft_swap(t_pile *tab, char *line)
{
	int tmp;

	tmp = 0;
	if (tab->la > 1 && (line[1] == 'a' || line[1] == 's'))
	{
		tmp = tab->a[tab->la - 1];
		tab->a[tab->la - 1] = tab->a[tab->la - 2];
		tab->a[tab->la - 2] = tmp;
	}
	if (tab->lb > 1 && (line[1] == 'b' || line[1] == 's'))
	{
		tmp = tab->b[tab->lb - 1];
		tab->b[tab->lb - 1] = tab->b[tab->lb - 2];
		tab->b[tab->lb - 2] = tmp;
	}
}

void	ft_push(t_pile *tab, char *line)
{
	if (tab->lb > 0 && line[1] == 'a')
	{
		tab->lb--;
		tab->a[tab->la] = tab->b[tab->lb];
		tab->b[tab->lb] = 0;
		tab->la++;
	}
	if (tab->la > 0 && line[1] == 'b')
	{
		tab->la--;
		tab->b[tab->lb] = tab->a[tab->la];
		tab->a[tab->la] = 0;
		tab->lb++;
	}
}

void	ft_rotate(t_pile *tab, char *line)
{
	int tmp;
	int i;

	if (tab->la > 0 && (line[1] == 'a' || line[1] == 'r'))
	{
		i = tab->la - 1;
		while (i > 0)
		{
			tmp = tab->a[i - 1];
			tab->a[i - 1] = tab->a[i];
			tab->a[i] = tmp;
			i--;
		}
	}
	if (tab->lb > 0 && (line[1] == 'b' || line[1] == 'r'))
	{
		i = tab->lb - 1;
		while (i > 0)
		{
			tmp = tab->b[i - 1];
			tab->b[i - 1] = tab->b[i];
			tab->b[i] = tmp;
			i--;
		}
	}
}

void	ft_rotate_r(t_pile *tab, char *line)
{
	int tmp;
	int i;

	if (tab->la > 0 && (line[2] == 'a' || line[2] == 'r'))
	{
		i = 0;
		while (i < tab->la - 1)
		{
			tmp = tab->a[i + 1];
			tab->a[i + 1] = tab->a[i];
			tab->a[i] = tmp;
			i++;
		}
	}
	if (tab->lb > 0 && (line[2] == 'b' || line[2] == 'r'))
	{
		i = 0;
		while (i < tab->lb - 1)
		{
			tmp = tab->b[i + 1];
			tab->b[i + 1] = tab->b[i];
			tab->b[i] = tmp;
			i++;
		}
	}
}
