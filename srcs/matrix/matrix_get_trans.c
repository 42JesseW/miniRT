/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_get_trans.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/07 19:47:37 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:53:11 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_matrix	matrix_get_trans(t_point p)
{
	t_matrix	m;

	m = matrix_alloc(4);
	if (!m.m)
		return (m);
	m.m[0][0] = 1;
	m.m[0][1] = 0;
	m.m[0][2] = 0;
	m.m[0][3] = p.x;
	m.m[1][0] = 0;
	m.m[1][1] = 1;
	m.m[1][2] = 0;
	m.m[1][3] = p.y;
	m.m[2][0] = 0;
	m.m[2][1] = 0;
	m.m[2][2] = 1;
	m.m[2][3] = p.z;
	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	return (m);
}
