/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_reflect.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/06 20:58:56 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:47:16 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	vector_reflect(t_vector *in, t_vector *normal)
{
	t_vector	v;

	v = vector_scale(*normal, 2. * vector_dot(in, normal));
	return (vector_sub_vector(in, &v));
}
