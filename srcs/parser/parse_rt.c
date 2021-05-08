/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_rt.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 11:54:07 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:24:10 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_parser		g_parsers[] = {
		(t_parser){"R", &parse_rt_ru},
		(t_parser){"A", &parse_rt_au},
		(t_parser){"c", &parse_rt_c},
		(t_parser){"l", &parse_rt_l},
		(t_parser){"sp", &parse_rt_sp},
		(t_parser){"pl", &parse_rt_pl},
		(t_parser){"sq", &parse_rt_sq},
		(t_parser){"cy", &parse_rt_cy},
		(t_parser){"tr", &parse_rt_tr},
		(t_parser){NULL, NULL}
};

static const char	**get_line_split(t_scene *scene, char *line)
{
	const char	**split;

	split = (const char **)ft_split(line, ' ');
	if (!split)
	{
		free(line);
		exit_minirt(error_new("parse_rt() failed", ENOMEM), scene);
	}
	if (!split[0])
	{
		str_arr_free(split);
		return (NULL);
	}
	return (split);
}

/*
** select the right parse function based on
** the type of object found in .rt file. parse_rt()
** free {*line} on error i.e. failed split or if {*err} is set
** free {**split} if no parser func is found
**
** @PARAM	{t_scene*} scene
** @PARAM	{char *} line
** @RETURN	{void}
*/

void	parse_rt(t_scene *scene, char *line)
{
	const char	**split;
	t_error		err;
	int			parser;

	split = get_line_split(scene, line);
	if (!split)
		return ;
	parser = 0;
	while (g_parsers[parser].type)
	{
		if (ft_strcmp(split[0], g_parsers[parser].type) == 0)
		{
			err = g_parsers[parser].func(scene, split);
			if (err.msg)
			{
				free(line);
				exit_minirt(err, scene);
			}
			return ;
		}
		parser++;
	}
	exit_minirt(error_new("parse_rt() failed-> unknown element", EPERM), scene);
}
