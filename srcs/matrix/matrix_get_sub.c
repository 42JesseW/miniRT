/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_get_sub.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/07 19:47:26 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:53:07 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_matrix	matrix_get_sub(t_matrix m, int row, int col)
{
	t_matrix	sub;
	int			xy[2];

	sub = matrix_alloc(m.size - 1);
	if (!sub.m)
		return (sub);
	xy[0] = 0;
	while (xy[0] < sub.size)
	{
		xy[1] = 0;
		while (xy[1] < sub.size)
		{
			if (xy[0] >= row && xy[1] >= col)
				sub.m[xy[0]][xy[1]] = m.m[xy[0] + 1][xy[1] + 1];
			if (xy[0] < row && xy[1] >= col)
				sub.m[xy[0]][xy[1]] = m.m[xy[0]][xy[1] + 1];
			if (xy[0] >= row && xy[1] < col)
				sub.m[xy[0]][xy[1]] = m.m[xy[0] + 1][xy[1]];
			if (xy[0] < row && xy[1] < col)
				sub.m[xy[0]][xy[1]] = m.m[xy[0]][xy[1]];
			xy[1]++;
		}
		xy[0]++;
	}
	return (sub);
}
