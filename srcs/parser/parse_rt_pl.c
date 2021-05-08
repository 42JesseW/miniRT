/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_rt_pl.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 16:23:10 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:27:29 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
** parse_pl() parses a sphere which when
** specified correctly should look like this:
** pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
**
** @PARAM	{t_scene*}		scene
** @PARAM	{const char**}	line
** @RETURN	{t_error *err}	err
*/

t_error	parse_rt_pl(t_scene *scene, const char **line)
{
	t_object	*pl;
	t_error		err;

	if (str_arr_len(line) != 4)
		return (error_new("parse_pl()-> invalid component amount", EPERM));
	pl = object_new(PLANE);
	if (!pl || !pl->type)
		return (object_free(error_new("parse_pl()-> ", ENOMEM), pl));
	err = error_new(NULL, 0);
	pl->elem.pl.origin = parse_util_point(line[1], &err, false);
	if (err.msg)
		return (object_free(err, pl));
	pl->elem.pl.orient = parse_util_vector(line[2], &err, true);
	if (err.msg)
		return (object_free(err, pl));
	pl->elem.pl.color = parse_util_color(line[3], &err);
	if (err.msg)
		return (object_free(err, pl));
	if (!rgb_is_valid(pl->elem.pl.color))
		return (object_free(error_new("parse_pl()-> invalid rgb", EPERM), pl));
	lst_add_back_obj(scene, pl);
	str_arr_free(line);
	return (err);
}
