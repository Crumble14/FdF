/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:46:00 by llenotre          #+#    #+#             */
/*   Updated: 2019/02/14 15:38:17 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void bresenham_quadrant1(t_mlx_info *info, t_point *p1, t_point *p2)
{
	if (dx >= dy)
	{
		dx = (e = dx) * 2;
		dy *= 2;
		while (TRUE)
		{
			mlx_pixel_put(info->ptr, info->win, p1.x, p1.y, 0xffffff);
			if (++p1.x == p2.x)
				break ;
			if ((e -= dy) < 0)
			{
				++p1.y;
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
			mlx_pixel_put(info->ptr, info->win, p1.x, p1.y, 0xffffff);
			if (++p1.y == p2.y)
				break ;
			if ((e -= dx) < 0)
			{
				++p1.x;
				e += dy;
			}
		}
	}
}

static void bresenham_quadrant2(t_mlx_info *info, t_point *p1, t_point *p2)
{
	if (-dx >= dy)
	{
		dx = (e = dx) * 2;
		dy *= 2;
		while (TRUE)
		{
			mlx_pixel_put(info->ptr, info->win, p1.x, p1.y, 0xffffff);
			if (--p1.x == p2.x)
				break ;
			if ((e += dy) >= 0)
			{
				++p1.y;
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
			mlx_pixel_put(info->ptr, info->win, p1.x, p1.y, 0xffffff);
			if (++p1.y == p2.y)
				break ;
			if ((e -= dx) <= 0)
			{
				--p1.x;
				e += dy;
			}
		}
	}
}

static void bresenham_quadrant3(t_mlx_info *info, t_point *p1, t_point *p2)
{
	if (dx <= dy)
	{
		dx = (e = dx) * 2;
		dy *= 2;
		while (TRUE)
		{
			mlx_pixel_put(info->ptr, info->win, p1.x, p1.y, 0xffffff);
			if (--p1.x == p2.x)
				break ;
			if ((e -= dy) >= 0)
			{
				--p1.y;
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
			mlx_pixel_put(info->ptr, info->win, p1.x, p1.y, 0xffffff);
			if (--p1.y == p2.y)
				break ;
			if ((e -= dx) >= 0)
			{
				--p1.x;
				e += dy;
			}
		}
	}
}

static void bresenham_quadrant4(t_mlx_info *info, t_point *p1, t_point *p2)
{
	if (dx >= -dy)
	{
		dx = (e = dx) * 2;
		dy *= 2;
		while (TRUE)
		{
			mlx_pixel_put(info->ptr, info->win, p1.x, p1.y, 0xffffff);
			if (++p1.x == p2.x)
				break ;
			if ((e += dy) < 0)
			{
				--p1.y;
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
			mlx_pixel_put(info->ptr, info->win, p1.x, p1.y, 0xffffff);
			if (--p1.y == p2.y)
				break ;
			if ((e += dx) > 0)
			{
				++p1.x;
				e += dy;
			}
		}
	}
}

static void	bresenham_horizontal(t_mlx_info *info, t_point *p1, t_point *p2)
{
	int dx;

	if (!(dx = p2->x - p1->x))
		return ;
	if (dx >= 0)
	{
		while (p1->x != p2->x)
			mlx_pixel_put(info->ptr, info->win, p1->x++, p1->y, 0xffffff);
	}
	else
	{
		while (p1->x != p2->x)
			mlx_pixel_put(info->ptr, info->win, p1->x--, p1->y, 0xffffff);
	}
}

static void	bresenham_vertical(t_mlx_info *info, t_point *p1, t_point *p2)
{
	int dy;

	if (!(dy = p2->y - p1->y))
		return ;
	if (dy >= 0)
	{
		while (p1->y != p2->y)
			mlx_pixel_put(info->ptr, info->win, p1->x, p1->y++, 0xffffff);
	}
	else
	{
		while (p1->y != p2->y)
			mlx_pixel_put(info->ptr, info->win, p1->x, p1->y--, 0xffffff);
	}
}

void	draw_line(t_mlx_info *info, t_point p1, t_point p2)
{
	int dx;
	int dy;
	int e;

	if (!(dx = p2.x - p1.x))
		bresenham_vertical(info, &p1, &p2);
	if (dx > 0)
	{
		if ((dy = p2.y - p1.y))
		{
			if (dy > 0)
				bresenham_quadrant1(info, p1, p2);
			else
				bresenham_quadrant4(info, p1, p2);
		}
		else
			bresenham_horizontal(info, &p1, &p2);
	}
	else
	{
		if ((dy = p2.y - p1.y))
		{
			if (dy > 0)
				bresenham_quadrant2(info, p1, p2);
			else
				bresenham_quadrant3(info, p1, p2);
		}
		else
			bresenham_horizontal(info, &p1, &p2);
	}
}

void			draw_wireframe(t_mlx_info *info, const t_list *wireframe)
{
	(void)info;
	(void)wireframe;
	// TODO
}
