/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_clear_l.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 11:34:00 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:28:36 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	lst_clear_l(t_light **start)
{
	t_light	*light;
	t_light	*cur;

	light = *start;
	while (light)
	{
		cur = light;
		light = cur->next;
		free(cur);
	}
	*start = NULL;
	return ;
}
