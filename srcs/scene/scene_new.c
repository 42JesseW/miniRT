/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene_new.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 11:20:35 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 13:38:57 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_scene	*scene_new(void)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		exit_minirt(error_new("scene_new()-> ", ENOMEM), NULL);
	scene->rt_file_fd = -1;
	scene->mlx = mlx_init();
	scene->mlx_window = NULL;
	scene->mlx_image = (t_data){NULL, NULL, 0, 0, 0, 0, 0};
	scene->mlx_image_buf = (t_data){NULL, NULL, 0, 0, 0, 0, 0};
	scene->height = -1;
	scene->width = -1;
	scene->a_ratio = -1.;
	scene->lights = NULL;
	scene->current_cam = NULL;
	scene->cams = NULL;
	scene->objects = NULL;
	return (scene);
}
