/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:46:00 by llenotre          #+#    #+#             */
/*   Updated: 2019/02/26 16:36:27 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_line(t_mlx_info *info, t_line line)
{
	int dx;
	int dy;

	line.p1.x = (line.p1.x * (float)(info->zoom / 10)) - info->camera.x;
	line.p1.y = (line.p1.y * (float)(info->zoom / 10)) - info->camera.y;
	line.p2.x = (line.p2.x * (float)(info->zoom / 10)) - info->camera.x;
	line.p2.y = (line.p2.y * (float)(info->zoom / 10)) - info->camera.y;
	if (!info)
		return ;
	if (!(dx = line.p2.x - line.p1.x))
	{
		bresenham_vertical(info, &line);
		return ;
	}
	if (!(dy = line.p2.y - line.p1.y))
	{
		bresenham_horizontal(info, &line);
		return ;
	}
	if (dx > 0)
		(dy > 0 ? bresenham_quadrant1
			: bresenham_quadrant4)(info, &line, dx, dy);
	else
		(dy > 0 ? bresenham_quadrant2
			: bresenham_quadrant3)(info, &line, dx, dy);
}

void		draw_wireframe(t_mlx_info *info, const t_wireframe *w)
{
	const t_wireframe	*n;
	t_line				line;

	if (!info || !info->proj || !w)
		return ;
	while (w)
	{
		n = w;
		while (n)
		{
			line.p1 = info->proj(&n->point);
			if (n->x_next)
			{
				line.p2 = info->proj(&n->x_next->point);
				draw_line(info, line);
			}
			if (n->y_next)
			{
				line.p2 = info->proj(&n->y_next->point);
				draw_line(info, line);
			}
			n = n->x_next;
		}
		w = w->y_next;
	}
}

void		render(t_mlx_info *info)
{
	mlx_string_put(info->ptr, info->win, 0, 0, 0xffffff,
		"Arrows: Move around");
	mlx_string_put(info->ptr, info->win, 0, 10, 0xffffff,
		"Space: Switch projection");
	mlx_string_put(info->ptr, info->win, 0, 20, 0xffffff,
		"R: Reset camera");
	mlx_string_put(info->ptr, info->win, 0, 30, 0xffffff,
		"+/-: Zoom");
	draw_wireframe(info, info->wireframe);
}
