/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:00:33 by llenotre          #+#    #+#             */
/*   Updated: 2019/02/26 16:47:21 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham_vertical(t_mlx_info *info, t_line *line)
{
	int dy;

	if (!(dy = line->p2.y - line->p1.y))
		return ;
	if (dy >= 0)
	{
		while (line->p1.y != line->p2.y)
		{
			mlx_pixel_put(info->ptr, info->win,
				line->p1.x, line->p1.y, 0xffffff);
			++line->p1.y;
		}
	}
	else
	{
		while (line->p1.y != line->p2.y)
		{
			mlx_pixel_put(info->ptr, info->win,
				line->p1.x, line->p1.y, 0xffffff);
			--line->p1.y;
		}
	}
}

void	bresenham_horizontal(t_mlx_info *info, t_line *line)
{
	int dx;

	if (!(dx = line->p2.x - line->p1.x))
		return ;
	if (dx >= 0)
	{
		while (line->p1.x != line->p2.x)
		{
			mlx_pixel_put(info->ptr, info->win,
				line->p1.x, line->p1.y, 0xffffff);
			++line->p1.x;
		}
	}
	else
	{
		while (line->p1.x != line->p2.x)
		{
			mlx_pixel_put(info->ptr, info->win,
				line->p1.x, line->p1.y, 0xffffff);
			--line->p1.x;
		}
	}
}
