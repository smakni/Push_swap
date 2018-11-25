/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:32:56 by smakni            #+#    #+#             */
/*   Updated: 2018/11/23 16:07:43 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		main(int ac, char **av)
{
	char	*line;
	s_pile 	*tab;
	
	tab = ft_memalloc(sizeof(s_pile));
	init_tab(ac, av, tab);
	check_init(tab);
	print_pile(tab);
	while (get_next_line(0, &line) > 0)
	{
		ft_operations_c(tab, line);
		print_pile(tab);
		ft_printf("OP = %s", line);
		ft_strdel(&line);
	}
	if (check_pile_a(tab) == -1)
		ft_printf("KO");
	else
		ft_printf("OK");
	free_s_tab(tab);
	return (0);
}

