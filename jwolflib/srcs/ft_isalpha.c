/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/17 14:17:14 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/07/07 08:32:24 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
