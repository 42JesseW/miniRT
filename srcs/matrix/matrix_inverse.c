/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_inverse.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 19:23:01 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:40:25 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static bool	get_matrix_info(t_matrix *in, t_matrix *out,
							double *det, t_error *err)
{
	if (!in->m)
		return (false);
	*det = matrix_get_det(*in, err);
	if (*det == 0)
		return (false);
	*det = 1 / *det;
	*out = matrix_alloc(in->size);
	if (!out->m || err->msg)
	{
		*err = error_new("matrix_inverse() -> ", ENOMEM);
		matrix_free(*out);
		return (false);
	}
	return (true);
}

t_matrix	matrix_inverse(t_matrix m)
{
	t_matrix	mat[3];
	t_error		err;
	double		det;
	int			x;
	int			y;

	err = error_new(NULL, 0);
	if (!get_matrix_info(&m, &mat[0], &det, &err))
		return ((t_matrix){.m = NULL, .size = 0});
	x = 0;
	while (x < m.size)
	{
		y = 0;
		while (y < m.size)
		{
			mat[0].m[x][y] = det * matrix_get_cof(m, x, y, &err);
			if (err.msg)
				return (matrix_free(mat[0]));
			y++;
		}
		x++;
	}
	mat[1] = matrix_transpose(mat[0]);
	matrix_free(mat[0]);
	return (mat[1]);
}
