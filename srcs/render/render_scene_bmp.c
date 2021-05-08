/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_scene_bmp.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 13:21:07 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 13:50:34 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <fcntl.h>

static void	write_file_header(t_scene *scene, int fd, int padd_amount)
{
	unsigned char	file_header[BMP_FILE_HEADER_SIZE];
	int				file_size;

	file_size = BMP_FILE_HEADER_SIZE + BMP_INFO_HEADER_SIZE;
	file_size += scene->width * scene->height + padd_amount * scene->height;
	ft_bzero(file_header, BMP_FILE_HEADER_SIZE);
	file_header[0] = 'B';
	file_header[1] = 'M';
	file_header[2] = file_size;
	file_header[3] = file_size >> 8;
	file_header[4] = file_size >> 16;
	file_header[5] = file_size >> 24;
	file_header[10] = sizeof(file_header) + BMP_INFO_HEADER_SIZE;
	if (write(fd, file_header, sizeof(file_header)) == -1)
	{
		close(fd);
		exit_minirt(error_new("render_scene_bmp() ->", EAGAIN), scene);
	}
}

static void	write_info_header(t_scene *scene, int fd)
{
	unsigned char	information_header[BMP_INFO_HEADER_SIZE];

	ft_bzero(information_header, BMP_INFO_HEADER_SIZE);
	information_header[0] = BMP_INFO_HEADER_SIZE;
	information_header[4] = scene->width;
	information_header[5] = scene->width >> 8;
	information_header[6] = scene->width >> 16;
	information_header[7] = scene->width >> 24;
	information_header[8] = scene->height;
	information_header[9] = scene->height >> 8;
	information_header[10] = scene->height >> 16;
	information_header[11] = scene->height >> 24;
	information_header[12] = 1;
	information_header[14] = 24;
	if (write(fd, information_header, sizeof(information_header)) == -1)
	{
		close(fd);
		exit_minirt(error_new("render_scene_bmp() ->", EAGAIN), scene);
	}
}

static bool	write_body(t_scene *scene, int fd, int padd_amount, char *padding)
{
	unsigned char	color[3];
	char			*addr;
	int				y;
	int				x;

	y = scene->height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < scene->width)
		{
			addr = scene->mlx_image.addr;
			addr += (y * scene->mlx_image.ll + x * (scene->mlx_image.bpp / 8));
			color[0] = (*((unsigned int *)addr));
			color[1] = (*((unsigned int *)addr)) >> 8;
			color[2] = (*((unsigned int *)addr)) >> 16;
			if (write(fd, color, 3) == -1)
				return (false);
			x++;
		}
		if (write(fd, padding, padd_amount) == -1)
			return (false);
		y--;
	}
	return (true);
}

void	render_scene_bmp(t_scene *scene)
{
	char			padding[3];
	int				padd_amount;
	int				fd;
	t_error			err;

	err = error_new(NULL, 0);
	fd = open("render.bmp", O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (fd == -1)
		err = error_new("render_scene_bmp() ->", EAGAIN);
	else
	{
		ft_bzero(padding, sizeof(padding));
		padd_amount = ((4 - (scene->width * 3) % 4) % 4);
		write_file_header(scene, fd, padd_amount);
		write_info_header(scene, fd);
		if (!write_body(scene, fd, padd_amount, padding))
			err = error_new("render_scene_bmp() ->", EAGAIN);
	}
	if (fd != -1 && close(fd) == -1)
		err = error_new("render_scene_bmp() ->", EIO);
	exit_minirt(err, scene);
}
