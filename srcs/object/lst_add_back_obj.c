/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_add_back_obj.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 11:27:14 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:28:27 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	lst_add_back_obj(t_scene *scene, t_object *new)
{
	t_object	*cur;

	if (new == NULL)
		return ;
	else if (scene->objects == NULL)
		scene->objects = new;
	else
	{
		cur = scene->objects;
		while (cur)
		{
			if (cur->next == NULL)
			{
				cur->next = new;
				return ;
			}
			cur = cur->next;
		}
	}
}
