/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_rt_tr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 13:27:47 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:27:49 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	set_object(t_error *err, t_object *tr, const char **line)
{
	tr->elem.tr.v1 = parse_util_vector(line[1], err, false);
	if (err->msg)
		return ;
	tr->elem.tr.v2 = parse_util_vector(line[2], err, false);
	if (err->msg)
		return ;
	tr->elem.tr.v3 = parse_util_vector(line[3], err, false);
	if (err->msg)
		return ;
	tr->elem.tr.color = parse_util_color(line[4], err);
	if (err->msg)
		return ;
	if (!rgb_is_valid(tr->elem.tr.color))
	{
		*err = error_new("parse_tr()-> invalid color", EPERM);
		return ;
	}
}

/*
** parse_tr() parses a triangle which when
** specified correctly should look like this:
** tr 10.0,20.0,10.0 10.0,10.0,20.0 20.0,10.0,10.0 0,0,255
**
** @PARAM	{t_scene*}		scene
** @PARAM	{const char**}	line
** @RETURN	{t_error *err}	err
*/

t_error	parse_rt_tr(t_scene *scene, const char **line)
{
	t_object	*tr;
	t_error		err;

	if (str_arr_len(line) != 5)
		return (error_new("parse_tr()-> invalid component amount", EPERM));
	tr = object_new(TRIANGLE);
	if (!tr || !tr->type)
		return (object_free(error_new("parse_tr()-> ", ENOMEM), tr));
	err = error_new(NULL, 0);
	set_object(&err, tr, line);
	if (err.msg)
		return (object_free(err, tr));
	lst_add_back_obj(scene, tr);
	str_arr_free(line);
	return (err);
}
