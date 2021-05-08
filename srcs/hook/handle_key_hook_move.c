/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_key_hook_move.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 13:29:58 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 12:22:32 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	set_camera_origin(t_scene *scene, t_key key)
{
	t_point	*origin;
	double	stepsize;

	stepsize = CAMERA_STEP_SIZE;
	origin = &scene->current_cam->origin;
	if (key == MOVE_UP || key == LMOVE_DOWN || key == RMOVE_DOWN)
	{
		if (key == LMOVE_DOWN || key == RMOVE_DOWN)
			stepsize = -stepsize;
		origin->y += stepsize;
	}
	else if (key == MOVE_LEFT || key == MOVE_RIGHT)
	{
		if (key == MOVE_LEFT)
			stepsize = -stepsize;
		origin->x += stepsize;
	}
	else
	{
		if (key == MOVE_BACK)
			stepsize = -stepsize;
		origin->z += stepsize;
	}
}

/*
** handle_key_hook_move() is called from
** handle_key_hook() when one of its corresponding
** keys is pressed. These are:
**
** [Space]       [move up]      (y + 1)
** [Shift]       [move down]    (y - 1)
** [left arrow]  [move left]    (x - 1)
** [top arrow]   [move forward] (z + 1)
** [right arrow] [move right]   (x + 1)
** [down arrow]  [move back]    (z - 1)
**
**	@PARAM	{t_scene*}	scene
**	@PARAM	{t_key}		key
**	@RETURN	{int}		0
*/

int	handle_key_hook_move(t_scene *scene, t_key key)
{
	t_data	img;

	img.img = mlx_new_image(scene->mlx, scene->width, scene->height);
	if (!img.img)
		exit_minirt((t_error){"handle_key_hook_move()-> ", 0}, scene);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.ll, &img.endian);
	scene->mlx_image_buf = img;
	set_camera_origin(scene, key);
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
