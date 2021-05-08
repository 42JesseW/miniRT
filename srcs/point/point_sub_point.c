/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   point_sub_point.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/06 21:01:56 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:22:04 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	point_sub_point(t_point *p1, t_point *p2)
{
	t_vector	v;

	v.x = p1->x - p2->x;
	v.y = p1->y - p2->y;
	v.z = p1->z - p2->z;
	v.w = p1->w - p2->w;
	return (v);
}
