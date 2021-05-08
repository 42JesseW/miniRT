/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_ru.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 11:46:56 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/10/02 11:46:56 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
** parse_ru() parses the resolution which when
** specified correctly should look like this:
** R 1920 1080
**
** If the declared size of the scene is
** greater than the display resolution,
** the window size will be set depending
** to the current display resolution.
**
** @PARAM	{t_scene*}		scene
** @PARAM	{const char**}	line
** @PARAM	{t_error *err}	err
** @RETURN	{void}
*/

t_error	parse_rt_ru(t_scene *scene, const char **line)
{
	int	height;
	int	width;

	if (str_arr_len(line) != 3)
		return (error_new("parse_ru()-> invalid component amount", EPERM));
	if (scene->height != -1)
		return (error_new("parse_ru()-> R specified multiple times", EPERM));
	if (!str_is_numeric(line[1], false) || !str_is_numeric(line[2], false))
		return (error_new("parse_ru()-> wrong format", EPERM));
	mlx_get_screen_size(scene->mlx, &scene->width, &scene->height);
	width = ft_atoi(line[1]);
	if (width < scene->width)
		scene->width = width;
	height = ft_atoi(line[2]);
	if (height < scene->height)
		scene->height = height;
	if (width <= 0 || height <= 0)
		return (error_new("parse_ru()-> zeros in height/width", EPERM));
	str_arr_free(line);
	return (error_new(NULL, 0));
}
