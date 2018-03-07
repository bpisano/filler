/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 18:31:44 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 19:35:03 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef struct	s_data
{
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

void			skip_next_line(const int fd);

void			init_data(t_data *data);

void			set_map(t_data *data);

#endif
