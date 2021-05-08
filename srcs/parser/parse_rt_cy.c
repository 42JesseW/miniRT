/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_rt_cy.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 13:14:30 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:26:01 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	set_object_transform(t_cylinder *cy)
{
	t_vector	abc[3];
	t_vector	tmp;
	t_matrix	m[5];
	t_point		p[3];

	tmp = vector_new(0., 1., 0.);
	if (fabs(cy->orient.y) == 1.)
		tmp = vector_new(0., 0., 1.);
	abc[0] = vector_norm(vector_cross(&tmp, &cy->orient));
	abc[1] = vector_norm(vector_cross(&cy->orient, &abc[0]));
	abc[2] = vector_norm(cy->orient);
	m[0] = matrix_get_trans(cy->origin);
	p[0] = point_new(abc[0].x, abc[0].y, abc[0].z);
	p[1] = point_new(abc[1].x, abc[1].y, abc[1].z);
	p[2] = point_new(abc[2].x, abc[2].y, abc[2].z);
	m[1] = matrix_get_rot(p[0], p[1], p[2]);
	m[2] = matrix_get_scale(vector_new(1., 1., 1.));
	m[3] = matrix_multiply(m[2], m[1]);
	m[4] = matrix_multiply(m[0], m[3]);
	cy->transform = matrix_inverse(m[4]);
	matrix_free_mult(m, 5);
	if (!cy->transform.m)
		matrix_free(cy->transform);
}

static void	set_object(t_error *err, t_object *cy, const char **line)
{
	cy->elem.cy.origin = parse_util_point(line[1], err, false);
	if (err->msg)
		return ;
	cy->elem.cy.orient = parse_util_vector(line[2], err, true);
	if (err->msg)
		return ;
	if (!str_is_numeric(line[3], true) || !str_is_numeric(line[4], true))
	{
		*err = error_new("parse_cy() -> invalid dia or size", EPERM);
		return ;
	}
	cy->elem.cy.dia = ft_atof(line[3]);
	cy->elem.cy.height = ft_atof(line[4]);
	cy->elem.cy.color = parse_util_color(line[5], err);
	if (err->msg)
		return ;
	if (!rgb_is_valid(cy->elem.cy.color))
	{
		*err = error_new("parse_cy() -> invalid color", EPERM);
		return ;
	}
	set_object_transform(&cy->elem.cy);
	if (!cy->elem.cy.transform.m)
		*err = error_new("parse_cy() -> ", ENOMEM);
}

/*
** parse_cy() parses a cylinder which when
** specified correctly should look like this:
** cy 50.0,0.0,20.6 0.0,0.0,1.0 10,0,255 14.2 21.42
**
** @PARAM	{t_scene*}		scene
** @PARAM	{const char**}	line
** @RETURN	{t_error *err}	err
*/

t_error	parse_rt_cy(t_scene *scene, const char **line)
{
	t_object	*cy;
	t_error		err;

	if (str_arr_len(line) != 6)
		return (error_new("parse_cy()-> invalid component amount", EPERM));
	cy = object_new(CYLINDER);
	if (!cy || !cy->type)
		return (object_free(error_new("parse_cy()-> ", ENOMEM), cy));
	err = error_new(NULL, 0);
	set_object(&err, cy, line);
	if (err.msg)
		return (object_free(err, cy));
	lst_add_back_obj(scene, cy);
	str_arr_free(line);
	return (err);
}
