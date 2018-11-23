/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:12:53 by smakni            #+#    #+#             */
/*   Updated: 2018/11/23 13:57:54 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/printf/ft_printf.h"
# include "../libft/libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"

typedef	struct	t_tab
{
	char	**arg;
	int		len;
}				s_tab;

typedef struct t_pile
{
	int *list;
	int	len;
}				s_pile;

int			ft_printf(const char *format, ...);
void		ft_operations(s_pile *pile_a, s_pile *pile_b, char *line);
void		ft_swap(s_pile *pile_a, s_pile *pile_b, char *line);
void		ft_push(s_pile *pile_a, s_pile *pile_b, char *line);
void		ft_rotate(s_pile *a, s_pile *b, char *line);
void		ft_rotate_r(s_pile *a, s_pile *b, char *line);
int			*ft_tabdup(int *tab, int len);

#endif
