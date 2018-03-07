/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 18:31:06 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 19:34:59 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	skip_next_line(const int fd)
{
	char	*line;

	get_next_line(fd, &line);
	free(line);
}

void	print_map(t_data *data)
{
	int		i;

	printf("\nMAP\n");
	i = 0;
	while (i < data->map_h)
	{
		printf("%s\n", (data->map)[i]);
		i++;
	}
}

int		main(void)
{
	t_data	data;

	init_data(&data);
	while (skip_next_line(0))
	{
		set_map(&data);
	}
	return (0);
}
