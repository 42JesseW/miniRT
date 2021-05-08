/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/10 11:53:29 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:46:13 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/*
** Check if no more than 2 arguments are passed to
** the program. If there's a second argument, check
** if its '--save'. Build the scene using init_scene()
** and then call the render_loop function to start rendering.
**
**	@PARAM	{int}		argc
**	@PARAM	{char**}	argv
**	@RETURN	{int}		0
*/

int	main(int argc, char *argv[])
{
	t_scene		*scene;
	const char	*err;
	bool		save;
	size_t		fname_len;

	err = "usage: minirt [.rt file] [--save]";
	if (argc < 2 || argc > 3)
		exit_minirt(error_new(err, EPERM), NULL);
	else
	{
		fname_len = ft_strlen(argv[1]);
		if (fname_len < 3 || ft_strcmp(argv[1] + (fname_len - 3), ".rt") != 0)
			exit_minirt(error_new(err, EPERM), NULL);
		save = false;
		scene = scene_init(argv[1]);
		if (argc == 3)
		{
			if (ft_strcmp(argv[2], "--save") != 0)
				exit_minirt(error_new(err, EPERM), NULL);
			save = true;
		}
		render_loop(scene, save);
	}
	return (0);
}
