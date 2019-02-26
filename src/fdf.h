/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:12:45 by llenotre          #+#    #+#             */
/*   Updated: 2019/02/26 16:50:36 by llenotre         ###   ########.fr       */
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

# ifdef __APPLE__
#  define ESC_KEY			65307
#  define SPACE_KEY			49
#  define PLUS_KEY			24
#  define NUM_PLUS_KEY		69
#  define MINUS_KEY			27
#  define NUM_MINUS_KEY		78
#  define ARROW_UP_KEY		125
#  define ARROW_LEFT_KEY	124
#  define ARROW_DOWN_KEY	126
#  define ARROW_RIGHT_KEY	123
#  define R_KEY				15
# else
#  define ESC_KEY			65307
#  define SPACE_KEY			32
#  define PLUS_KEY			61
#  define NUM_PLUS_KEY		65451
#  define MINUS_KEY			45
#  define NUM_MINUS_KEY		65453
#  define ARROW_UP_KEY		65364
#  define ARROW_LEFT_KEY	65363
#  define ARROW_DOWN_KEY	65362
#  define ARROW_RIGHT_KEY	65361
#  define R_KEY				114
# endif

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
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
	const int axis);
void			free_wireframe(const t_wireframe *w);

t_wireframe		*read_wireframe(const char *file);

t_point			isometric_projection(const t_point *p);
t_point			parallel_projection(const t_point *p);

void			draw_line(t_mlx_info *mlx, t_line line);
void			draw_wireframe(t_mlx_info *mlx, const t_wireframe *w);
void			render(t_mlx_info *info);

void			bresenham_quadrant1(t_mlx_info *info, t_line *line,
	int dx, int dy);
void			bresenham_quadrant2(t_mlx_info *info, t_line *line,
	int dx, int dy);
void			bresenham_quadrant3(t_mlx_info *info, t_line *line,
	int dx, int dy);
void			bresenham_quadrant4(t_mlx_info *info, t_line *line,
	int dx, int dy);
void			bresenham_vertical(t_mlx_info *info, t_line *line);
void			bresenham_horizontal(t_mlx_info *info, t_line *line);

int				key_event(int key, void *ptr);
int				close_event(void);

#endif
