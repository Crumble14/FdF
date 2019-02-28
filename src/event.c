/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:28:21 by llenotre          #+#    #+#             */
/*   Updated: 2019/02/28 19:37:43 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline void	reset(t_mlx_info *info)
{
	info->zoom = 1;
	ft_bzero(&info->camera, sizeof(t_point));
}

int					key_event(int key, void *ptr)
{
	t_mlx_info *info;

	info = (t_mlx_info *)ptr;
	if (key == ESC_KEY)
		exit(0);
	else if (key == SPACE_KEY)
		info->proj = (info->proj == isometric_projection
			? parallel_projection : isometric_projection);
	else if ((key == PLUS_KEY || key == NUM_PLUS_KEY) && info->zoom < 64)
		info->zoom *= 2;
	else if ((key == MINUS_KEY || key == NUM_MINUS_KEY) && info->zoom > 1)
		info->zoom /= 2;
	else if (key == ARROW_RIGHT_KEY)
		info->camera.x -= 100;
	else if (key == ARROW_LEFT_KEY)
		info->camera.x += 100;
	else if (key == ARROW_DOWN_KEY)
		info->camera.y -= 100;
	else if (key == ARROW_UP_KEY)
		info->camera.y += 100;
	else if (key == R_KEY)
		reset(info);
	mlx_clear_window(info->ptr, info->win);
	render(info);
	return (0);
}

int					close_event(void)
{
	exit(0);
}
