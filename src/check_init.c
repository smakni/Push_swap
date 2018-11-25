/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:49:45 by smakni            #+#    #+#             */
/*   Updated: 2018/11/23 15:58:49 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <push_swap.h>

static	int	check_nb(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		   i++;	
		if (ft_isdigit(str[i]) != 1)
		{
			ft_printf("error");
			exit(-1);
		}
		i++;
	}
	return (0);
}

static	int	check_dlb(int *a, int cur, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (cur == a[j])
		{	
			ft_printf("error");
			exit(-1);
		}
		j++;
	}
	return (0);
}

void		check_init(s_pile *tab)
{
	int 	i;
	int		j;

	i = tab->lt - 1;
	j = 0;
	while (i >= 0)
	{
		check_nb(tab->arg[i]);
		tab->a[j] = ft_atoi(tab->arg[i]);
		check_dlb(tab->a, tab->a[j], j);
		i--;
		j++;
	}
}
