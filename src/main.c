/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:15:38 by llenotre          #+#    #+#             */
/*   Updated: 2019/02/14 15:13:25 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static t_mlx_info	*open_window(void)
{
	t_mlx_info *info;

	if (!(info = (t_mlx_info *)malloc(sizeof(t_mlx_info))))
		return (NULL);
	if (!(info->ptr = mlx_init()))
		return (NULL);
	if (!(info->win = mlx_new_window(info->ptr, WIN_WIDTH, WIN_HEIGHT, "FdF")))
		return (NULL);
	// TODO
	return (info);
}

static void			close_window(t_mlx_info *info)
{
	mlx_destroy_window(info->ptr, info->win);
	free((void *)info);
}

static void			del(void *content, size_t content_size)
{
	free((void *)content);
	(void)content_size;
}

int					main(int argc, char **argv)
{
	const t_list	*wireframe;
	t_mlx_info		*info;

	--argc;
	++argv;
	if (argc <= 0)
		return (-1); // TODO Error message
	wireframe = read_wireframe(*argv);
	if (!(info = open_window()))
		return (-1); // TODO Error message
	while (TRUE)
	{
		//mlx_clear_window(info->ptr, info->win);
		// TODO Handle events
		// TODO draw_wireframe(info, wireframe);
		t_point test1;
		test1.x = 50;
		test1.y = 50;

		t_point test2;
		test2.x = 50;
		test2.y = 60;

		draw_line(info, test1, test2);
	}
	close_window(info);
	ft_lstdel((t_list **)&wireframe, del);
	return (0);
}