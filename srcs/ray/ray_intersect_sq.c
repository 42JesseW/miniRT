/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_intersect_sq.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 22:26:10 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:13:56 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
** ray_intersect_sq() uses the two triangles
** that make up the square to check for
** intersection using hit_triangle().
**
** method:
** Choose an arbitrary vector (0,0,1)
** and take the cross product of this arbitrary
** vector and the square normal. Then two more
** cross products of the plane normal and the
** result of the first cross product and their
** reverse. This way we get the following vectors ABC:
**
** v0_____________v1
** |       A       |
** |       ^       |
** |       |       |
** |B <----|----> C|
** |               |
** |               |
** v2-------------v3
**
** which can then be used to calculate the vectors
** v0,v1,v2,v3. These four new vectors can be fed
** to ray_intersect_tr() to check with intersection.
*/

bool	ray_intersect_sq(t_ray *r, t_square sq, t_hit *hit)
{
	return (ray_intersect_tr(r, sq.tr[0], hit)
		|| ray_intersect_tr(r, sq.tr[1], hit));
}
