/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   piece_manager.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 20:15:56 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 20:24:39 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	new_piece(t_piece *new)
{
	new->box_w = 0;
	new->box_h = 0;
	new->width = 0;
	new->height = 0;
	new->map = NULL;
}

void	set_piece_box(t_piece *piece)
{
	int		width;
	int		height;

	read_parameters(&width, &height);
	piece->box_w = width;
	piece->box_h = height;
}

void	set_piece(t_piece *piece)
{
	new_piece(piece);
	set_piece_box(piece);

}
