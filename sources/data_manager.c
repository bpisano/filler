/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   data_manager.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 13:45:05 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 19:22:15 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	new_data(t_data *new)
{
	new->p1 = 0;
	new->p2 = 0;
	new->map = NULL;
	new->step = 1;
	new->map_w = 0;
	new->map_h = 0;
	new->turn = 0;
	new->p1_x = 0;
	new->p1_y = 0;
	new->p2_x = 0;
	new->p2_y = 0;
	new->p2_min_x = 1000;
	new->p2_min_y = 1000;
	new->p2_max_x = 0;
	new->p2_max_y = 0;
	new->p_x = -1;
	new->p_y = -1;
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
			data->p1 = 'O';
			data->p2 = 'X';
			break ;
		}
		if (line[i] == '2')
		{
			data->p1 = 'X';
			data->p2 = 'O';
			break ;
		}
		i++;
	}
	free(line);
}

void	set_board_size(t_data *data)
{
	int		width;
	int		height;

	read_parameters(&height, &width);
	data->map_h = height;
	data->map_w = width;
}

void	init_data(t_data *data)
{
	new_data(data);
	set_player(data);
	set_board_size(data);
}
