/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   piece_manager.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 20:15:56 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/20 12:43:11 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	new_piece(t_piece *new)
{
	new->width = 0;
	new->height = 0;
	new->min_x = EVAL_MAX;
	new->min_y = EVAL_MAX;
	new->max_x = 0;
	new->max_y = 0;
	new->map = NULL;
}

void	free_piece(t_piece *p)
{
	int		i;

	i = 0;
	while ((p->map)[i])
		free((p->map)[i++]);
	free(p->map);
}

void	set_piece_size(t_piece *piece)
{
	int		x;
	int		y;

	y = -1;
	while (++y < piece->height)
	{
		x = -1;
		while (++x < piece->width)
		{
			if ((piece->map)[y][x] == '*')
			{
				piece->min_x = x < piece->min_x ? x : piece->min_x;
				piece->min_y = y < piece->min_y ? y : piece->min_y;
				piece->max_x = x > piece->max_x ? x : piece->max_x;
				piece->max_y = y > piece->max_y ? y : piece->max_y;
			}
		}
	}
}

void	set_piece(t_data *data, t_piece *piece)
{
	int		i;
	int		width;
	int		height;
	char	*line;

	new_piece(piece);
	read_parameters(&height, &width);
	piece->width = width;
	piece->height = height;
	if (!(piece->map = (char **)malloc(sizeof(char *) * (piece->height + 1))))
		return ;
	i = 0;
	while (i < piece->height)
	{
		get_next_line(0, &line);
		(piece->map)[i++] = ft_strdup(line);
		free(line);
	}
	(piece->map)[i] = NULL;
	set_piece_size(piece);
	data->piece = piece;
}

int		can_place(t_data *d, t_piece *p, int x, int y)
{
	int		cx;
	int		cy;
	int		contact;

	if (x + p->width > d->map_w || y + p->height > d->map_h)
		return (0);
	contact = 0;
	cy = y;
	while (cy < p->height + y)
	{
		cx = x;
		while (cx < p->width + x)
		{
			if ((p->map)[cy - y][cx - x] == '*'
					&& (d->map)[cy][cx] == d->p1)
				contact++;
			else if ((p->map)[cy - y][cx - x] == '*'
					&& (d->map)[cy][cx] == d->p2)
				return (0);
			cx++;
		}
		cy++;
	}
	return (contact == 1);
}
