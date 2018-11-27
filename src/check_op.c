/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:45:57 by smakni            #+#    #+#             */
/*   Updated: 2018/11/27 17:46:11 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	up_a(s_pile *tab, s_ret *ret, int p)
{
	int i;

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
}

int		find_max_in_b(s_pile *tab)
{
	int i;
	int max;

	i = tab->lb - 1;
	max = tab->b[i--];
	while (i >= 0)
	{
		if (tab->b[i] > max)
			max = tab->b[i];
		i--;
	}
	return (max);
}

int		first_a(s_pile *tab, s_ret *ret, int p)
{
	int i;
	int j;
	int min_frame;
	int max_frame;

	i = tab->lb - 1;
	j = 0;
	ft_strdel(&ret->tmp);
	ret->tmp = ft_memalloc(1);
	min_frame = find_min_frame(tab, tab->a[p]);
	max_frame = find_max_frame(tab, tab->a[p]);
//	ft_printf("tab->a[p] = %d\n", tab->a[p]);
	if (tab->a[p] == min_frame)
	{
		max_frame = find_max_in_b(tab);
		while (tab->b[i] != max_frame && i > 0)
		{	
			i--;
			j++;
		}
	}
	else if (tab->a[p] == max_frame)
	{
		while (tab->b[i] != min_frame && i > 0)
		{	
			i--;
			j++;
		}
	}
	else
	{
		while (tab->b[i] != min_frame && i > 0)
		{	
			//ft_printf("tab->b = %d | i = %d\n", tab->b[i], i);	
			i--;
			j++;
		}
	}
	//ft_printf("min = %d | max = %d\n", min_frame, max_frame);
//	ft_printf("j = %d\n", j);
	up_a(tab, ret, p);
	if (j < tab->lb)
	{	
		while (j > 0)
		{
			ret->tmp = ft_strjoin(ret->tmp, "rb\n");
			j--;
		}
	}
	else
	{	
		while (j > 0)
		{
			ret->tmp = ft_strjoin(ret->tmp, "rrb\n");
			j--;
		}
	}
	ret->tmp = ft_strjoin_free1(ret->tmp, "pb\n");
//	ft_printf("op = %s\n", ret->tmp);
//	ft_printf(">>>nb_coups = %d\n\n", ft_count_n(ret->tmp));
	return (ft_count_n(ret->tmp));
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
	while (i <= tab->la - 1)
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
