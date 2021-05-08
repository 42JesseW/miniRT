/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_destroy.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 22:25:54 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:48:57 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	ray_destroy(t_ray *ray)
{
	t_hit	*hit;
	t_hit	*tmp;

	hit = ray->hits;
	if (hit)
	{
		while (hit)
		{
			tmp = hit;
			hit = hit->next;
			free(tmp);
		}
	}
}
