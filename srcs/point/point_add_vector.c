/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   point_add_vector.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/06 21:01:46 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:16:16 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_point	point_add_vector(t_point *p, t_vector *v)
{
	t_point	out;

	out.x = p->x + v->x;
	out.y = p->y + v->y;
	out.z = p->z + v->z;
	out.w = p->w + v->w;
	return (out);
}
