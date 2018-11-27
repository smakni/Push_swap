/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:12:53 by smakni            #+#    #+#             */
/*   Updated: 2018/11/27 16:54:21 by smakni           ###   ########.fr       */
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
	int 	*a;
	int		*b;
	int		lt;
	int		la;
	int		lb;
}				s_pile;

typedef struct t_ret
{
	char 	*ret;
	char 	*tmp;
	int		max;
	int		min;
}				s_ret;

int			ft_printf(const char *format, ...);
void		ft_operations_c(s_pile *tab, char *line);
void		ft_operations_p(s_pile *tab, char *line);
void		ft_swap(s_pile *tab, char *line);
void		ft_push(s_pile *tab, char *line);
void		ft_rotate(s_pile *tab, char *line);
void		ft_rotate_r(s_pile *tab, char *line);
void		ft_swap_ret(s_pile *tab, char *line);
void		ft_push_ret(s_pile *tab, char *line);
void		ft_rotate_ret(s_pile *tab, char *line);
void		ft_rotate_r_ret(s_pile *tab, char *line);
int			*ft_tabdup(int *tab, int len);
void		init_tab(int ac, char **av, s_pile *tab);
void		free_s_tab(s_pile *tab);
void		print_pile(s_pile *tab);
void		check_init(s_pile *tab);
int			check_pile_a(s_pile *tab);
int			check_pile_b(s_pile *tab);
int			first_a(s_pile *tab, s_ret *ret, int p);
void		first_b(s_pile *tab, s_ret *ret, int p);
void		in_place_b(s_pile *tab, s_ret *ret,  int p);
int			ft_count_n(char *line);
void		init_ret(s_pile *tab, s_ret *ret);
void		check_min_max(s_pile *tab, s_ret *ret);
int			find_max(s_pile *tab, s_ret *ret);
void		exc_op(s_pile *tab, char *str);
int			find_min_frame(s_pile *tab, int x);
int			find_max_frame(s_pile *tab, int x);

#endif
