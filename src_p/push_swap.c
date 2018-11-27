/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:12:54 by smakni            #+#    #+#             */
/*   Updated: 2018/11/27 17:46:14 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


static void	step_0(s_pile *tab, s_ret *ret)
{
	ret->ret = ft_strdup("pb\npb\n");
	ft_operations_p(tab, "pb\n");
	ft_operations_p(tab, "pb\n");
}

void	place_a(s_pile *tab, s_ret *ret)
{
	int i;
	char *tmp;
	int save;
	int	turns;;


	i = tab->la - 1;
	save = first_a(tab, ret, i--);
	tmp = ft_strdup(ret->tmp);
	while (i >= 0)
	{
		if ((turns = first_a(tab, ret, i)) < save)
		{	
			save = turns;
			ft_strdel(&tmp);
			tmp = ft_strdup(ret->tmp);
		}
		i--;
	}
	ft_strdel(&ret->tmp);
	ret->tmp = ft_strdup(tmp);
	ft_strdel(&tmp);
	ret->ret = ft_strjoin_free1(ret->ret, ret->tmp);
}

static	void final_step(s_pile *tab, s_ret *ret)
{
	int i;

	i = tab->lb - 1;
//	ft_printf("final_1");
//	ft_printf("max = %d\n", ret->max);
	while (tab->b[i] != ret->max)
	{
		ret->ret = ft_strjoin_free1(ret->ret, "rb\n");
		ft_operations_c(tab, "rb");
	}
//	print_pile(tab);
	while (tab->lb > 0)
	{
		ret->ret = ft_strjoin_free1(ret->ret, "pa\n");
		ft_operations_c(tab, "pa");
	}
}

int 	main(int ac, char **av)
{
	s_pile 	*tab;
	s_ret	*ret;
	int		i;
	
	i = 0;
	tab = ft_memalloc(sizeof(s_pile));
	ret = ft_memalloc(sizeof(s_ret));
	init_tab(ac, av, tab);
	check_init(tab);
	init_ret(tab, ret);
//	ft_printf("max = %d\n", ret->max);
	if (check_pile_a(tab) == 0)
	{
		free_s_tab(tab);
		return (0);
	}
	else
	{
		step_0(tab, ret);
//		print_pile(tab);
		while (i < tab->la)
		{
			place_a(tab, ret);
			exc_op(tab, ret->tmp);
//			print_pile(tab);
		}
	}
	final_step(tab, ret);
//	print_pile(tab);
	ft_printf("%s\n", ret->ret);
	ft_strdel(&ret->tmp);
	ft_strdel(&ret->ret);
	free_s_tab(tab);
	return (0);
}

