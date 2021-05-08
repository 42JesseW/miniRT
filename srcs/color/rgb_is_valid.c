/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rgb_is_valid.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 15:08:50 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/01/31 15:10:34 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	rgb_is_valid(t_rgb rgb)
{
	return ((rgb.r >= 0 && rgb.r <= 1.)
		&& (rgb.g >= 0 && rgb.g <= 1.)
		&& (rgb.b >= 0 && rgb.b <= 1.));
}
