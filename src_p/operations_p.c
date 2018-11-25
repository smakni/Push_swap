/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:42:44 by smakni            #+#    #+#             */
/*   Updated: 2018/11/23 15:47:42 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_operations_p(s_pile *tab, char *line)
{
	if (ft_strequ("sa", line) == 1 || ft_strequ("sb", line) == 1
			|| ft_strequ("ss", line) == 1)
		ft_swap_p(tab, line);
	if (ft_strequ("pa", line) == 1 || ft_strequ("pb", line) == 1)
		ft_push_p(tab, line);
	if (ft_strequ("ra", line) == 1 || ft_strequ("rb", line) == 1
	   		|| ft_strequ("rr", line) == 1)
		ft_rotate_p(tab, line);
	if (ft_strequ("rra", line) == 1 || ft_strequ("rrb", line) == 1
	   		|| ft_strequ("rrr", line) == 1)
		ft_rotate_r_p(tab, line);
}

void	ft_swap_p(s_pile *tab, char *line)
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
	ft_swap_ret(tab, line);
}

void	ft_push_p(s_pile *tab, char *line)
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
	ft_push_ret(tab, line);
}

void	ft_rotate_p(s_pile *tab, char *line)
{
	int *tmp;
	int i;

	if (tab->la > 0 && (line[1] == 'a' || line[1] == 'r'))
	{
		i = -1;
		tmp = ft_tabdup(tab->a, tab->la);
		while (++i < tab->la - 1)
			tab->a[i + 1] = tmp[i];
		tab->a[0] = tmp[tab->la - 1];
		free(tmp);
	}
	if (tab->lb > 0 && (line[1] == 'b' || line[1] == 'r'))
	{
		i = -1;
		tmp = ft_tabdup(tab->b, tab->lb);
		while (++i < tab->lb - 1)
			tab->b[i + 1] = tmp[i];
		tab->b[0] = tmp[tab->lb - 1];
		free(tmp);
	}
	ft_rotate_ret(tab, line);
}		

void	ft_rotate_r_p(s_pile *tab, char *line)
{
	int *tmp;
	int i;

	if (tab->la > 0 && (line[2] == 'a' || line[2] == 'r'))
	{
		i = tab->la - 1;
		tmp = ft_tabdup(tab->a, tab->la);
		while (i > 0)
		{
			tab->a[i - 1] = tmp[i];
			i--;
		}
		tab->a[tab->la - 1] = tmp[0];
		free(tmp);
	}
	if (tab->lb > 0 && (line[2] == 'b' || line[2] == 'r'))
	{
		i = tab->lb - 1;
		tmp = ft_tabdup(tab->b, tab->lb);
		while (i > 0)
		{
			tab->b[i - 1] = tmp[i];
			i--;
		}
		tab->b[tab->lb - 1] = tmp[0];
		free(tmp);
	}
	ft_rotate_r_ret(tab, line);
}		
