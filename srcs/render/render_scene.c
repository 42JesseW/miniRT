/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_scene.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: null <null@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 11:46:51 by null          #+#    #+#                 */
/*   Updated: 2021/03/04 13:49:42 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

#ifdef BONUS

void	*render_scene_dispatch(void *data)
{
	int				pixel_x;
	int				pixel_y;
	t_rgb			color;
	t_thread_data	*d;

	d = (t_thread_data*)data;
	pixel_y = d->ymin;
	d->img->img_ratio = (float)d->scene->width / (float)d->scene->height;
	d->img->fov_scale = tan(d->scene->current_cam->fov * 0.5 * M_PI / 180.);
	while (pixel_y < d->ymax)
	{
		pixel_x = 0;
		while (pixel_x < d->scene->width)
		{
			color = render_scene_pixel(d->scene, d->img, pixel_x, pixel_y);
			mlx_set_pixel(d->img, pixel_x, pixel_y, color);
			pixel_x++;
		}
		pixel_y++;
	}
	free(data);
	return (NULL);
}

static t_thread_data	*get_thread_data(t_scene *scene, t_data *img
										, int thread_count, int idx)
{
	t_thread_data	*data;
	int				start;
	int				end;
	int				remainder;

	data = malloc(sizeof(t_thread_data));
	data->scene = scene;
	data->img = img;
	remainder = scene->height % thread_count;
	start = scene->height / thread_count * idx;
	if (idx == 0)
		start = 0;
	end = start + (scene->height / thread_count);
	if (idx == (thread_count - 1))
		end += remainder;
	data->ymin = start;
	data->ymax = end;
	return (data);
}

void	render_scene(t_scene *scene, t_data *img)
{
	pthread_t		*threads;
	t_thread_data	*data;
	int				thread_count;
	int				idx;

	idx = 0;
	thread_count = 4;
	threads = malloc(sizeof(pthread_t) * thread_count);
	if (!threads)
		exit_minirt(error_new("render_scene() -> ", ENOMEM), scene);
	while (idx < thread_count)
	{
		data = get_thread_data(scene, img, thread_count, idx);
		pthread_create(&threads[idx], NULL, render_scene_dispatch, data);
		idx++;
	}
	idx = 0;
	while (idx < thread_count)
	{
		pthread_join(threads[idx], NULL);
		idx++;
	}
	free(threads);
}

#else

/*
** render_scene() Configures the image and it
** then loops over each pixel to render its
** color.
**
**	@PARAM	{t_scene*}	scene
**	@PARAM	{t_data*}	img
**	@RETURN	{void}
*/

void	render_scene(t_scene *scene, t_data *img)
{
	int		pixel_x;
	int		pixel_y;
	t_rgb	color;

	pixel_y = 0;
	img->img_ratio = (float)scene->width / (float)scene->height;
	img->fov_scale = tan(scene->current_cam->fov * 0.5 * M_PI / 180.);
	while (pixel_y < scene->height)
	{
		pixel_x = 0;
		while (pixel_x < scene->width)
		{
			color = render_scene_pixel(scene, img, pixel_x, pixel_y);
			mlx_set_pixel(img, pixel_x, pixel_y, color);
			pixel_x++;
		}
		pixel_y++;
	}
}

#endif
