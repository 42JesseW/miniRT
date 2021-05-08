/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rgb_blend.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 15:08:36 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 12:03:16 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb	rgb_blend(t_rgb *c1, t_rgb *c2)
{
	t_rgb	out;

	out.r = c1->r * c2->r;
	out.g = c1->g * c2->g;
	out.b = c1->b * c2->b;
	return (out);
}
