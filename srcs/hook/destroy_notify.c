/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroy_notify.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 13:18:41 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:53:44 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	destroy_notify(t_scene *scene)
{
	exit_minirt(error_new(NULL, 0), scene);
	return (0);
}
