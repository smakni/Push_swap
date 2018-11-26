/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:12:54 by smakni            #+#    #+#             */
/*   Updated: 2018/11/26 20:40:44 by smakni           ###   ########.fr       */
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
	int j;

	j = 0;
	i = find_max(tab, ret);
	while (tab->b[tab->lb - j] != tab->b[i] && j < tab->lb)
	{
		ret->ret = ft_strjoin_free1(ret->ret, "rb\n");
		ft_operations_c(tab, "rb");
		j++;
		if (tab->b[tab->lb - i] == tab->b[find_max(tab, ret)])
			break ;
	}
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
	if (check_pile_a(tab) == 0)
	{
		free_s_tab(tab);
		return (0);
	}
	else
	{
		step_0(tab, ret);
		print_pile(tab);
		while (i < tab->la)
		{
			if (tab->la == 1 && tab->a[0] == ret->min)
				break ;
			place_a(tab, ret);
			exc_op(tab, ret->tmp);
			print_pile(tab);
		}
	}
	final_step(tab, ret);
	print_pile(tab);
	ft_printf("%s\n", ret->ret);
	ft_strdel(&ret->tmp);
	ft_strdel(&ret->ret);
	free_s_tab(tab);
	return (0);
}

