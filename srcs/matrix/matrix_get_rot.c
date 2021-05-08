/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_get_rot.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/07 19:47:22 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:39:57 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_matrix	matrix_get_rot(t_point a, t_point b, t_point c)
{
	t_matrix	m;

	m = matrix_alloc(4);
	if (!m.m)
		return (m);
	m.m[0][0] = a.x;
	m.m[0][1] = b.x;
	m.m[0][2] = c.x;
	m.m[0][3] = 0;
	m.m[1][0] = a.y;
	m.m[1][1] = b.y;
	m.m[1][2] = c.y;
	m.m[1][3] = 0;
	m.m[2][0] = a.z;
	m.m[2][1] = b.z;
	m.m[2][2] = c.z;
	m.m[2][3] = 0;
	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	return (m);
}

t_matrix	matrix_get_rot_x(double rad)
{
	t_matrix	m;

	m = matrix_alloc(4);
	if (!m.m)
		return (m);
	m.m[0][0] = 1;
	m.m[0][1] = 0;
	m.m[0][2] = 0;
	m.m[0][3] = 0;
	m.m[1][0] = 0;
	m.m[1][1] = cos(rad);
	m.m[1][2] = -sin(rad);
	m.m[1][3] = 0;
	m.m[2][0] = 0;
	m.m[2][1] = sin(rad);
	m.m[2][2] = cos(rad);
	m.m[2][3] = 0;
	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	return (m);
}

t_matrix	matrix_get_rot_y(double rad)
{
	t_matrix	m;

	m = matrix_alloc(4);
	if (!m.m)
		return (m);
	m.m[0][0] = cos(rad);
	m.m[0][1] = 0;
	m.m[0][2] = sin(rad);
	m.m[0][3] = 0;
	m.m[1][0] = 0;
	m.m[1][1] = 1;
	m.m[1][2] = 0;
	m.m[1][3] = 0;
	m.m[2][0] = -sin(rad);
	m.m[2][1] = 0;
	m.m[2][2] = cos(rad);
	m.m[2][3] = 0;
	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	return (m);
}

t_matrix	matrix_get_rot_z(double rad)
{
	t_matrix	m;

	m = matrix_alloc(4);
	if (!m.m)
		return (m);
	m.m[0][0] = cos(rad);
	m.m[0][1] = -sin(rad);
	m.m[0][2] = 0;
	m.m[0][3] = 0;
	m.m[1][0] = sin(rad);
	m.m[1][1] = cos(rad);
	m.m[1][2] = 0;
	m.m[1][3] = 0;
	m.m[2][0] = 0;
	m.m[2][1] = 0;
	m.m[2][2] = 1;
	m.m[2][3] = 0;
	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	return (m);
}
