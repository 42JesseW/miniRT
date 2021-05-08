/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_free.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/07 19:47:00 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:52:39 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_matrix	matrix_free(t_matrix m)
{
	int	i;

	i = 0;
	if (m.m)
	{
		while (i < m.size)
		{
			free(m.m[i]);
			i++;
		}
		free(m.m);
		m.m = NULL;
	}
	return (m);
}
