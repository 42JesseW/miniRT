/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_get_id.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/07 19:47:20 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:52:53 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_matrix	matrix_get_id(void)
{
	t_matrix	m;

	m = matrix_alloc(4);
	if (!m.m)
		return (m);
	m.m[0][0] = 1;
	m.m[1][1] = 1;
	m.m[2][2] = 1;
	m.m[3][3] = 1;
	return (m);
}
