/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:12:45 by llenotre          #+#    #+#             */
/*   Updated: 2019/02/14 14:22:51 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../minilibx/mlx.h"

# define WIN_WIDTH	1024
# define WIN_HEIGHT	768

typedef struct	s_mlx_info
{
	void *ptr;
	void *win;
}				t_mlx_info;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	uint16_t	color;
}				t_point;

const t_list	*read_wireframe(const char *file);

void			draw_line(t_mlx_info *mlx, t_point p1, t_point p2);
void			draw_wireframe(t_mlx_info *mlx, const t_list *wireframe);

#endif
