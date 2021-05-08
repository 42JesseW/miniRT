/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 11:18:29 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:47:55 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
** create a scene struct and parse the .rt file data
** into it.
**
** @PARAM	{const char*} file
** @RETURN	{t_scene*} scene
*/

t_scene	*scene_init(const char *file)
{
	t_scene	*scene;
	char	*line;
	int		ret;

	scene = scene_new();
	scene->rt_file_fd = open(file, O_RDONLY);
	if (scene->rt_file_fd == -1)
		exit_minirt(error_new("init_scene() failed", EBADF), NULL);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(scene->rt_file_fd, &line);
		if (ret == -1)
			exit_minirt(error_new("init_scene() failed", EAGAIN), scene);
		parse_rt(scene, line);
		free(line);
	}
	if (!scene->cams || scene->a_ratio == -1 || scene->height == -1)
		exit_minirt(error_new("init_scene() failed", EPERM), scene);
	scene->current_cam = scene->cams;
	close(scene->rt_file_fd);
	return (scene);
}
