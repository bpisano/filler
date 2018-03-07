/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_manager.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 17:42:27 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 19:21:16 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	set_player_square(t_data *data, char *line, int y)
{
	int		x;
	char	c;

	x = -1;
	while (line[++x])
	{
		c = line[x];
		if (c != 'X' && c != 'O')
			continue ;
		(c != data->player && x < data->p2_min_x) ? data->p1_x = x : c;
		(c != data->player && y < data->p2_min_y) ? data->p1_y = y : c;
		(c != data->player && x > data->p2_max_x) ? data->p2_x = x : c;
		(c != data->player && y > data->p2_max_y) ? data->p2_x = y : c;
	}
}

void	set_player_position(t_data *data, char *line, int y)
{
	int		x;
	char	c;

	x = -1;
	while (line[++x])
	{
		c = line[x];
		if (c != 'X' && c != 'O')
			continue ;
		if (!(data->map))
		{
			c == data->player ? data->p1_x = x : c;
			c == data->player ? data->p1_y = y : c;
			c != data->player ? data->p2_x = x : c;
			c != data->player ? data->p2_y = y : c;
			continue ;
		}
		(c == data->player && (data->map)[y][x] != c) ? data->p1_x = x : c;
		(c == data->player && (data->map)[y][x] != c) ? data->p1_y = y : c;
		(c != data->player && (data->map)[y][x] != c) ? data->p2_x = x : c;
		(c != data->player && (data->map)[y][x] != c) ? data->p2_x = y : c;
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
	y = -1;
	while (++y < data->map_h)
	{
		get_next_line(0, &line);
		x = -1;
		while (ft_isdigit(line[++x]))
			x++;
		map[y] = ft_strdup(line + x);
		set_player_position(data, line + x, y);
		set_player_square(data, line + x, y);
		free(line);
	}
	map[y] = NULL;
	data->map ? free(data->map) : data->map;
	data->map = map;
}
