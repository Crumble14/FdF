/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:12:45 by llenotre          #+#    #+#             */
/*   Updated: 2019/02/13 18:44:11 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../minilibx/mlx.h"

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	uint16_t	color;
}				t_point;

const t_list	*read_wireframe(const char *file);

void			open_window(void);

void			draw_line(t_point p1, t_point p2);
void			draw_wireframe(const t_list *wireframe);

#endif
