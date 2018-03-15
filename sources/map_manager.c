/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_manager.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:42:27 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 16:13:08 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	set_player_square(t_data *data, char *line, int y)
{
	int		x;
	char	c;

	x = -1;
	while ((c = line[++x]))
	{
		if (c != 'X' && c != 'O')
			continue ;
		(c == data->p2 && x < data->p2_min_x) ? data->p2_min_x = x : c;
		(c == data->p2 && y < data->p2_min_y) ? data->p2_min_y = y : c;
		(c == data->p2 && x > data->p2_max_x) ? data->p2_max_x = x : c;
		(c == data->p2 && y > data->p2_max_y) ? data->p2_max_y = y : c;
	}
}

void	set_player_position(t_data *data, char *line, int y)
{
	int		x;
	char	c;

	x = -1;
	while ((c = line[++x]))
	{
		if (c != 'X' && c != 'O')
			continue ;
		if (!(data->map))
		{
			c == data->p1 ? data->p1_x = x : c;
			c == data->p1 ? data->p1_y = y : c;
			c == data->p2 ? data->p2_x = x : c;
			c == data->p2 ? data->p2_y = y : c;
			continue ;
		}
		(c == data->p1 && (data->map)[y][x] != c) ? data->p1_x = x : c;
		(c == data->p1 && (data->map)[y][x] != c) ? data->p1_y = y : c;
		(c == data->p2 && (data->map)[y][x] != c) ? data->p2_x = x : c;
		(c == data->p2 && (data->map)[y][x] != c) ? data->p2_x = y : c;
	}
}

void	set_map(t_data *data)
{
	int		x;
	int		y;
	char	*line;
	char	**map;

	if (!(map = (char **)malloc(sizeof(char *) * (data->map_h + 1))))
		return ;
	skip_next_line(0);
	y = -1;
	while (++y < data->map_h)
	{
		get_next_line(0, &line);
		x = -1;
		while (ft_isdigit(line[++x]))
			x++;
		map[y] = ft_strdup(ft_strupcase(line + x));
		set_player_position(data, map[y], y);
		set_player_square(data, map[y], y);
		//free(line);
	}
	map[y] = NULL;
	data->map ? free(data->map) : data->map;
	data->map = map;
}
