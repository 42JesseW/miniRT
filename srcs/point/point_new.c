/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   point_new.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/06 21:01:54 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:18:28 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_point	point_new(double x, double y, double z)
{
	t_point	p;

	p.x = x;
	p.y = y;
	p.z = z;
	p.w = 1;
	return (p);
}
