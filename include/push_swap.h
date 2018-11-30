/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:12:53 by smakni            #+#    #+#             */
/*   Updated: 2018/11/30 12:28:59 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/printf/ft_printf.h"
# include "../libft/libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"

typedef struct t_pile
{
	char	**arg;
	long 	*a;
	long	*b;
	int		lt;
	int		la;
	int		lb;
}				s_pile;

typedef struct t_sol
{
	int sa;
	int sb;
	int ss;
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
}				s_sol;

int			ft_printf(const char *format, ...);
void		ft_operations(s_pile *tab, char *line);
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
void		print_pile_test(s_pile *tab);
void		check_init(s_pile *tab);
int			check_pile_a(s_pile *tab);
int			check_pile_b(s_pile *tab);
void		in_place_b(s_pile *tab, s_sol *sol,  int p);
int			ft_count_n(char *line);
int			find_max_in_b(s_pile *tab);
int			find_i_max_in_a(s_pile *tab);
int			find_i_max_in_b(s_pile *tab);
int			find_i_min_in_a(s_pile *tab);
void		exc_op(s_pile *tab, s_sol *sol);
int			find_min_frame(s_pile *tab, int x);
int			find_max_frame(s_pile *tab, int x);
int			check_frames(s_pile *tab, int min_frame, int max_frame, int p);
void		save_solution(s_sol *tmp, s_sol *sol);
void		init_solution(s_sol *sol);
int			check_solutions(s_pile *tab, s_sol *tmp, int p);
void		cycle_a(s_pile *tab, s_sol *sol, int p);
long		ft_atoi_p(const char *str);

#endif
