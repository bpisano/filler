/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 18:31:44 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/08 17:30:22 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef struct	s_square
{
	int			x;
	int			y;
	int			width;
	int			height;
}				t_square;

typedef struct	s_piece
{
	int			width;
	int			height;
	char		**map;
}				t_piece;

typedef struct	s_data
{
	t_piece		*piece;
	char		player;
	char		**map;
	char		step;
	int			map_w;
	int			map_h;
	int			turn;
	int			p1_x;
	int			p1_y;
	int			p2_x;
	int			p2_y;
	int			p2_min_x;
	int			p2_min_y;
	int			p2_max_x;
	int			p2_max_y;
}				t_data;

int				skip_next_line(const int fd);
void			read_parameters(int *p1, int *p2);

void			init_data(t_data *data);

void			set_map(t_data *data);
void			set_piece(t_data *data, t_piece *piece);
int				can_place(t_data *d, t_piece *p, int x, int y);
void			place(t_data *data, t_piece *p, int x, int y);

void			move(t_data *data);

#endif
