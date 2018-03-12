/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   play.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/09 12:57:28 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 15:42:49 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

int		distance(int x1, int y1, int x2, int y2)
{
	int		dx;
	int		dy;

	dx = ft_abs(x2 - x1);
	dy = ft_abs(y2 - y1);
	return (dx + dy);
}

void	play(t_data *data)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	move(data, &x, &y);
	ft_printf("%d %d\n", y, x);
}
