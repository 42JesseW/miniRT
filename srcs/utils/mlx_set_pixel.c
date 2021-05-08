/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_set_pixel.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 13:22:29 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 13:32:19 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	mlx_set_pixel(t_data *data, int x, int y, t_rgb c)
{
	char	*dst;
	int		rgb[3];

	if (c.r > 1.f)
		c.r = 1.f;
	if (c.g > 1.f)
		c.g = 1.f;
	if (c.b > 1.f)
		c.b = 1.f;
	dst = data->addr + (y * data->ll + x * (data->bpp / 8));
	rgb[0] = (int)(c.r * 255.) << 16;
	rgb[1] = (int)(c.g * 255.) << 8;
	rgb[2] = (int)(c.b * 255.);
	*(unsigned int *)dst = (rgb[0] | rgb[1] | rgb[2]);
}
