/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_new.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/06 20:58:52 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 13:25:15 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	vector_new(double x, double y, double z)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = 0;
	return (v);
}
