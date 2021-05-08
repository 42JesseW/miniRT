/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_new.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 11:43:58 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 12:09:06 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_error	error_new(const char *msg, int no)
{
	t_error	err;

	err.msg = msg;
	err.no = no;
	return (err);
}
