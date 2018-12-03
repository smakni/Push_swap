/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:32:56 by smakni            #+#    #+#             */
/*   Updated: 2018/12/03 14:04:23 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		main(int ac, char **av)
{
	char	*line;
	t_pile	*tab;

	if (ac == 1)
		return (0);
	line = NULL;
	tab = ft_memalloc(sizeof(t_pile));
	init_tab(ac, av, tab);
	check_init(tab);
	print_stack(tab, av[ac - 1], line);
	while (get_next_line(0, &line) > 0)
	{
		ft_operations(tab, line);
		print_stack(tab, av[ac - 1], line);
		ft_strdel(&line);
	}
	if (check_pile_a(tab) == -1)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free_s_tab(tab);
	return (0);
}
