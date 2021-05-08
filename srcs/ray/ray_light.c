/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_light.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 22:26:14 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:14:16 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	ray_light_set_default(t_rgb *diff, t_rgb *spec)
{
	*diff = rgb_new(0, 0, 0);
	*spec = rgb_new(0, 0, 0);
}

/*
** ray_light() implements the phong lighting model
** to accurately light each pixel using the following
** three ingredients:
** - Ambient
** - Diffuse
** - Specular
**
** It covers 2 main edge cases using dot products:
** - The angle between normal and light vector where
** negative means light is on the other side of the surface
** - angle between reflection vector and the eye vector
** negative means light is reflecting away from the eye
**
** @PARAM {t_scene}	*scene
** @PARAM {t_ray}	*ray
** @PARAM {t_light}	*light
** @RETURN {t_rgb}
*/

t_rgb	ray_light(t_ray *ray, t_light *light)
{
	t_rgb		rgb[4];
	t_vector	v[3];
	double		dot[2];
	t_vector	eyevec;

	rgb[0] = rgb_scale(light->color, light->ratio);
	rgb[1] = rgb_add(&ray->color, &rgb[0]);
	v[0] = vector_norm(point_sub_point(&light->origin, &ray->hits->p));
	dot[0] = vector_dot(&v[0], &ray->hits->normal);
	if (dot[0] < 0)
		ray_light_set_default(&rgb[2], &rgb[3]);
	else
	{
		rgb[2] = rgb_scale(rgb[1], DIFFUSE * dot[0]);
		v[1] = vector_negate(v[0]);
		v[1] = vector_reflect(&v[1], &ray->hits->normal);
		eyevec = vector_negate(ray->dir);
		dot[1] = vector_dot(&v[1], &eyevec);
		if (dot[1] <= 0)
			rgb[3] = rgb_new(0, 0, 0);
		else
			rgb[3] = rgb_scale(rgb[0], SPECULAR * pow(dot[1], SHININESS));
	}
	return (rgb_add_multiple(rgb + 2, 2));
}
