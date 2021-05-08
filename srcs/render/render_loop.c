/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_loop.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 13:14:14 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 15:55:59 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
** render_loop() initialises mlx and creates the window.
** It then registers the required hooks into the
** available events. After this is done it builds
** the first image to render and checks if --save
** is set. If so, it writes the image to .bmp and exits.
** otherwise it will call mxl_loop()
**
** @PARAM	{t_scene*}	sc
** @PARAM	{bool}		save
** @RETURN	{void}
*/

void	render_loop(t_scene *sc, bool save)
{
	t_data	img;

	sc->mlx = mlx_init();
	if (!sc->mlx)
		exit_minirt(error_new("mlx_init()-> ", 0), sc);
	img.img = mlx_new_image(sc->mlx, sc->width, sc->height);
	if (!img.img)
		exit_minirt(error_new("mlx_new_image()-> ", 0), sc);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.ll, &img.endian);
	sc->mlx_image = img;
	render_scene(sc, &sc->mlx_image);
	if (save)
		render_scene_bmp(sc);
	sc->mlx_window = mlx_new_window(sc->mlx, sc->width, sc->height, "MiniRT");
	if (!sc->mlx_window)
		exit_minirt(error_new("mlx_new_window()-> ", 0), sc);
	mlx_hook(sc->mlx_window, 17, (1L << 17), destroy_notify, sc);
	mlx_key_hook(sc->mlx_window, &handle_key_hook, sc);
	mlx_put_image_to_window(sc->mlx, sc->mlx_window, sc->mlx_image.img, 0, 0);
	mlx_loop(sc->mlx);
}
