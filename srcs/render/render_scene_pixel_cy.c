/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_scene_pixel_cy.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 19:40:39 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:48:17 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
** render_scene_pixel_sp() checks for intersection
** with a sphere. If it finds an intersection, it
** adds it to the list of hits.
*/

int	render_scene_pixel_cy(t_scene *sc, t_object *obj, t_ray *ray)
{
	t_cylinder	cy;
	t_hit		*hit;

	cy = obj->elem.cy;
	hit = ray_hit_new_default();
	if (!hit)
	{
		ray_destroy(ray);
		exit_minirt(error_new("renders_scene_pixel_cy()", ENOMEM), sc);
	}
	if (ray_intersect_cy(ray, cy, hit))
	{
		hit->obj = obj;
		hit->type = CYLINDER;
		ray_hit_lst_add(ray, hit);
		if ((hit->t[0] > 0 || hit->t[1] > 0) && hit == ray->hits)
			ray->color = obj->elem.cy.color;
	}
	else
		free(hit);
	return (0);
}
