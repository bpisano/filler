/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/08 15:36:40 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 20:11:06 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

int		distance(int x1, int y1, int x2, int y2)
{
	int		dx;
	int		dy;

	dx = ft_abs(x2 - x1);
	dy = ft_abs(y2 - y1);
	return (dx + dy);
}


int		eval(t_data *d)
{
	int		x;
	int		y;
	int		dist;
	int		min_dist;

	min_dist = EVAL_MAX;
	y = -1;
	while (++y < d->map_h)
	{
		x = -1;
		while (++x < d->map_w)
		{
			if ((d->map)[y][x] == d->p2)
			{	
				if ((dist = distance_nearest_p2(d, x, y)) < min_dist)
					min_dist = dist;
			}
		}
	}
	return (min_dist);
}

void	get_place_position(t_data *d, int *px, int *py)
{
	int		x;
	int		y;
	int		ev;
	int		min_eval;

	min_eval = EVAL_MAX;
	y = -1;
	while (++y < d->map_h)
	{
		x = -1;
		while (++x < d->map_w)
		{
			if (can_place(d, d->piece, x, y))
			{
				d->p_x = x;
				d->p_y = y;
				if ((ev = eval(d)) < min_eval)
				{
					min_eval = ev;
					*px = x;
					*py = y;
				}
			}
		}
	}
}

void	play(t_data *d)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	get_place_position(d, &x, &y);	
	ft_printf("%d %d\n", y, x);
}
