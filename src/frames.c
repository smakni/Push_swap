/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:15:15 by smakni            #+#    #+#             */
/*   Updated: 2018/11/30 15:00:03 by smakni           ###   ########.fr       */
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

int		find_max_in_b(s_pile *tab)
{
	int i;
	int max;

	i = tab->lb - 1;
	max = tab->b[i--];
	while (i >= 0)
	{
		if (tab->b[i] > max)
			max = tab->b[i];
		i--;
	}
	return (max);
}

int		find_i_max_in_a(s_pile *tab)
{
	int i;
	int j;
	int max;


	i = tab->la - 1;
	j = i;
	max = tab->a[i--];
	while (i >= 0)
	{
		if (tab->a[i] > max)
		{
			max = tab->a[i];
			j = i;
		}
		i--;
	}
	return (j);
}

int		find_i_max_in_b(s_pile *tab)
{
	int i;
	int j;
	int max;


	i = tab->lb - 1;
	j = i;
	max = tab->b[i--];
	while (i >= 0)
	{
		if (tab->b[i] > max)
		{
			max = tab->b[i];
			j = i;
		}
		i--;
	}
	return (j);
}

int		find_i_min_in_a(s_pile *tab)
{
	int i;
	int j;
	int min;

	i = tab->la - 1;
	j = i;
	min = tab->a[i--];
	while (i >= 0)
	{
		if (tab->a[i] < min)
		{
			min = tab->a[i];
			j = i;
		}
		i--;
	}
	return (j);
}

int		check_frames(s_pile *tab, int min_frame, int max_frame, int p)
{
	int i;
	int j;

	i = tab->lb - 1;
	j = 0;
	if (tab->a[p] == min_frame)
	{
		max_frame = find_max_in_b(tab);
		while (tab->b[i] != max_frame && i > 0)
			i--;
	}
	else
		while (tab->b[i] != min_frame && i > 0)
			i--;
	return (i);
}
