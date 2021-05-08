/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_intersect_tr.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 22:26:12 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:14:10 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static bool	in_edge(t_vector *normal, t_vector *one, t_vector *two, t_point *p)
{
	t_vector	inout[3];
	t_vector	tmp;

	tmp = vector_new(p->x, p->y, p->z);
	inout[0] = vector_sub_vector(one, two);
	inout[1] = vector_sub_vector(&tmp, two);
	inout[2] = vector_norm(vector_cross(&inout[0], &inout[1]));
	return (vector_dot(&inout[2], normal) >= 0);
}

static void	set_hit(t_hit *hit, t_vector *normal, t_point p, double t)
{
	hit->p = p;
	hit->normal = vector_norm(*normal);
	hit->t[0] = t;
	hit->t[1] = t;
}

/*
** [t=(N(A,B,C)⋅ O+D) / (N(A,B,C)⋅ R)]
** - t is the scalar that we want to calculate
** - N(A,B,C) is the plane normal
** - D is the distance from origin to the plane
** - O is the ray origin
** - R is the ray direction
**
** Edge cases:
** - three points making up the triangle do not
** create a plane but a line or single point.
** - ray and plane normal are parallel
** - triangle is behind ray
** - shading behing on inside surface
**
** @PARAM {t_triangle}	tr
** @PARAM {t_ray*}		r
** @PARAM {t_hit*}		hit
** @RETURN {bool}
*/

bool	ray_intersect_tr(t_ray *r, t_triangle tr, t_hit *hit)
{
	t_vector	abc[3];
	t_vector	tmp;
	t_point		p;
	double		d;
	double		t;

	abc[0] = vector_sub_vector(&tr.v2, &tr.v1);
	abc[1] = vector_sub_vector(&tr.v3, &tr.v1);
	abc[2] = vector_cross(&abc[0], &abc[1]);
	if (vector_mag(abc[2]) == 0)
		return (false);
	if (fabs(vector_dot(&abc[2], &r->dir)) < EPSILON)
		return (false);
	d = vector_dot(&abc[2], &tr.v1);
	tmp = vector_new(r->origin.x, r->origin.y, r->origin.z);
	t = -((vector_dot(&abc[2], &tmp) - d) / vector_dot(&abc[2], &r->dir));
	if (t < 0)
		return (false);
	p = ray_at(r, t);
	if (!in_edge(&abc[2], &tr.v2, &tr.v1, &p)
		|| !in_edge(&abc[2], &tr.v3, &tr.v2, &p)
		|| !in_edge(&abc[2], &tr.v1, &tr.v3, &p))
		return (false);
	set_hit(hit, &abc[2], p, t);
	return (true);
}
