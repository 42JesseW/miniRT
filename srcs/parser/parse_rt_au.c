/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_rt_au.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 11:53:43 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:24:21 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
** parse_au() parses the ambient lighting into
** the t_scene object. Ambient lighting, which when
** specified correctly, should look like this:
** A 0.2 255,233,255
**
** @PARAM	{t_scene*}		scene
** @PARAM	{const char**}	line
** @RETURN	{t_error*}		err
*/

t_error	parse_rt_au(t_scene *scene, const char **line)
{
	t_rgb	rgb;
	t_error	err;

	if (str_arr_len(line) != 3)
		return (error_new("parse_au()-> invalid component amount", EPERM));
	if (scene->a_ratio != -1)
		return (error_new("parse_au()-> A specified multiple times", EPERM));
	if (!str_is_numeric(line[1], true))
		return (error_new("parse_au()-> invalid format", EPERM));
	scene->a_ratio = ft_atof(line[1]);
	if (scene->a_ratio < 0 || scene->a_ratio > 1.)
		return (error_new("parse_au()-> invalid ratio", EPERM));
	err = error_new(NULL, 0);
	rgb = parse_util_color(line[2], &err);
	if (err.msg)
		return (err);
	if (!rgb_is_valid(rgb))
		return (error_new("parse_au()-> invalid color", EPERM));
	scene->a_color = rgb;
	str_arr_free(line);
	return (err);
}
