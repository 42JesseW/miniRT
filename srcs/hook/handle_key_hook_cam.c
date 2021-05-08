/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_key_hook_cam.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 13:30:36 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 12:10:25 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
** handle_key_hook_cam() is called from
** handle_key_hook() when one of its corresponding
** keys is pressed. These are:
**
**  [Q] [previous camera]
**  [E] [next camera]
**
**	@PARAM	{t_scene*}	scene
**	@PARAM	{t_key}		key
**	@RETURN {int}
*/

int	handle_key_hook_cam(t_scene *scene, t_key key)
{
	t_data	img;

	if (scene->current_cam->next == scene->current_cam)
		return (0);
	img.img = mlx_new_image(scene->mlx, scene->width, scene->height);
	if (!img.img)
		exit_minirt((t_error){"handle_key_hook_cam()-> ", 0}, scene);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.ll, &img.endian);
	scene->mlx_image_buf = img;
	if (key == CAM_PREV)
		scene->current_cam = scene->current_cam->prev;
	else
		scene->current_cam = scene->current_cam->next;
	render_scene(scene, &scene->mlx_image_buf);
	mlx_clear_window(scene->mlx, scene->mlx_window);
	mlx_put_image_to_window(
		scene->mlx,
		scene->mlx_window,
		scene->mlx_image_buf.img, 0, 0);
	mlx_destroy_image(scene->mlx, scene->mlx_image.img);
	scene->mlx_image = img;
	scene->mlx_image_buf = (t_data){NULL, NULL, 0, 0, 0, 0, 0};
	return (0);
}
