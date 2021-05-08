/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_eq.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/07 19:46:55 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:52:33 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	matrix_eq(t_matrix m1, t_matrix m2)
{
	int	x;
	int	y;

	if (m1.size != m2.size)
		return (false);
	x = 0;
	while (x < m1.size)
	{
		y = 0;
		while (y < m1.size)
		{
			if (fabs(m1.m[x][y] - m2.m[x][y]) >= __FLT_EPSILON__)
				return (false);
			y++;
		}
		x++;
	}
	return (true);
}
