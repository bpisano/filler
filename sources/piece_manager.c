/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   piece_manager.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 20:15:56 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/08 12:27:44 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	new_piece(t_piece *new)
{
	new->width = 0;
	new->height = 0;
	new->map = NULL;
}

void	set_piece_size(t_piece *piece)
{
	int		width;
	int		height;

	read_parameters(&width, &height);
	piece->width = width;
	piece->height = height;
}

void	set_piece(t_data *data, t_piece *piece)
{
	int		i;
	char	*line;

	new_piece(piece);
	set_piece_size(piece);
	if (!(piece->map = (char **)malloc(sizeof(char *) * (piece->height + 1))))
		return ;
	i = 0;
	while (i < piece->height)
	{
		get_next_line(0, &line);
		(piece->map)[i++] = line;
	}
	(piece->map)[i] = NULL;
	data->piece = piece;
}
