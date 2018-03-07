/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   data_manager.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 13:45:05 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 20:12:24 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	new_data(t_data *new)
{
	new->player = 0;
	new->map = NULL;
	new->step = 0;
	new->map_w = 0;
	new->map_h = 0;
	new->turn = 0;
	new->p1_x = 0;
	new->p1_y = 0;
	new->p2_x = 0;
	new->p2_y = 0;
	new->p2_min_x = 0;
	new->p2_min_y = 0;
	new->p2_max_x = 0;
	new->p2_max_y = 0;
}

void	set_player(t_data *data)
{
	int		i;
	char	*line;

	get_next_line(0, &line);
	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
		{
			data->player = 'O';
			free(line);
			return ;
		}
		if (line[i] == '2')
		{
			data->player = 'X';
			free(line);
			return ;
		}
		i++;
	}
	free(line);
}

void	set_board_size(t_data *data)
{
	int		width;
	int		height;

	read_parameters(&width, &height);
	data->map_h = width;
	data->map_w = height;
}

void	init_data(t_data *data)
{
	new_data(data);
	set_player(data);
	set_board_size(data);
}
