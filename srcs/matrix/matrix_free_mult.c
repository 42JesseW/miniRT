/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_free_mult.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/07 19:46:57 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:52:36 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	matrix_free_mult(t_matrix *m, int amount)
{
	int	idx;

	idx = 0;
	while (idx < amount)
	{
		matrix_free(m[idx]);
		idx++;
	}
}
