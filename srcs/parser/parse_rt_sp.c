/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_rt_sp.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 15:15:51 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:27:41 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static bool	set_transform(t_object *sp, t_error *err)
{
	t_matrix	m[3];

	m[0] = matrix_get_trans(sp->elem.sp.origin);
	m[1] = matrix_get_scale(vector_new_one(sp->elem.sp.dia * 0.5));
	m[2] = matrix_multiply(m[0], m[1]);
	sp->elem.sp.transform = matrix_inverse(m[2]);
	if (!m[0].m || !m[1].m || !m[2].m || !sp->elem.sp.transform.m)
	{
		*err = error_new("parse_sp().set_transform()", ENOMEM);
		matrix_free(sp->elem.sp.transform);
	}
	matrix_free_mult(m, 3);
	if (err->msg)
		return (false);
	else
		return (true);
}

/*
** parse_sp() parses a sphere which when
** specified correctly should look like this:
** sp 0.0,0.0,20.6 12.6 10,0,255
**
** @PARAM	{t_scene*}		scene
** @PARAM	{const char**}	line
** @RETURN	{t_error *err}	err
*/

t_error	parse_rt_sp(t_scene *scene, const char **line)
{
	t_object	*sp;
	t_error		err;

	if (str_arr_len(line) != 4)
		return (error_new("parse_sp()-> invalid component amount", EPERM));
	sp = object_new(SPHERE);
	if (!sp || !sp->type)
		return (object_free(error_new("parse_sp()-> ", ENOMEM), sp));
	err = error_new(NULL, 0);
	sp->elem.sp.origin = parse_util_point(line[1], &err, false);
	if (err.msg)
		return (object_free(err, sp));
	if (!str_is_numeric(line[2], true))
		return (object_free(error_new("parse_sp()-> invalid dia", EPERM), sp));
	sp->elem.sp.dia = ft_atof(line[2]);
	sp->elem.sp.color = parse_util_color(line[3], &err);
	if (err.msg)
		return (object_free(err, sp));
	if (!rgb_is_valid(sp->elem.sp.color))
		return (object_free(error_new("parse_sp()-> invalid rgb", EPERM), sp));
	if (!set_transform(sp, &err))
		return (object_free(err, sp));
	lst_add_back_obj(scene, sp);
	str_arr_free(line);
	return (err);
}
