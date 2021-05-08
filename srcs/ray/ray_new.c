/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_new.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 22:26:17 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:15:01 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_ray	ray_new(t_point origin, t_vector dir, t_hit *next)
{
	t_ray	r;

	r.origin = origin;
	r.dir = dir;
	r.dirtrans = vector_new_one(INFINITY);
	r.hits = next;
	r.color = rgb_new(-1, -1, -1);
	return (r);
}
