/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   point_dist.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/06 21:01:50 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:22:38 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	point_dist(t_point *p1, t_point *p2)
{
	double	xyz[3];

	xyz[0] = pow(p2->x - p1->x, 2);
	xyz[1] = pow(p2->y - p1->y, 2);
	xyz[2] = pow(p2->z - p1->z, 2);
	return (sqrt(xyz[0] + xyz[1] + xyz[2]));
}
