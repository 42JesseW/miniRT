/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_get_view.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/07 19:47:40 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/11 12:17:00 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
** matrix_get_view() build a transformation
** matrix for the camera so that it can
** orient itself properly in the world
*/

static void	set_matrix(t_matrix m, t_vector *fw, t_vector *up, t_vector *lft)
{
	if (!m.m)
		return ;
	m.m[0][0] = lft->x;
	m.m[0][1] = lft->y;
	m.m[0][2] = lft->z;
	m.m[0][3] = 0;
	m.m[1][0] = up->x;
	m.m[1][1] = up->y;
	m.m[1][2] = up->z;
	m.m[1][3] = 0;
	m.m[2][0] = -fw->x;
	m.m[2][1] = -fw->y;
	m.m[2][2] = -fw->z;
	m.m[2][3] = 0;
	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
}

t_matrix	matrix_get_view(t_point from, t_point to)
{
	t_matrix	view[3];
	t_vector	fw;
	t_vector	lft;
	t_vector	up;
	t_vector	tmp;

	view[0] = matrix_alloc(4);
	fw = vector_norm(point_sub_point(&to, &from));
	tmp = vector_new(0, 1., 0);
	lft = vector_cross(&tmp, &fw);
	if (vector_mag(lft) == 0)
	{
		tmp = vector_new(0, 0, 1.);
		if (fw.y == 1.0)
			tmp = vector_new(0, 0, -1.);
		lft = vector_cross(&tmp, &fw);
	}
	up = vector_cross(&fw, &lft);
	set_matrix(view[0], &fw, &up, &lft);
	view[1] = matrix_get_trans(point_new(-from.x, -from.y, -from.z));
	view[2] = matrix_multiply(view[0], view[1]);
	matrix_free_mult(view, 2);
	if (!view[2].m)
		matrix_free(view[2]);
	return (view[2]);
}
