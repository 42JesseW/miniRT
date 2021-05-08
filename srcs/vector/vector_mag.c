/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_mag.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/06 20:58:36 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:47:01 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	vector_mag(t_vector v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}
