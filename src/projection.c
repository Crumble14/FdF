#include "fdf.h"

t_point	isometric_projection(const t_point *p)
{
	t_point screen_point;

	screen_point.x = (double)p->x - 0.013707355 * p->z;
	screen_point.y = (double)p->y + 0.010645681 * p->z;
	screen_point.z = 0;
	return (screen_point);
}
