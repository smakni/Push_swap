/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:12:54 by smakni            #+#    #+#             */
/*   Updated: 2018/11/23 17:34:22 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	smart_swap(s_pile *tab)
{
	if (tab->b[0] > tab->b[1] && tab->a[tab->la - 1] > tab->a[tab->la - 2])
		ft_swap_p(tab, "ss");
	else if (tab->b[0] > tab->b[1])
		ft_swap_p(tab, "sb");
	else if (tab->a[tab->la - 1] > tab->a[tab->la - 2])
		ft_swap_p(tab, "sa");
}

void	test_op(s_pile *tab)
{
	ft_push_p(tab, "pb");
	ft_push_p(tab, "pb");
	ft_push_p(tab, "pb");
	ft_push_p(tab, "pb");
}	

void	step_0(s_pile *tab)
{
	ft_push_p(tab, "pb");
	ft_push_p(tab, "pb");
	smart_swap(tab);
}

void	final_step(s_pile *tab)
{
	while (tab->lb > 0)
		ft_push_p(tab, "pa");
}

int 	main(int ac, char **av)
{
	s_pile 	*tab;
	int		i;
	
	i = 0;
	tab = ft_memalloc(sizeof(s_pile));
	init_tab(ac, av, tab);
	check_init(tab);
	if (check_pile_a(tab) == 0)
	{
		free_s_tab(tab);
		return (0);
	}
	else
	{
		step_0(tab);
		while (i < tab->lt)
		{
			if (check_pile_a(tab) == 0)
				break ;
			test_op(tab);
			i++;
		}
		final_step(tab);
	}
	ft_printf("%s\n", tab->ret);
	return (0);
}

