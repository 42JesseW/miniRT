/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_multiply.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/07 19:47:53 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:41:26 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_matrix	matrix_multiply(t_matrix m1, t_matrix m2)
{
	t_matrix	m;
	int			x;
	int			y;

	m = matrix_alloc(4);
	if (!m1.m || !m2.m || !m.m || m1.size != m2.size)
		return (matrix_free(m));
	x = 0;
	while (x < m.size)
	{
		y = 0;
		while (y < m.size)
		{
			m.m[x][y] = m1.m[x][0] * m2.m[0][y]
				+ m1.m[x][1] * m2.m[1][y]
				+ m1.m[x][2] * m2.m[2][y]
				+ m1.m[x][3] * m2.m[3][y];
			y++;
		}
		x++;
	}
	return (m);
}
