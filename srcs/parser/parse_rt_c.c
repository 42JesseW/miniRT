/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_rt_c.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 11:44:52 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:24:32 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	set_cam(t_error *err, t_camera *cam, const char **line)
{
	cam->next = cam;
	cam->prev = cam;
	cam->origin = parse_util_point(line[1], err, false);
	if (err->msg)
		return ;
	cam->orient = parse_util_vector(line[2], err, true);
	if (err->msg)
		return ;
	cam->fov = ft_atoi(line[3]);
	if (!str_is_numeric(line[3], false) || cam->fov <= 0 || cam->fov >= 180)
	{
		*err = error_new("parse_c()-> fov not in range [0,180]", EPERM);
		return ;
	}
}

/*
** parse_c() parses a camera which when
** specified correctly should look like this:
** c -50.0,0,20 0,0,1 70
**
** @PARAM	{t_scene*}		scene
** @PARAM	{const char**}	line
** @RETURN	{t_error *err}	err
*/

t_error	parse_rt_c(t_scene *scene, const char **line)
{
	t_camera	*cam;
	t_error		err;

	if (str_arr_len(line) != 4)
		return (error_new("parse_c()-> invalid component amount", EPERM));
	err = error_new(NULL, 0);
	cam = malloc(sizeof(t_camera));
	if (!cam)
		return (error_new("parse_c()-> could not allocate camera", ENOMEM));
	set_cam(&err, cam, line);
	if (err.msg)
	{
		free(cam);
		return (err);
	}
	lst_add_back_c(scene, cam);
	str_arr_free(line);
	return (err);
}
