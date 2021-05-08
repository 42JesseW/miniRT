/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_scene_pixel_sp.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 19:31:47 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:48:23 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
** render_scene_pixel_sp() checks for intersection
** with a sphere. If it finds an intersection, it
** adds it to the list of hits.
*/

int	render_scene_pixel_sp(t_scene *sc, t_object *obj, t_ray *ray)
{
	t_sphere	sp;
	t_hit		*hit;

	sp = obj->elem.sp;
	hit = ray_hit_new_default();
	if (!hit)
	{
		ray_destroy(ray);
		exit_minirt(error_new("renders_scene_pixel_sp()", ENOMEM), sc);
	}
	if (ray_intersect_sp(ray, sp, hit))
	{
		hit->obj = obj;
		hit->type = SPHERE;
		hit->ptrans = matrix_apply_p(sp.transform, &hit->p);
		ray_hit_lst_add(ray, hit);
		if ((hit->t[0] > 0 || hit->t[1] > 0) && hit == ray->hits)
		{
			ray->color = obj->elem.sp.color;
			ray->dirtrans = matrix_apply_v(sp.transform, &ray->dir);
		}
	}
	else
		free(hit);
	return (0);
}
