/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_new_one.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/06 20:58:38 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 13:22:41 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	vector_new_one(double xyz)
{
	t_vector	v;

	v.x = xyz;
	v.y = xyz;
	v.z = xyz;
	v.w = 0;
	return (v);
}
