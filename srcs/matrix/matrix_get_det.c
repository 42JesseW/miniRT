/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_get_det.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/07 19:47:18 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:52:50 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	matrix_get_det(t_matrix m, t_error *err)
{
	t_matrix	sub;
	double		det;
	int			y;

	det = 0;
	if (!m.m)
		*err = error_new("matrix_get_det() -> ", ENOMEM);
	else if (m.size == 2)
		det = m.m[0][0] * m.m[1][1] - m.m[1][0] * m.m[0][1];
	else
	{
		y = 0;
		while (y < m.size)
		{
			sub = matrix_get_sub(m, 0, y);
			det += m.m[0][y]
				* matrix_get_cof_sign(0, y)
				* matrix_get_det(sub, err);
			matrix_free(sub);
			y++;
		}
	}
	return (det);
}
