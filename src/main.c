/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:15:38 by llenotre          #+#    #+#             */
/*   Updated: 2019/02/13 18:41:05 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	del(void *content, size_t content_size)
{
	free((void *)content);
	(void)content_size;
}

int		main(int argc, char **argv)
{
	const t_list *wireframe;

	--argc;
	++argv;
	if (argc <= 0)
		return (-1); // TODO Error message
	wireframe = read_wireframe(*argv);
	open_window();
	draw_wireframe(wireframe);
	ft_lstdel((t_list **)&wireframe, del);
	return (0);
}
