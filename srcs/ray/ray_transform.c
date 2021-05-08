/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_transform.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 22:26:19 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:49:33 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_ray	ray_transform(t_ray *ray, t_matrix m)
{
	t_ray	trans;

	trans.origin = matrix_apply_p(m, &ray->origin);
	trans.dir = matrix_apply_v(m, &ray->dir);
	trans.hits = ray->hits;
	trans.color = ray->color;
	return (trans);
}
