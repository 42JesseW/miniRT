/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_minirt.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 11:44:53 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:54:22 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <string.h>

/*
** TODO cleanup object matrices
** exit the program using exit(status) after cleaning
** up the scene if it has been initiated
**
**	@PARAM	{t_error}	err
**	@PARAM	{t_scene*}	scene
**	@RETURN	{void}
*/

void	exit_minirt(t_error err, t_scene *scene)
{
	if (err.msg)
		ft_printf("Error\n%s: %s\n", err.msg, strerror(err.no));
	if (scene)
	{
		if (scene->rt_file_fd != -1)
			close(scene->rt_file_fd);
		if (scene->mlx_window)
			mlx_destroy_window(scene->mlx, scene->mlx_window);
		if (scene->mlx_image.img)
			mlx_destroy_image(scene->mlx, scene->mlx_image.img);
		lst_clear_c(&(scene->cams));
		lst_clear_l(&(scene->lights));
		lst_clear_obj(scene->objects);
		free(scene->mlx);
		free(scene);
	}
	exit(err.no);
}
