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

# define POINT_GAP	30

# define ISOMETRIC_ALPHA	0.60996413
# define ISOMETRIC_BETA		0.78539816

typedef enum	e_proj_tyoe
{
	ISOMETRIC = 0
}				t_proj_type;

typedef struct	s_mlx_info
{
	void		*ptr;
	void		*win;

	t_proj_type	proj_type;
}				t_mlx_info;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	uint16_t	color;
}				t_point;

typedef struct	s_line
{
	t_point p1;
	t_point p2;
}				t_line;

typedef struct	s_wireframe
{
	t_point point;

	struct s_wireframe *x_next;
	struct s_wireframe *y_next;
}				t_wireframe;

t_wireframe			*create_wireframe(t_point *p);
void				join_wireframes(t_wireframe **w1, t_wireframe *w2,
	int axis);
void				free_wireframe(const t_wireframe *w);

const t_wireframe	*read_wireframe(const char *file);

void				draw_line(t_mlx_info *mlx, t_line line);
void				draw_wireframe(t_mlx_info *mlx, const t_wireframe *w);

#endif
