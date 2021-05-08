/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   object_loop.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 19:57:57 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:29:30 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_tracer	g_tracers[] = {
	(t_tracer){SPHERE, &render_scene_pixel_sp},
	(t_tracer){PLANE, &render_scene_pixel_pl},
	(t_tracer){TRIANGLE, &render_scene_pixel_tr},
	(t_tracer){SQUARE, &render_scene_pixel_sq},
	(t_tracer){CYLINDER, &render_scene_pixel_cy},
	(t_tracer){NULL, NULL}
};

bool	object_loop(t_scene *scene, t_ray *ray, bool stop_early)
{
	t_object	*obj;
	int			idx;

	idx = 0;
	obj = scene->objects;
	while (obj)
	{
		idx = 0;
		while (g_tracers[idx].type)
		{
			if (ft_strcmp(obj->type, g_tracers[idx].type) == 0)
			{
				g_tracers[idx].func(scene, obj, ray);
				break ;
			}
			idx++;
		}
		if (ray->hits && stop_early)
			return (true);
		obj = obj->next;
	}
	return (ray->hits != NULL);
}
