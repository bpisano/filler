/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/08 15:36:40 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/13 12:27:29 by bpisano     ###    #+. /#+    ###.fr     */
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

int		distance_nearest_p2(t_data *d, int x, int y)
{
	int			cx;
	int			cy;
	int			dist;

	dist = 0;
	cy = (d->piece)->min_y - 1;
	while (++cy <= (d->piece)->max_y)
	{
		cx = (d->piece)->min_x - 1;
		while (++cx <= (d->piece)->max_x)
		{
			if (((d->piece)->map)[cy][cx] == '*')
				dist += distance(x, y, d->p_x + cx, d->p_y + cy);
		}
	}
	return (dist);
}

int		eval(t_data *d)
{
	int		x;
	int		y;
	int		dist;
	int		min_dist;

	min_dist = EVAL_MAX;
	y = d->p2_min_y - 1;
	while (++y <= d->p2_max_y)
	{
		x = d->p2_min_x - 1;
		while (++x <= d->p2_max_x)
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
	while (++y <= d->map_h - (d->piece)->height)
	{
		x = -1;
		while (++x <= d->map_w - (d->piece)->width)
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
