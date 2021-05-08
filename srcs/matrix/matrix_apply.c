/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_apply.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/07 19:46:45 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:39:23 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_point	matrix_apply_p(t_matrix m, t_point *p)
{
	t_point	pt;
	double	tmp[4];
	double	w;

	tmp[0] = p->x * m.m[0][0] + p->y * m.m[0][1];
	pt.x = tmp[0] + p->z * m.m[0][2] + p->w * m.m[0][3];
	tmp[1] = p->x * m.m[1][0] + p->y * m.m[1][1];
	pt.y = tmp[1] + p->z * m.m[1][2] + p->w * m.m[1][3];
	tmp[2] = p->x * m.m[2][0] + p->y * m.m[2][1];
	pt.z = tmp[2] + p->z * m.m[2][2] + p->w * m.m[2][3];
	tmp[3] = p->x * m.m[3][0] + p->y * m.m[3][1];
	pt.w = tmp[3] + p->z * m.m[3][2] + p->w * m.m[3][3];
	if (pt.w != 1. && pt.w != 0)
	{
		w = 1 / pt.w;
		pt.x *= w;
		pt.y *= w;
		pt.z *= w;
	}
	return (pt);
}

t_vector	matrix_apply_v(t_matrix m, t_vector *v)
{
	t_vector	vt;
	double		tmp[4];
	double		w;

	tmp[0] = v->x * m.m[0][0] + v->y * m.m[0][1];
	vt.x = tmp[0] + v->z * m.m[0][2] + v->w * m.m[0][3];
	tmp[1] = v->x * m.m[1][0] + v->y * m.m[1][1];
	vt.y = tmp[1] + v->z * m.m[1][2] + v->w * m.m[1][3];
	tmp[2] = v->x * m.m[2][0] + v->y * m.m[2][1];
	vt.z = tmp[2] + v->z * m.m[2][2] + v->w * m.m[2][3];
	tmp[3] = v->x * m.m[3][0] + v->y * m.m[3][1];
	vt.w = tmp[3] + v->z * m.m[3][2] + v->w * m.m[3][3];
	if (vt.w != 1. && vt.w != 0)
	{
		w = 1 / vt.w;
		vt.x *= w;
		vt.y *= w;
		vt.z *= w;
	}
	return (vt);
}
