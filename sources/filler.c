/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 18:31:06 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/08 12:47:21 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	print_map(char **map, int height)
{
	int		i;

	printf("\nMAP\n");
	i = 0;
	while (i < height)
		ft_printf("%s\n", map[i++]);
}

int		main(void)
{
	t_data	data;
	t_piece	piece;

	init_data(&data);
	while (skip_next_line(0))
	{
		set_map(&data);
		set_piece(&data, &piece);
		(data.turn)++;
	}
	return (0);
}
