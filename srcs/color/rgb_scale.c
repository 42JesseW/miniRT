/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rgb_scale.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 15:08:46 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 12:06:45 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb	rgb_scale(t_rgb c, double n)
{
	t_rgb	out;

	out.r = c.r * n;
	out.g = c.g * n;
	out.b = c.b * n;
	return (out);
}
