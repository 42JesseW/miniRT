/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_get_cof_sign.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/10 10:31:12 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:52:42 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	matrix_get_cof_sign(int row, int col)
{
	if ((row % 2 == 1 && col % 2 == 0) || (row % 2 == 0 && col % 2 == 1))
		return (-1);
	else
		return (1);
}
