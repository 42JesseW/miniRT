/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rgb_add_multiple.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 15:08:26 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:54:28 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb	rgb_add_multiple(t_rgb *rgb, int size)
{
	t_rgb	combined;
	int		idx;

	idx = 0;
	combined = rgb_new(0, 0, 0);
	while (idx < size)
	{
		combined = rgb_add(&combined, &rgb[idx]);
		idx++;
	}
	return (combined);
}
