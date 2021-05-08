/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_add_back_c.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 11:30:46 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:28:21 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
** lst_add_back_c() builds a cyclical doubly linked
** list which is used to make sure you can switch
** forwards and backwards between cameras and you
** start and the first camera when reaching the end.
**
** @PARAM	{t_scene*}	scene
** @PARAM	{t_camera*}	new
** @RETURN	{void}
*/

void	lst_add_back_c(t_scene *scene, t_camera *new)
{
	t_camera	*cur;

	if (new == NULL)
		return ;
	else if (scene->cams == NULL)
		scene->cams = new;
	else
	{
		cur = scene->cams;
		while (cur)
		{
			if (cur->next == scene->cams)
			{
				cur->next = new;
				new->prev = cur;
				new->next = scene->cams;
				scene->cams->prev = new;
				return ;
			}
			cur = cur->next;
		}
	}
}
