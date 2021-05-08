/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_arr_free.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 11:39:52 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 13:34:37 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	str_arr_free(const char **str)
{
	int	idx;

	if (!str)
		return ;
	idx = 0;
	while (str[idx] != NULL)
	{
		free((void *)str[idx]);
		idx++;
	}
	free(str);
	return ;
}
