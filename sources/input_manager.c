/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input_manager.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 20:05:58 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 20:09:35 by bpisano     ###    #+. /#+    ###.fr     */
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

void	read_parameters(int *p1, int *p2)
{
	int		i;
	char	*line;

	i = 0;
	get_next_line(0, &line);
	while (!ft_isdigit(line[i]))
		i++;
	*p1 = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	*p2 = ft_atoi(line + i);
	free(line);
}
