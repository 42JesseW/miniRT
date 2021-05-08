/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 14:07:52 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 13:37:59 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
** parse_util_vector() takes in a string and an empty t_error
** object. It tries to parse the string into a valid t_vector
** object. On failure, it sets the appropriate values to err
**
** @ARG {const char*}	str
** @ARG {t_error*}		err
** @ARG {int}			norm
** @RETURN {t_vector}	vec
*/

t_vector	parse_util_vector(const char *str, t_error *err, bool norm)
{
	const char	**strs;
	t_vector	vec;

	vec = vector_new(-1., -1., -1.);
	strs = (const char **)ft_split(str, ',');
	if (!strs)
		*err = error_new("parse_util_vector()->", ENOMEM);
	else if (str_arr_len(strs) != 3)
		*err = error_new("parse_util_vector()-> invalid components", EPERM);
	else
	{
		if (!str_is_numeric(strs[0], true) || !str_is_numeric(strs[1], true)
			|| !str_is_numeric(strs[2], true))
			*err = error_new("parse_util_vector()-> invalid format", EPERM);
		vec = vector_new(ft_atof(strs[0]), ft_atof(strs[1]), ft_atof(strs[2]));
		if (norm && !(*err).msg)
		{
			if (!vector_is_valid_norm(&vec))
				*err = error_new("parse_util_vector()-> not norm", EPERM);
		}
	}
	if (strs)
		str_arr_free(strs);
	return (vec);
}

/*
** parse_util_point() takes in a string and an empty t_error
** object. It tries to parse the string into a valid t_point
** object. On failure, it sets the appropriate values to err
**
** @ARG {const char*}	str
** @ARG {t_error*}		err
** @ARG {int}			norm
** @RETURN {t_point}	pt
*/

t_point	parse_util_point(const char *str, t_error *err, bool norm)
{
	const char	**strs;
	t_point		pt;

	(void)norm;
	pt = point_new_one(-1.);
	strs = (const char **)ft_split(str, ',');
	if (!strs)
		*err = error_new("parse_util_point()->", ENOMEM);
	else if (str_arr_len(strs) != 3)
		*err = error_new("parse_util_point()-> invalid components", EPERM);
	else
	{
		if (!str_is_numeric(strs[0], true) || !str_is_numeric(strs[1], true)
			|| !str_is_numeric(strs[2], true))
			*err = error_new("parse_util_point()-> invalid format", EPERM);
		pt = point_new(ft_atof(strs[0]), ft_atof(strs[1]), ft_atof(strs[2]));
	}
	if (strs)
		str_arr_free(strs);
	return (pt);
}

static t_rgb	get_rgb(const char **strs)
{
	t_rgb	rgb;

	rgb.r = (float)ft_atoi(strs[0]) / 255.;
	rgb.g = (float)ft_atoi(strs[1]) / 255.;
	rgb.b = (float)ft_atoi(strs[2]) / 255.;
	return (rgb);
}

/*
** parse_util_color() takes in a string and empty t_error
** object. It tries to parse the string into a valid t_rgb
** object. On failure, it sets the appropriate values to err.
**
** @ARG {const char*}	str
** @ARG {t_error*}		err
** @RETURN {t_rgb}	rgb
*/

t_rgb	parse_util_color(const char *str, t_error *err)
{
	const char	**strs;
	t_rgb		rgb;

	rgb = rgb_new(-1, -1, -1);
	strs = (const char **)ft_split(str, ',');
	if (!strs)
		*err = error_new("parse_util_color() failed", ENOMEM);
	else
	{
		if (str_arr_len(strs) != 3)
			*err = error_new("parse_util_color() failed", EPERM);
		else
		{
			if (!str_is_numeric(strs[0], false)
				|| !str_is_numeric(strs[1], false)
				|| !str_is_numeric(strs[2], false))
				*err = error_new("parse_util_color() failed", EPERM);
			else
				rgb = get_rgb(strs);
		}
		str_arr_free(strs);
	}
	return (rgb);
}
