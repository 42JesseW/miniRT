/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_norm.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/06 20:58:54 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:47:14 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	vector_norm(t_vector v)
{
	return (vector_scale(v, 1 / vector_mag(v)));
}
