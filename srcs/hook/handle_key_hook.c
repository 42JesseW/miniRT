/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_key_hook.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <jevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 13:34:45 by jevan-de      #+#    #+#                 */
/*   Updated: 2021/03/04 12:09:54 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

#ifdef BONUS

static t_handle_key	g_key_handlers[] = {
	(t_handle_key){FOV_LEFT, &handle_key_hook_fov},
	(t_handle_key){FOV_RIGHT, &handle_key_hook_fov},
	(t_handle_key){FOV_DOWN, &handle_key_hook_fov},
	(t_handle_key){CAM_PREV, &handle_key_hook_cam},
	(t_handle_key){FOV_UP, &handle_key_hook_fov},
	(t_handle_key){CAM_NEXT, &handle_key_hook_cam},
	(t_handle_key){MOVE_UP, &handle_key_hook_move},
	(t_handle_key){MOVE_LEFT, &handle_key_hook_move},
	(t_handle_key){MOVE_FORWARD, &handle_key_hook_move},
	(t_handle_key){MOVE_RIGHT, &handle_key_hook_move},
	(t_handle_key){MOVE_BACK, &handle_key_hook_move},
	(t_handle_key){LMOVE_DOWN, &handle_key_hook_move},
	(t_handle_key){RMOVE_DOWN, &handle_key_hook_move},
	(t_handle_key){-1, NULL}
};

#else

static t_handle_key	g_key_handlers[] = {
	(t_handle_key){CAM_PREV, &handle_key_hook_cam},
	(t_handle_key){CAM_NEXT, &handle_key_hook_cam},
	(t_handle_key){MOVE_UP, &handle_key_hook_move},
	(t_handle_key){MOVE_LEFT, &handle_key_hook_move},
	(t_handle_key){MOVE_FORWARD, &handle_key_hook_move},
	(t_handle_key){MOVE_RIGHT, &handle_key_hook_move},
	(t_handle_key){MOVE_BACK, &handle_key_hook_move},
	(t_handle_key){LMOVE_DOWN, &handle_key_hook_move},
	(t_handle_key){RMOVE_DOWN, &handle_key_hook_move},
	(t_handle_key){-1, NULL}
};

#endif

int	handle_key_hook(int keycode, t_scene *scene)
{
	size_t	idx;

	if (keycode == ESC)
		exit_minirt(error_new(NULL, 0), scene);
	idx = 0;
	while (g_key_handlers[idx].func)
	{
		if (g_key_handlers[idx].key == keycode)
		{
			g_key_handlers[idx].func(scene, keycode);
			return (0);
		}
		idx++;
	}
	return (0);
}
