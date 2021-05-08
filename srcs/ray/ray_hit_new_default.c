/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_hit_new_default.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 22:25:58 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:49:01 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_hit	*ray_hit_new_default(void)
{
	t_hit	*hit;

	hit = malloc(sizeof(t_hit));
	if (!hit)
		return (NULL);
	hit->t[0] = INFINITY;
	hit->t[1] = INFINITY;
	hit->p = point_new_one(INFINITY);
	hit->p = point_new_one(INFINITY);
	hit->normal = vector_new_one(0);
	hit->reflect = vector_new_one(0);
	hit->obj = NULL;
	hit->type = NULL;
	hit->next = NULL;
	return (hit);
}
