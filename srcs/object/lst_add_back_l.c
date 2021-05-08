/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_add_back_l.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 11:33:42 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:28:24 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	lst_add_back_l(t_scene *scene, t_light *new)
{
	t_light	*cur;

	if (new == NULL)
		return ;
	else if (scene->lights == NULL)
		scene->lights = new;
	else
	{
		cur = scene->lights;
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
