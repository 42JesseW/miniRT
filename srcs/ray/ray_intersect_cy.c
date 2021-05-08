/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_intersect_cy.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 22:26:03 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 15:54:22 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	fswap(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static t_vector	normal_at(t_ray *r, t_hit *hit, t_cylinder *cy)
{
	t_point		object_pt;
	t_point		world_origin;
	t_vector	normals[2];

	world_origin = point_new_one(0);
	object_pt = matrix_apply_p(cy->transform, &hit->p);
	normals[0] = vector_norm(vector_new(object_pt.x, object_pt.y, 0.));
	normals[1] = matrix_apply_v(cy->transform, &normals[0]);
	if (point_dist(&r->origin, &world_origin)
		< point_dist(&object_pt, &world_origin))
		normals[1] = vector_negate(normals[1]);
	return (vector_norm(normals[1]));
}

static bool	check_hit(t_ray *trans, t_cylinder *cy, t_hit *hit, double t[2])
{
	double	z[2];

	z[0] = trans->origin.z + (t[0] * trans->dir.z);
	z[1] = trans->origin.z + (t[1] * trans->dir.z);
	if ((-(cy->height * 0.5)) < z[0] && z[0] < ((cy->height * 0.5)))
		hit->t[0] = t[0];
	if ((-(cy->height * 0.5)) < z[1] && z[1] < ((cy->height * 0.5)))
		hit->t[1] = t[1];
	if (hit->t[0] == INFINITY && hit->t[1] == INFINITY)
		return (false);
	if ((hit->t[0] < 0 && hit->t[1] == INFINITY)
		|| (hit->t[1] < 0 && hit->t[0] == INFINITY))
		return (false);
	return (true);
}

static void	set_hit(t_ray *r, t_ray *trans, t_hit *hit, t_cylinder *cy)
{
	if (fabs(hit->t[0]) <= fabs(hit->t[1]) && hit->t[0] > 0)
		hit->p = ray_at(r, hit->t[0]);
	else
		hit->p = ray_at(r, hit->t[1]);
	hit->normal = normal_at(trans, hit, cy);
	hit->reflect = vector_reflect(&r->dir, &hit->normal);
}

bool	ray_intersect_cy(t_ray *r, t_cylinder cy, t_hit *hit)
{
	t_ray	trans;
	double	abc[3];
	double	discriminant;
	double	t[2];

	trans = ray_transform(r, cy.transform);
	abc[0] = pow(trans.dir.x, 2.) + pow(trans.dir.y, 2.);
	if (abc[0] < EPSILON)
		return (false);
	abc[1] = (2. * trans.origin.x * trans.dir.x)
		+ (2. * trans.origin.y * trans.dir.y);
	abc[2] = pow(trans.origin.x, 2.)
		+ pow(trans.origin.y, 2.) - pow(cy.dia * 0.5, 2);
	discriminant = pow(abc[1], 2.) - (4. * abc[0] * abc[2]);
	if (discriminant < 0)
		return (false);
	t[0] = (-abc[1] - sqrt(discriminant)) / (2 * abc[0]);
	t[1] = (-abc[1] + sqrt(discriminant)) / (2 * abc[0]);
	if (t[0] > t[1])
		fswap(&t[0], &t[1]);
	if (!check_hit(&trans, &cy, hit, t))
		return (false);
	set_hit(r, &trans, hit, &cy);
	return (true);
}
