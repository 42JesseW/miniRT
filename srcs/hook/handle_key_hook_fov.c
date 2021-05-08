/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_key_hook_fov.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 13:30:24 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 12:16:48 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	set_camera_orient(t_scene *scene, t_key key)
{
	t_matrix	m;
	double		rad;

	rad = -(M_PI / 16);
	if (key == FOV_RIGHT || key == FOV_DOWN)
		rad = M_PI / 16;
	m = matrix_get_rot_x(rad);
	if (key == FOV_RIGHT || key == FOV_DOWN)
		m = matrix_get_rot_y(rad);
	if (!m.m)
		exit_minirt(error_new("handle_key_hook_cam()-> ", ENOMEM), scene);
	scene->current_cam->orient = matrix_apply_v(m, &scene->current_cam->orient);
	matrix_free(m);
}

/*
** handle_key_hook_fov() is called from
** handle_key_hook() when one of its corresponding
** keys is pressed. These are:
**
**  [A] [look left]
**  [W] [look up]
**  [D] [look right]
**  [S] [look down]
**
**	@PARAM	{t_scene*}	scene
**	@PARAM	{t_key}		key
**	@RETURN {int}
*/

int	handle_key_hook_fov(t_scene *scene, t_key key)
{
	t_data		img;

	img.img = mlx_new_image(scene->mlx, scene->width, scene->height);
	if (!img.img)
		exit_minirt(error_new("handle_key_hook_cam()-> ", ENOMEM), scene);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.ll, &img.endian);
	scene->mlx_image_buf = img;
	set_camera_orient(scene, key);
	render_scene(scene, &scene->mlx_image_buf);
	mlx_clear_window(scene->mlx, scene->mlx_window);
	mlx_put_image_to_window(scene->mlx,
		scene->mlx_window,
		scene->mlx_image_buf.img, 0, 0);
	mlx_destroy_image(scene->mlx, scene->mlx_image.img);
	scene->mlx_image = img;
	scene->mlx_image_buf = (t_data){NULL, NULL, 0, 0, 0, 0, 0};
	return (0);
}
