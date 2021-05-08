/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_scale.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/06 20:58:58 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 13:23:49 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	vector_scale(t_vector v, double n)
{
	t_vector	out;

	out.x = v.x * n;
	out.y = v.y * n;
	out.z = v.z * n;
	out.w = 0;
	return (out);
}
