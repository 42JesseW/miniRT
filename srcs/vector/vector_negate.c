/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_negate.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/06 20:58:47 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:47:04 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	vector_negate(t_vector v)
{
	t_vector	neg;

	neg = vector_new_one(0);
	return (vector_sub_vector(&neg, &v));
}
