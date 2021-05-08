/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   point_new_one.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/06 21:01:52 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:21:21 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_point	point_new_one(double xyz)
{
	t_point	p;

	p.x = xyz;
	p.y = xyz;
	p.z = xyz;
	p.w = 1;
	return (p);
}
