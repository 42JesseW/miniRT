/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_is_numeric.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 11:38:44 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:47:45 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	str_is_numeric(const char *str, bool isdecimal)
{
	size_t	idx;
	bool	isnumeric;

	if (!str)
		return (false);
	idx = 0;
	if (str[idx] == '-')
		idx++;
	isnumeric = true;
	while (isnumeric)
	{
		if (!ft_isdigit(str[idx]))
		{
			if (isdecimal && str[idx] == '.' && ft_isdigit(str[idx + 1]))
			{
				isdecimal = false;
				idx++;
				continue ;
			}
			isnumeric = false;
		}
		if (isnumeric)
			idx++;
	}
	return (idx == ft_strlen(str));
}
