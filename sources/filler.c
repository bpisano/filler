/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 18:31:06 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 21:11:45 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_data	data;
	t_piece	piece;
	
	init_data(&data);
	while (data.turn == 0 ? 1 : skip_next_line(0))
	{
		set_map(&data);
		set_piece(&data, &piece);
		play(&data);
		(data.turn)++;
		//free_piece(&piece);
	}
	//free_data(&data);
	return (0);
}
