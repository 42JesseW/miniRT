/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rgb_new.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 15:08:48 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 12:06:17 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb	rgb_new(float r, float g, float b)
{
	t_rgb	out;

	out.r = r;
	out.g = g;
	out.b = b;
	return (out);
}
