/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/08 15:36:40 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 18:53:06 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

int		move_eval(t_data *d, int x, int y)
{
	return (distance(x, y, d->p2_x, d->p2_y));
}

int		circle_eval(t_data *d, int x, int y)
{
	int		cx;
	int		cy;
	int		score;

	score = 0;
	cy = -1;
	while (++cy < (d->piece)->width)
	{
		cx = -1;
		while (++cx < (d->piece)->height)
		{
			score += distance_nearest_p2(d, x + cx, y + cy);
		}
	}
	return (score);
}

void	get_move_position(t_data *d, t_square *s, int *px, int *py)
{
	int		x;
	int		y;
	int		ev;
	int		min_eval;

	min_eval = EVAL_MAX;
	y = s->y - 1;
	while (++y < s->height + s->y)
	{
		x = s->x - 1;
		while (++x < s->width + s->x)
		{
			if (can_place(d, d->piece, x, y))
			{	
				if ((ev = (d->eval)[d->step](d, x, y)) < min_eval)
				{
					min_eval = ev;
					*px = x;
					*py = y;
				}	
			}
		}
	}
}

void	move(t_data *d, int *x, int *y)
{
	t_square	square;

	*x = -1;
	*y = -1;
	(d->square)[d->step](d, &square);	
	get_move_position(d, &square, x, y);
	if (*x == -1 && *y == -1)
	{
		set_map_square(d, &square);
		get_move_position(d, &square, x, y);
	}
	if (*x + 10 >= d->p2_min_x && *x - 10 <= d->p2_max_x
			&& *y + 10 >= d->p2_max_y && *y - 10 <= d->p2_max_y)
	{
		d->step = 1;
		//ft_printf("-1 -1");
		//sleep(5);
	}
	//ft_printf("%d, %d, %d, %d\n", d->p2_min_x, d->p2_min_y, d->p2_max_x, d->p2_max_y);
	//sleep(1);
}
