/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_rt_l.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 14:45:27 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:27:17 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_error	free_light(t_error err, t_light *lit)
{
	free(lit);
	return (err);
}

/*
** parse_l() parses a light which when
** specified correctly should look like this:
** l -40.0,50.0,0.0 0.6 10,0,255
**
** @PARAM	{t_scene*}		scene
** @PARAM	{const char**}	line
** @RETURN	{t_error *err}	err
*/

t_error	parse_rt_l(t_scene *scene, const char **line)
{
	t_light	*lit;
	t_error	err;

	if (str_arr_len(line) != 4)
		return (error_new("parse_l()-> invalid component amount", EPERM));
	err = error_new(NULL, 0);
	lit = malloc(sizeof(t_light));
	if (!lit)
		return (error_new("parse_l()-> could not allocate light", ENOMEM));
	lit->next = NULL;
	lit->origin = parse_util_point(line[1], &err, false);
	if (err.msg)
		return (free_light(err, lit));
	lit->ratio = ft_atof(line[2]);
	if (!str_is_numeric(line[2], true) || lit->ratio < 0.0 || lit->ratio > 1.0)
		return (free_light(error_new("parse_l()-> invalid ratio", EPERM), lit));
	lit->color = parse_util_color(line[3], &err);
	if (err.msg)
		return (err);
	if (!rgb_is_valid(lit->color))
		return (free_light(error_new("parse_l()-> invalid color", EPERM), lit));
	lst_add_back_l(scene, lit);
	str_arr_free(line);
	return (err);
}
