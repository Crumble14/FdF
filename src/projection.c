#include "fdf.h"

static inline double	to_rad(double deg)
{
	return (deg * M_PI / 180.0);
}

t_point					isometric_projection(const t_point *p)
{
	t_point sp;

	sp.x = p->x * cos(to_rad(40)) + p->y * cos(to_rad(30 + 120))
		+ p->z * cos(to_rad(30 - 120));
	sp.y = p->x * sin(to_rad(40)) + p->y * sin(to_rad(30 + 120))
		+ p->z * sin(to_rad(30 - 120));
	sp.z = 0;
	return (sp);
}

t_point					parallel_projection(const t_point *p)
{
	t_point sp;

	// TODO
	sp = *p;
	return (sp);
}
