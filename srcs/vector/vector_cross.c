/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_cross.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/06 20:58:29 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 13:21:51 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	vector_cross(t_vector *v1, t_vector *v2)
{
	t_vector	v;

	v.x = v1->y * v2->z - v1->z * v2->y;
	v.y = v1->z * v2->x - v1->x * v2->z;
	v.z = v1->x * v2->y - v1->y * v2->x;
	v.w = 0;
	return (v);
}
