/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_intersect_sp.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 22:26:08 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:13:50 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_vector	normal_at(t_ray *r, t_hit *hit, t_sphere *sp)
{
	t_point		object_pt;
	t_point		world_origin;
	t_vector	normals[2];

	world_origin = point_new_one(0);
	object_pt = matrix_apply_p(sp->transform, &hit->p);
	normals[0] = point_sub_point(&object_pt, &world_origin);
	normals[1] = matrix_apply_v(sp->transform, &normals[0]);
	if (point_dist(&r->origin, &world_origin)
		< point_dist(&object_pt, &world_origin))
		normals[1] = vector_negate(normals[1]);
	return (vector_norm(normals[1]));
}

bool	ray_intersect_sp(t_ray *r, t_sphere sp, t_hit *hit)
{
	t_ray		trans;
	t_vector	origin;
	t_point		world_origin;
	double		abc[3];
	double		discriminant;

	trans = ray_transform(r, sp.transform);
	world_origin = point_new_one(0);
	origin = point_sub_point(&trans.origin, &world_origin);
	abc[0] = vector_dot(&trans.dir, &trans.dir);
	abc[1] = 2. * vector_dot(&trans.dir, &origin);
	abc[2] = vector_dot(&origin, &origin) - 1;
	discriminant = pow(abc[1], 2.) - 4 * abc[0] * abc[2];
	if (discriminant < 0)
		return (false);
	hit->t[0] = (-abc[1] - sqrt(discriminant)) / (2 * abc[0]);
	hit->t[1] = (-abc[1] + sqrt(discriminant)) / (2 * abc[0]);
	if (fabs(hit->t[0]) <= fabs(hit->t[1]) && hit->t[0] > 0)
		hit->p = ray_at(r, hit->t[0]);
	else
		hit->p = ray_at(r, hit->t[1]);
	hit->normal = normal_at(&trans, hit, &sp);
	hit->reflect = vector_reflect(&r->dir, &hit->normal);
	return (true);
}
