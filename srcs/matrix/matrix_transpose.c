/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_transpose.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/07 19:47:55 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/07 19:47:56 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_matrix	matrix_transpose(t_matrix m)
{
	t_matrix	trans;
	int			x;
	int			y;

	trans = matrix_alloc(m.size);
	if (!trans.m)
		return (trans);
	x = 0;
	while (x < trans.size)
	{
		y = 0;
		while (y < trans.size)
		{
			trans.m[x][y] = m.m[y][x];
			y++;
		}
		x++;
	}
	return (trans);
}
