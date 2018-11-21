/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:12:53 by smakni            #+#    #+#             */
/*   Updated: 2018/11/21 13:24:36 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf/printf/ft_printf.h"
# include "ft_printf/libft/libft.h"
# include "ft_printf/get_next_line/get_next_line.h"

int			ft_printf(const char *format, ...);
int					ft_strequ(char const *s1, char const *s2);

#endif
