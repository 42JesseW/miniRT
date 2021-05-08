/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_dot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/06 20:58:32 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:46:55 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	vector_dot(t_vector *v1, t_vector *v2)
{
	return ((v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z));
}
