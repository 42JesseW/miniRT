/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_scene_pixel_sq.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 19:36:53 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:48:25 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
** render_scene_pixel_pl() checks for intersection
** with a plane. If it finds an intersection, it
** adds it to the list of hits.
*/

int	render_scene_pixel_sq(t_scene *sc, t_object *obj, t_ray *ray)
{
	t_square	sq;
	t_hit		*hit;

	sq = obj->elem.sq;
	hit = ray_hit_new_default();
	if (!hit)
	{
		ray_destroy(ray);
		exit_minirt(error_new("renders_scene_pixel_sq()", ENOMEM), sc);
	}
	if (ray_intersect_sq(ray, sq, hit))
	{
		hit->obj = obj;
		hit->type = SQUARE;
		ray_hit_lst_add(ray, hit);
		if ((hit->t[0] > 0 || hit->t[1] > 0) && hit == ray->hits)
			ray->color = obj->elem.sq.color;
	}
	else
		free(hit);
	return (0);
}
