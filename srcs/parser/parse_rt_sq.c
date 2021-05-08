/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_rt_sq.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 13:28:55 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:27:46 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	set_object_triangles(t_square *sq)
{
	t_vector	cross[3];
	t_vector	v[4];
	t_vector	tmp[2];
	double		half_side;

	half_side = sq->side * 0.5;
	tmp[0] = vector_new(0., 0., 1.);
	if (fabs(sq->orient.z) == 1.)
		tmp[0] = vector_new(1., 0., 0.);
	cross[0] = vector_norm(vector_cross(&tmp[0], &sq->orient));
	cross[1] = vector_norm(vector_cross(&sq->orient, &cross[0]));
	cross[2] = vector_norm(vector_cross(&sq->orient, &tmp[0]));
	tmp[1] = vector_new(sq->origin.x, sq->origin.y, sq->origin.z);
	v[0] = vector_scale(vector_add_vector(&cross[1], &cross[0]), half_side);
	v[0] = vector_add_vector(&tmp[1], &v[0]);
	v[1] = vector_scale(vector_sub_vector(&cross[1], &cross[0]), half_side);
	v[1] = vector_add_vector(&tmp[1], &v[1]);
	v[2] = vector_scale(vector_sub_vector(&cross[2], &cross[1]), half_side);
	v[2] = vector_add_vector(&tmp[1], &v[2]);
	v[3] = vector_scale(vector_sub_vector(&cross[0], &cross[1]), half_side);
	v[3] = vector_add_vector(&tmp[1], &v[3]);
	sq->tr[0] = (t_triangle){v[0], v[1], v[2], sq->color};
	sq->tr[1] = (t_triangle){v[0], v[2], v[3], sq->color};
}

static void	set_object(t_error *err, t_object *sq, const char **line)
{
	sq->elem.sq.origin = parse_util_point(line[1], err, false);
	if (err->msg)
		return ;
	sq->elem.sq.orient = parse_util_vector(line[2], err, true);
	if (err->msg)
		return ;
	if (!str_is_numeric(line[3], true))
	{
		*err = error_new("parse_sq()-> Invalid side", EPERM);
		return ;
	}
	sq->elem.sq.side = ft_atof(line[3]);
	sq->elem.sq.color = parse_util_color(line[4], err);
	if (err->msg)
		return ;
	if (!rgb_is_valid(sq->elem.sq.color))
	{
		*err = error_new("parse_sq()-> invalid color", EPERM);
		return ;
	}
	set_object_triangles(&sq->elem.sq);
}

/*
** parse_sq() parses a square which when
** specified correctly should look like this:
** sq 0.0,0.0,20.6 1.0,0.0,0.0 12.6 255,0,255
**
** @PARAM	{t_scene*}		scene
** @PARAM	{const char**}	line
** @RETURN	{t_error *err}	err
*/

t_error	parse_rt_sq(t_scene *scene, const char **line)
{
	t_object	*sq;
	t_error		err;

	if (str_arr_len(line) != 5)
		return (error_new("parse_sq()-> invalid component amount", EPERM));
	sq = object_new(SQUARE);
	if (!sq || !sq->type)
		return (object_free(error_new("parse_sq()-> ", ENOMEM), sq));
	err = error_new(NULL, 0);
	set_object(&err, sq, line);
	if (err.msg)
		return (object_free(err, sq));
	lst_add_back_obj(scene, sq);
	str_arr_free(line);
	return (err);
}
