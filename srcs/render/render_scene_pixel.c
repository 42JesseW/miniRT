/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_scene_pixel.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: null <null@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 11:48:28 by null          #+#    #+#                 */
/*   Updated: 2021/03/04 15:55:31 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static bool	object_except(t_ray *ray)
{
	t_vector	eyev;
	t_vector	rnormal;

	if (object_is_planar(ray->hits->type))
	{
		eyev = vector_negate(ray->dir);
		rnormal = vector_negate(ray->hits->normal);
		if (vector_dot(&rnormal, &eyev) > 0)
		{
			ray->hits->normal = vector_negate(ray->hits->normal);
			return (true);
		}
	}
	return (false);
}

static bool	is_t_switch(t_ray *r, double t)
{
	return (((r->hits->t[1] < r->hits->t[0]) && r->hits->t[1] > 0) || t < 0);
}

static bool	is_shadowed(t_scene *scene, t_light *light, t_ray *ray)
{
	t_ray		shad_ray;
	t_point		adjusted;
	t_vector	v[2];
	double		tdist[2];
	bool		shadowed;

	object_except(ray);
	v[0] = vector_scale(ray->hits->normal, EPSILON);
	adjusted = point_add_vector(&ray->hits->p, &v[0]);
	v[1] = point_sub_point(&light->origin, &adjusted);
	tdist[0] = vector_mag(v[1]);
	v[1] = vector_norm(v[1]);
	shad_ray = ray_new(adjusted, v[1], NULL);
	shadowed = false;
	if (object_loop(scene, &shad_ray, false))
	{
		tdist[1] = shad_ray.hits->t[0];
		if (is_t_switch(&shad_ray, tdist[1]))
			tdist[1] = shad_ray.hits->t[1];
		if (tdist[1] > 0 && tdist[1] < tdist[0])
			shadowed = true;
	}
	ray_destroy(&shad_ray);
	return (shadowed);
}

/*
** render_scene_pixel_shade() firstly checks
** if the ray has hit something. If this is
** the case, then check for each light if it
** is blocked by another object. If not, add
** the light's light to a rgb[0] light
**
**	@PARAM {t_scene}	*scene
**	@PARAM {t_ray}		*ray
**	@RETURN {t_rgb}
*/

static t_rgb	render_scene_pixel_shade(t_scene *scene, t_ray *ray)
{
	t_rgb		rgb[2];
	t_light		*light;
	t_vector	eyev;

	rgb[0] = ray->color;
	if (ray->hits && (ray->hits->t[0] > 0 || ray->hits->t[1] > 0))
	{
		light = scene->lights;
		rgb[0] = rgb_scale(rgb_add(&rgb[0], &scene->a_color), scene->a_ratio);
		while (light)
		{
			if (!is_shadowed(scene, light, ray))
			{
				eyev = vector_negate(ray->dir);
				if (vector_dot(&ray->hits->normal, &eyev) > 0)
				{
					rgb[1] = ray_light(ray, light);
					rgb[0] = rgb_add(&rgb[0], &rgb[1]);
				}
			}
			light = light->next;
		}
	}
	ray_destroy(ray);
	return (rgb[0]);
}

/*
** render_scene_pixel() creates a new camera ray
** and shoots it into the scene. It returns the
** shaded color of the hit object.
**
**	@PARAM {t_scene}	*scene
**	@PARAM {t_data}		*img
**	@PARAM {int}		x
**	@PARAM {int}		y
**	@RETURN {t_rgb}
*/

t_rgb	render_scene_pixel(t_scene *scene, t_data *img, int x, int y)
{
	t_matrix	view;
	t_ray		cam_ray;
	float		ndc_xy[2];
	float		screen_xy[2];

	ndc_xy[0] = (x + 0.5) / scene->width;
	ndc_xy[1] = (y + 0.5) / scene->height;
	screen_xy[0] = (2 * ndc_xy[0] - 1) * img->img_ratio * img->fov_scale;
	screen_xy[1] = (1 - 2 * ndc_xy[1]) * img->fov_scale;
	cam_ray.origin = scene->current_cam->origin;
	cam_ray.dir = vector_new(screen_xy[0], screen_xy[1], -1);
	view = matrix_get_view(cam_ray.origin,
			point_add_vector(&cam_ray.origin, &scene->current_cam->orient));
	if (!view.m)
		exit_minirt(error_new("set_cam_ray() -> ", ENOMEM), scene);
	cam_ray.dir = vector_norm(matrix_apply_v(view, &cam_ray.dir));
	matrix_free(view);
	cam_ray.dirtrans = vector_new_one(INFINITY);
	cam_ray.hits = NULL;
	cam_ray.color = rgb_new(0, 0, 0);
	object_loop(scene, &cam_ray, false);
	return (render_scene_pixel_shade(scene, &cam_ray));
}
