/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_hit_lst_add.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/07 19:44:34 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:12:48 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static bool	is_front_and_closest(t_ray *ray, t_hit *hit, t_hit *cur)
{
	double	dist[2];

	dist[0] = point_dist(&hit->p, &ray->origin);
	dist[1] = point_dist(&cur->p, &ray->origin);
	if (cur->t[0] < 0 && cur->t[1] < 0)
		return (true);
	return ((hit->t[0] > 0 || hit->t[1] > 0) && dist[0] < dist[1]);
}

void	ray_hit_lst_add(t_ray *ray, t_hit *hit)
{
	t_hit	*cur;
	t_hit	*prev;

	if (ray->hits == NULL)
		ray->hits = hit;
	else
	{
		prev = NULL;
		cur = ray->hits;
		while (cur != NULL)
		{
			if (is_front_and_closest(ray, hit, cur))
			{
				if (prev != NULL)
					prev->next = hit;
				if (cur == ray->hits)
					ray->hits = hit;
				hit->next = cur;
				return ;
			}
			prev = cur;
			cur = cur->next;
		}
		prev->next = hit;
	}
}
