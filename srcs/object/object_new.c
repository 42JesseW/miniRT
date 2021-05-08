/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   object_new.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 11:26:35 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:51:39 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_object	*object_new(const char *type)
{
	t_object	*obj;

	obj = malloc(sizeof(t_object));
	if (!obj)
		return (NULL);
	obj->type = ft_strdup(type);
	obj->next = NULL;
	return (obj);
}
