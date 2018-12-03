/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:12:53 by smakni            #+#    #+#             */
/*   Updated: 2018/12/03 13:49:18 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/printf/ft_printf.h"
# include "../libft/libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"

struct		s_pile
{
	char	**arg;
	long	*a;
	long	*b;
	int		lt;
	int		la;
	int		lb;
};

typedef	struct s_pile	t_pile;

struct		s_sol
{
	int		sa;
	int		sb;
	int		ss;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
};

typedef	struct s_sol	t_sol;

int			ft_printf(const char *format, ...);
int			ft_operations(t_pile *tab, char *line);
void		ft_swap(t_pile *tab, char *line);
void		ft_push(t_pile *tab, char *line);
void		ft_rotate(t_pile *tab, char *line);
void		ft_rotate_r(t_pile *tab, char *line);
void		ft_swap_ret(t_pile *tab, char *line);
void		ft_push_ret(t_pile *tab, char *line);
void		ft_rotate_ret(t_pile *tab, char *line);
void		ft_rotate_r_ret(t_pile *tab, char *line);
int			*ft_tabdup(int *tab, int len);
void		init_tab(int ac, char **av, t_pile *tab);
void		free_s_tab(t_pile *tab);
void		print_stack(t_pile *tab, char *opt, char *line);
void		check_init(t_pile *tab);
int			check_pile_a(t_pile *tab);
void		in_place_b(t_pile *tab, t_sol *sol, int p);
int			ft_count_n(char *line);
int			find_max_in_b(t_pile *tab);
int			find_i_max_in_a(t_pile *tab);
int			find_i_max_in_b(t_pile *tab);
int			find_i_min_in_a(t_pile *tab);
void		exc_op(t_pile *tab, t_sol *sol);
int			find_min_frame(t_pile *tab, int x);
int			find_max_frame(t_pile *tab, int x);
int			check_frames(t_pile *tab, int min_frame, int max_frame, int p);
void		save_solution(t_sol *tmp, t_sol *sol);
void		init_solution(t_sol *sol);
int			check_solutions(t_pile *tab, t_sol *tmp, int p);
void		cycle_a(t_pile *tab, t_sol *sol, int p);
long		ft_atoi_p(const char *str);
void		algo_1(t_pile *tab);
void		algo_2(t_pile *tab, t_sol *sol);
void		algo_3(t_pile *tab, t_sol *sol);

#endif
