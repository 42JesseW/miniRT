/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_alloc.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/07 19:45:48 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 14:30:11 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_matrix	matrix_alloc(int size)
{
	t_matrix	m;
	int			i;

	m.m = malloc(sizeof(double *) * size);
	if (!m.m || size == 1)
		return (matrix_free(m));
	i = 0;
	while (i < size)
	{
		m.m[i] = malloc(sizeof(double) * size);
		if (!m.m[i])
		{
			while (i >= 0)
			{
				free(m.m[i]);
				i--;
			}
			free(m.m);
			return (m);
		}
		ft_bzero(m.m[i], sizeof(double) * size);
		i++;
	}
	m.size = size;
	return (m);
}
