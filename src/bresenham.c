/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:00:33 by llenotre          #+#    #+#             */
/*   Updated: 2019/02/25 19:01:22 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham_quadrant1(t_mlx_info *info, t_line *line, int dx, int dy)
{
	int e;

	if (dx >= dy)
	{
		dx = (e = dx) * 2;
		dy *= 2;
		while (TRUE)
		{
			mlx_pixel_put(info->ptr, info->win,
				line->p1.x, line->p1.y, 0xffffff);
			if (++line->p1.x == line->p2.x)
				break ;
			if ((e -= dy) < 0)
			{
				++line->p1.y;
				e += dx;
			}
		}
	}
	else
	{
		dy = (e = dy) * 2;
		dx *= 2;
		while (TRUE)
		{
			mlx_pixel_put(info->ptr, info->win,
				line->p1.x, line->p1.y, 0xffffff);
			if (++line->p1.y == line->p2.y)
				break ;
			if ((e -= dx) < 0)
			{
				++line->p1.x;
				e += dy;
			}
		}
	}
}

void	bresenham_quadrant2(t_mlx_info *info, t_line *line, int dx, int dy)
{
	int e;

	if (-dx >= dy)
	{
		dx = (e = dx) * 2;
		dy *= 2;
		while (TRUE)
		{
			mlx_pixel_put(info->ptr, info->win,
				line->p1.x, line->p1.y, 0xffffff);
			if (--line->p1.x == line->p2.x)
				break ;
			if ((e += dy) >= 0)
			{
				++line->p1.y;
				e += dx;
			}
		}
	}
	else
	{
		dy = (e = dy) * 2;
		dx *= 2;
		while (TRUE)
		{
			mlx_pixel_put(info->ptr, info->win,
				line->p1.x, line->p1.y, 0xffffff);
			if (++line->p1.y == line->p2.y)
				break ;
			if ((e += dx) <= 0)
			{
				--line->p1.x;
				e += dy;
			}
		}
	}
}

void	bresenham_quadrant3(t_mlx_info *info, t_line *line, int dx, int dy)
{
	int e;

	if (dx <= dy)
	{
		dx = (e = dx) * 2;
		dy *= 2;
		while (TRUE)
		{
			mlx_pixel_put(info->ptr, info->win,
				line->p1.x, line->p1.y, 0xffffff);
			if (--line->p1.x == line->p2.x)
				break ;
			if ((e -= dy) >= 0)
			{
				--line->p1.y;
				e += dx;
			}
		}
	}
	else
	{
		dy = (e = dy) * 2;
		dx *= 2;
		while (TRUE)
		{
			mlx_pixel_put(info->ptr, info->win,
				line->p1.x, line->p1.y, 0xffffff);
			if (--line->p1.y == line->p2.y)
				break ;
			if ((e -= dx) >= 0)
			{
				--line->p1.x;
				e += dy;
			}
		}
	}
}

void	bresenham_quadrant4(t_mlx_info *info, t_line *line, int dx, int dy)
{
	int e;

	if (dx >= -dy)
	{
		dx = (e = dx) * 2;
		dy *= 2;
		while (TRUE)
		{
			mlx_pixel_put(info->ptr, info->win,
				line->p1.x, line->p1.y, 0xffffff);
			if (++line->p1.x == line->p2.x)
				break ;
			if ((e += dy) < 0)
			{
				--line->p1.y;
				e += dx;
			}
		}
	}
	else
	{
		dy = (e = dy) * 2;
		dx *= 2;
		while (TRUE)
		{
			mlx_pixel_put(info->ptr, info->win,
				line->p1.x, line->p1.y, 0xffffff);
			if (--line->p1.y == line->p2.y)
				break ;
			if ((e += dx) > 0)
			{
				++line->p1.x;
				e += dy;
			}
		}
	}
}
