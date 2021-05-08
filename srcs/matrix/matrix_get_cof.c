/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_get_cof.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/07 19:47:02 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:52:46 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	matrix_get_cof(t_matrix m, int row, int col, t_error *err)
{
	t_matrix	sub;
	double		cof;

	sub = matrix_get_sub(m, row, col);
	if (!sub.m)
	{
		*err = error_new("matrix_get_cof() -> ", ENOMEM);
		return (-1.);
	}
	if (sub.size == 2)
		cof = sub.m[0][0] * sub.m[1][1] - sub.m[0][1] * sub.m[1][0];
	else
		cof = matrix_get_det(sub, err);
	matrix_free(sub);
	return (matrix_get_cof_sign(row, col) * cof);
}
