/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:15:38 by llenotre          #+#    #+#             */
/*   Updated: 2019/02/25 18:21:03 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static t_mlx_info	*open_window(void)
{
	t_mlx_info *info;

	if (!(info = (t_mlx_info *)malloc(sizeof(t_mlx_info))))
		return (NULL);
	ft_bzero(info, sizeof(t_mlx_info));
	if (!(info->ptr = mlx_init()))
		return (NULL);
	if (!(info->win = mlx_new_window(info->ptr, WIN_WIDTH, WIN_HEIGHT, "FdF")))
		return (NULL);
	info->proj = isometric_projection;
	info->zoom = 1;
	return (info);
}

static void			close_window(t_mlx_info *info)
{
	mlx_destroy_window(info->ptr, info->win);
	free_wireframe(info->wireframe);
	free((void *)info);
}

int					main(int argc, char **argv)
{
	t_wireframe	*wireframe;
	t_mlx_info	*info;

	--argc;
	++argv;
	if (argc <= 0 || !(wireframe = read_wireframe(*argv))
		|| !(info = open_window()))
		return (-1);
	info->wireframe = wireframe;
	mlx_key_hook(info->win, key_event, info);
	mlx_clear_window(info->ptr, info->win);
	render(info);
	mlx_loop(info->ptr);
	close_window(info);
	return (0);
}
