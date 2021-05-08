/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_scene_pixel_pl.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 19:32:09 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:48:20 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
** render_scene_pixel_pl() checks for intersection
** with a plane. If it finds an intersection, it
** adds it to the list of hits.
*/

int	render_scene_pixel_pl(t_scene *sc, t_object *obj, t_ray *ray)
{
	t_plane	pl;
	t_hit	*hit;

	pl = obj->elem.pl;
	hit = ray_hit_new_default();
	if (!hit)
	{
		ray_destroy(ray);
		exit_minirt(error_new("renders_scene_pixel_pl()", ENOMEM), sc);
	}
	if (ray_intersect_pl(ray, pl, hit))
	{
		hit->obj = obj;
		hit->type = PLANE;
		ray_hit_lst_add(ray, hit);
		if ((hit->t[0] > 0 || hit->t[1] > 0) && hit == ray->hits)
			ray->color = obj->elem.pl.color;
	}
	else
		free(hit);
	return (0);
}
