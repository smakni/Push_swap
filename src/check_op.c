/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:45:57 by smakni            #+#    #+#             */
/*   Updated: 2018/11/26 20:40:42 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		first_a(s_pile *tab, s_ret *ret, int p)
{
	int i;

	i = 0;
	ft_strdel(&ret->tmp);
	ret->tmp = ft_memalloc(1);
	ft_printf("\nDEBUG\n");
	ft_printf("tab->a[p] = %d\n", tab->a[p]);
	ft_printf("tab->a = %d < tab->b = %d\n", tab->a[p], tab->b[tab->lb - 1 - i]);
	while (tab->a[p] > tab->b[tab->lb - 1 - i] && tab->lb - 1 - i > 0)
	{	
		i++;
	}
	ft_printf("i = %d\n", i);
	ft_printf("tab->a = %d < tab->b = %d\n", tab->a[p], tab->b[tab->lb - 1 - i]);
	if (i != 0 && i <= tab->lb / 2)
	{
		while (i > 0)
		{
			ret->tmp = ft_strjoin(ret->tmp, "rb\n");
			i--;
		}
	}
	else if (i != 0)
	{
		while (i > 0)
		{
			ret->tmp = ft_strjoin(ret->tmp, "rrb\n");
			i--;
		}
	}
	i = p;
	if (i >= tab->la / 2)
	{
		while (i < tab->la - 1)
		{	
			ret->tmp = ft_strjoin(ret->tmp, "ra\n");
			i++;
		}
	}
	else
	{	
		while (i >= 0)
		{		
			ret->tmp = ft_strjoin(ret->tmp, "rra\n");
			i--;
		}
	}
	ret->tmp = ft_strjoin_free1(ret->tmp, "pb\n");
	ft_printf("phase2 = %s\n", ret->tmp);
	ft_printf("nb_coups = %d\n", ft_count_n(ret->tmp));
	return (ft_count_n(ret->tmp));
}

void	first_b(s_pile *tab, s_ret *ret, int p)
{
	if (p >= tab->lb / 2)
	{
		while (p < tab->lb - 1)
		{	
			ret->tmp = ft_strjoin(ret->tmp, "rb\n");
			p++;
		}
	}
	else
	{	
		while (p >= 0)
		{		
			ret->tmp = ft_strjoin(ret->tmp, "rrb\n");
			p--;
		}
	}
}

int		ft_count_n(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

void	check_min_max(s_pile *tab, s_ret *ret)
{
	int i;

	i = 0;
	ret->max = tab->a[i];
	ret->min = tab->a[i];
	while (i < tab->la - 1)
	{
		if (tab->a[i] > ret->max)
			ret->max = tab->a[i];
		if (tab->a[i] < ret->min)
			ret->min = tab->a[i];
		i++;
	}
}

int		find_max(s_pile *tab, s_ret *ret)
{
	int i;

	i = tab->lb - 1;
	while (tab->b[i] != ret->max)
		i--;
	return (i);
}

static int	len_x(const char *str, int x, char c)
{
	int count;

	count = 1;
	while (str[x + count] && str[x + count] != c)
		count++;
	return (count);
}

void	exc_op(s_pile *tab, char *str)
{
	int 	i;
	int		len;
	char 	*tmp;

	i = 0;
	tmp = NULL;
	while (str[i])
	{
		len = len_x(str, i, '\n');
		tmp = ft_strsub(str, i, len);
		i += len_x(str, i, '\n') + 1;
		ft_operations_c(tab, tmp);
		ft_strdel(&tmp);
	}
}
