/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_at.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 22:25:52 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/08 22:25:53 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_point	ray_at(t_ray *r, double t)
{
	t_vector	v;

	v = vector_scale(r->dir, t);
	return (point_add_vector(&r->origin, &v));
}
