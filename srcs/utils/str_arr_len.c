/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_arr_len.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 11:40:15 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/02/20 17:47:43 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	str_arr_len(const char **arr)
{
	int	idx;

	if (!arr)
		return (-1);
	idx = 0;
	while (arr[idx])
		idx++;
	return (idx);
}
