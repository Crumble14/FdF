/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:50:20 by llenotre          #+#    #+#             */
/*   Updated: 2019/02/13 19:04:26 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	open_window(void)
{
	void *ptr;
	void *win;

	if (!(ptr = mlx_init()))
		return ; // TODO Error
	if (!(win = mlx_new_window(ptr, WIN_WIDTH, WIN_HEIGHT, "FdF")))
		return ; // TODO Error
	(void) win; // TODO
}
