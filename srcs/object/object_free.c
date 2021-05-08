/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   object_free.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 11:35:36 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:29:10 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_error	object_free(t_error err, t_object *obj)
{
	if (obj)
	{
		if (obj->type)
			free((void *)obj->type);
		free(obj);
	}
	return (err);
}
