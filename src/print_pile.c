/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:51:48 by smakni            #+#    #+#             */
/*   Updated: 2018/12/03 14:31:19 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static	void	print_speed(char *opt)
{
	if (opt[2] == '1')
		sleep(1);
	if (opt[2] == '2')
		sleep(2);
	if (opt[2] == '3')
		sleep(3);
}

static	void	print_stack_2(t_pile *tab)
{
	int i;

	i = tab->lt - 1;
	while (i >= 0)
	{
		if (i > tab->la - 1)
			ft_printf("%-11.d|", tab->a[i]);
		else
			ft_printf("%-11d|", tab->a[i]);
		if (i > tab->lb - 1)
			ft_printf("%11.d\n", tab->b[i]);
		else
			ft_printf("%11d\n", tab->b[i]);
		i--;
	}
}

void			print_stack(t_pile *tab, char *opt, char *line)
{
	static	int	count = 0;

	if (opt[1] == 'v')
	{
		ft_printf("\n|---------------------|\n");
		print_stack_2(tab);
		ft_printf("|---------------------|\n");
		ft_printf("|stack_a       satck_b|\n");
		ft_printf("|>>>>>>>>[%5d]<<<<<<|\n", count++);
		ft_printf("|---------------------|\n");
		ft_printf("OP = %s\n", line);
		print_speed(opt);
	}
}
