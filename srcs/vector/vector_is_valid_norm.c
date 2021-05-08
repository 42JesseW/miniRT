/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_is_valid_norm.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/06 20:58:34 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 15:26:14 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	vector_is_valid_norm(t_vector *v)
{
	return (fabs(vector_mag(*v) - 1.) < __DBL_EPSILON__);
}
