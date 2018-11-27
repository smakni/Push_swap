/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:15:15 by smakni            #+#    #+#             */
/*   Updated: 2018/11/27 15:13:39 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		find_min_frame(s_pile *tab, int x)
{
	int i;
	int frame_min;

	i = tab->lb - 1;
	frame_min = x;
	while (i >= 0)
	{
		if (tab->b[i] < x)
		{
			if (frame_min == x)
				frame_min = tab->b[i];
			else if (tab->b[i] > frame_min)
				frame_min = tab->b[i];
		}
		i--;
	}
	return (frame_min);
}

int		find_max_frame(s_pile *tab, int x)
{
	int i;
	int frame_max;

	i = tab->lb - 1;
	frame_max = x;
	while (i >= 0)
	{
		if (tab->b[i] > x)
		{
			if (frame_max == x)
				frame_max = tab->b[i];
			else if (tab->b[i] < frame_max)
				frame_max = tab->b[i];
		}	
		i--;
	}
	return (frame_max);
}
