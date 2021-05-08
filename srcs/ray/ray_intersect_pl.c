/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_intersect_pl.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 22:26:06 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:49:20 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
** [l∗t ⋅ n+(lO−pO) ⋅ n=0]
** - l is the direction of the ray along which it is cast
** - t is the scalar that we want to calculate
** - n is the plane orientation normal
** - lO is the ray origin
** - pO is the plane origin
**
** solve for t:
** t = ((pO - lO) ⋅ n) / (l ⋅ n)
** - {denominator} = (l ⋅ n)
**
**	@PARAM {t_vector}	origin
**	@PARAM {t_vector}	orient
**	@PARAM {t_ray*}	r
**	@PARAM {t_hit*} hit
**	@RETURN {bool}
*/

bool	ray_intersect_pl(t_ray *r, t_plane pl, t_hit *hit)
{
	double		denominator;
	double		t;
	double		dot;
	t_vector	v;

	denominator = vector_dot(&pl.orient, &r->dir);
	v = point_sub_point(&pl.origin, &r->origin);
	t = vector_dot(&v, &pl.orient);
	t /= denominator;
	if (t >= 0)
	{
		dot = vector_dot(&r->dir, &pl.orient);
		if (dot >= 0 && dot < EPSILON)
			return (false);
		hit->t[0] = t;
		hit->t[1] = t;
		hit->normal = pl.orient;
		hit->reflect = vector_reflect(&r->dir, &pl.orient);
		hit->p = ray_at(r, t);
		return (true);
	}
	return (false);
}
