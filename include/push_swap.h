/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:12:53 by smakni            #+#    #+#             */
/*   Updated: 2018/11/23 15:59:32 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/printf/ft_printf.h"
# include "../libft/libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"

typedef struct t_pile
{
	char	**arg;
	int 	*list_a;
	int		*list_b;
	int		len_t;
	int		len_a;
	int		len_b;
}				s_pile;

int			ft_printf(const char *format, ...);
void		ft_operations(s_pile *tab, char *line);
void		ft_swap(s_pile *tab, char *line);
void		ft_push(s_pile *tab, char *line);
void		ft_rotate(s_pile *tab, char *line);
void		ft_rotate_r(s_pile *tab, char *line);
int			*ft_tabdup(int *tab, int len);
void		init_tab(int ac, char **av, s_pile *tab);
void		free_s_tab(s_pile *tab);
void		print_pile(s_pile *tab);
void		check_init(s_pile *tab);

#endif
