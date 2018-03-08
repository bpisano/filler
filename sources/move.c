/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/08 15:36:40 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/08 17:36:49 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

int		eval(t_data *d, int x, int y)
{
	int	dx;
	int	dy;

	dx = ft_abs(d->p2_x - x);
	dy = ft_abs(d->p2_y - y);
	return (dx + dy);
}

void	set_pos_square(t_data *d, t_square *s)
{
	s->x = d->p2_x - (d->piece)->width;
	s->y = d->p2_y - (d->piece)->height;
	s->width = (d->piece)->width * 2;
	s->height = (d->piece)->height * 2;
	s->x = s->x < 0 ? 0 : s->x;
	s->y = s->y < 0 ? 0 : s->y;
	s->width = s->width + s->x > d->map_w ? d->map_w - s->x : s->width;
	s->height = s->height + s->y > d->map_h ? d->map_h - s->y : s->height;
}

void	get_position(t_data *d, t_square *s, int *px, int *py)
{
	int		x;
	int		y;
	int		ev;
	int		min_eval;

	min_eval = 1000000;
	y = s->y;
	while (y < s->height)
	{
		x = s->x;
		while (x < s->width)
		{
			if (can_place(d, d->piece, x, y))
			{
				if ((ev = eval(d, x, y)) < min_eval)
				{
					min_eval = ev;
					*px = x;
					*py = y;
				}
			}
			x++;
		}
		y++;
	}
}

void	move(t_data *data)
{
	int			x;
	int			y;
	t_square	square;

	x = -1;
	y = -1;
	set_pos_square(data, &square);
	get_position(data, &square, &x, &y);
	printf("%d, %d", x, y);
}
