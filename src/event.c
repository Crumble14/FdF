#include "fdf.h"

int key_event(int key, void *ptr)
{
	t_mlx_info *info;

	info = (t_mlx_info *)ptr;
	if (key == 65307)
		exit(0);
	else if (key == 32)
		info->proj = (info->proj == isometric_projection
			? parallel_projection : isometric_projection);
	else if (key == 61 || key == 65451)
		info->zoom *= 2;
	else if (key == 45 || key == 65453)
		info->zoom /= 2;
	else if (key == 65361)
		info->camera.x -= 100;
	else if (key == 65363)
		info->camera.x += 100;
	else if (key == 65362)
		info->camera.y -= 100;
	else if (key == 65364)
		info->camera.y += 100;
	else if (key == 114)
	{
		info->zoom = 1;
		ft_bzero(&info->camera, sizeof(t_point));
	}
	mlx_clear_window(info->ptr, info->win);
	draw_wireframe(info, info->wireframe);
	return (0);
}
