/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_clear_c.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 11:31:54 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:28:32 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
** Free up cyclical linked list
**
**	@PARAM	{t_camera*}	start
**	@RETURN	{void}
*/

void	lst_clear_c(t_camera **start)
{
	t_camera	*cur;
	t_camera	*prev;

	cur = *start;
	if (cur && cur->next != cur)
	{
		cur = cur->next;
		while (cur != *start)
		{
			prev = cur;
			cur = cur->next;
			free(prev);
		}
	}
	free(cur);
	*start = NULL;
	return ;
}
