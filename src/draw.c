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
#include <stdio.h>

static void	set_pixel(t_mlx_info *info, t_point *p)
{
	if(p->x < 0 || p->y < 0 || p->x > WIN_WIDTH || p->y > WIN_HEIGHT)
		return ;
	mlx_pixel_put(info->ptr, info->win, p->x, p->y, 0xffffff);
}

static void bresenham_quadrant1(t_mlx_info *info, t_line *line, int dx, int dy)
{
	int e;

	if (dx >= dy)
	{
		dx = (e = dx) * 2;
		dy *= 2;
		while (TRUE)
		{
			set_pixel(info, &line->p1);
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
			set_pixel(info, &line->p1);
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

static void bresenham_quadrant2(t_mlx_info *info, t_line *line, int dx, int dy)
{
	int e;

	if (-dx >= dy)
	{
		dx = (e = dx) * 2;
		dy *= 2;
		while (TRUE)
		{
			set_pixel(info, &line->p1);
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
			set_pixel(info, &line->p1);
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

static void bresenham_quadrant3(t_mlx_info *info, t_line *line, int dx, int dy)
{
	int e;

	if (dx <= dy)
	{
		dx = (e = dx) * 2;
		dy *= 2;
		while (TRUE)
		{
			set_pixel(info, &line->p1);
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
			set_pixel(info, &line->p1);
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

static void bresenham_quadrant4(t_mlx_info *info, t_line *line, int dx, int dy)
{
	int e;

	if (dx >= -dy)
	{
		dx = (e = dx) * 2;
		dy *= 2;
		while (TRUE)
		{
			set_pixel(info, &line->p1);
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
			set_pixel(info, &line->p1);
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

static void	bresenham_vertical(t_mlx_info *info, t_line *line)
{
	int dy;

	if (!(dy = line->p2.y - line->p1.y))
		return ;
	if (dy >= 0)
	{
		while (line->p1.y != line->p2.y)
		{
			set_pixel(info, &line->p1);
			++line->p1.y;
		}
	}
	else
	{
		while (line->p1.y != line->p2.y)
		{
			set_pixel(info, &line->p1);
			--line->p1.y;
		}
	}
}

static void	bresenham_horizontal(t_mlx_info *info, t_line *line)
{
	int dx;

	if (!(dx = line->p2.x - line->p1.x))
		return ;
	if (dx >= 0)
	{
		while (line->p1.x != line->p2.x)
		{
			set_pixel(info, &line->p1);
			++line->p1.x;
		}
	}
	else
	{
		while (line->p1.x != line->p2.x)
		{
			set_pixel(info, &line->p1);
			--line->p1.x;
		}
	}
}

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
	{
		(dy > 0 ? bresenham_quadrant1
			: bresenham_quadrant4)(info, &line, dx, dy);
	}
	else
	{
		(dy > 0 ? bresenham_quadrant2
			: bresenham_quadrant3)(info, &line, dx, dy);
	}
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
	mlx_string_put(info->ptr, info->win, 0, 10, 0xffffff,
		"Arrows: Move around");
	mlx_string_put(info->ptr, info->win, 0, 20, 0xffffff,
		"Space: Switch projection");
	mlx_string_put(info->ptr, info->win, 0, 30, 0xffffff,
		"R: Reset camera");
	mlx_string_put(info->ptr, info->win, 0, 40, 0xffffff,
		"+/-: Zoom");
	draw_wireframe(info, info->wireframe);
}
