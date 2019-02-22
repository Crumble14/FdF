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
# include <math.h>
# include <stdint.h>

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# ifdef __linux__
#  include "../minilibx_linux/mlx.h"
# else
#  include "../minilibx_macos/mlx.h"
# endif

# define WIN_WIDTH	1024
# define WIN_HEIGHT	768

# define POINT_GAP		30
# define POINT_GAP_Z	3

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	uint32_t	color;
}				t_point;

typedef struct	s_line
{
	t_point p1;
	t_point p2;
}				t_line;

typedef struct	s_wireframe
{
	t_point				point;

	struct s_wireframe	*x_next;
	struct s_wireframe	*y_next;
}				t_wireframe;

typedef struct	s_mlx_info
{
	void		*ptr;
	void		*win;

	t_wireframe	*wireframe;

	t_point		(*proj)(const t_point *p);

	t_point		camera;
	float		zoom;
}				t_mlx_info;

t_wireframe		*create_wireframe(t_point *p);
void			join_wireframes(t_wireframe **w1, t_wireframe *w2,
	int axis);
void			set_wireframe_color(t_wireframe *w);
void			free_wireframe(const t_wireframe *w);

t_wireframe		*read_wireframe(const char *file);

t_point			isometric_projection(const t_point *p);
t_point			parallel_projection(const t_point *p);

void			draw_line(t_mlx_info *mlx, t_line line);
void			draw_wireframe(t_mlx_info *mlx, const t_wireframe *w);
void			render(t_mlx_info *info);

int				key_event(int key, void *ptr);

#endif
