/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   square_manager.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/08 14:32:38 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 15:15:35 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	adjust_if_needed(t_data *d, t_square *s)
{
	s->x = s->x < 0 ? 0 : s->x;
	s->y = s->y < 0 ? 0 : s->y;
	s->width = s->width + s->x > d->map_w ? d->map_w - s->x : s->width;
	s->height = s->height + s->y > d->map_h ? d->map_h - s->y : s->height;
}

void	set_move_square(t_data *d, t_square *s)
{
	s->x = d->p1_x - (d->piece)->width;
	s->y = d->p1_y - (d->piece)->height;
	s->width = (d->piece)->width * 2 + 1;
	s->height = (d->piece)->height * 2 + 1;
	adjust_if_needed(d, s);
}

void	set_circle_square(t_data *d, t_square *s)
{
	s->x = d->p2_min_x - s->width;
	s->y = d->p2_min_y - s->height;
	s->width = d->p2_max_x - d->p2_min_x + ((d->piece)->width * 2 + 1);
	s->height = d->p2_max_y - d->p2_min_y + ((d->piece)->height * 2 + 1);
	adjust_if_needed(d, s);
}

void	set_map_square(t_data *d, t_square *s)
{
	s->x = 0;
	s->y = 0;
	s->width = d->map_w;
	s->height = d->map_h;
}
