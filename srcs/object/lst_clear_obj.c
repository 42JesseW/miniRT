/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_clear_obj.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 11:28:37 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:29:05 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	lst_clear_obj(t_object *start)
{
	t_object	*obj;
	t_object	*cur;

	obj = start;
	while (obj)
	{
		cur = obj;
		obj = cur->next;
		if (ft_strcmp(cur->type, SPHERE) == 0)
			matrix_free(cur->elem.sp.transform);
		if (ft_strcmp(cur->type, CYLINDER) == 0)
			matrix_free(cur->elem.cy.transform);
		free((void *)cur->type);
		free(cur);
	}
	return ;
}
