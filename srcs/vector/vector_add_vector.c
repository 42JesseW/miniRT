/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_add_vector.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/06 20:58:20 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 13:21:33 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	vector_add_vector(t_vector *v1, t_vector *v2)
{
	t_vector	v;

	v.x = v1->x + v2->x;
	v.y = v1->y + v2->y;
	v.z = v1->z + v2->z;
	v.w = v1->w + v2->w;
	return (v);
}
