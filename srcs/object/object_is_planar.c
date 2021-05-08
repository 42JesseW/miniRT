/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   object_is_planar.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/07 19:31:10 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:28:46 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	object_is_planar(const char *type)
{
	return (ft_strcmp(type, TRIANGLE) == 0
		|| ft_strcmp(type, SQUARE) == 0
		|| ft_strcmp(type, PLANE) == 0);
}
