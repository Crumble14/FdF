#include "fdf.h"

static inline double	to_rad(double deg)
{
	return (deg * M_PI / 180.0);
}

static t_point rotate_x(const t_point *point, const float angle)
{
	t_point p;

	p.x = point->x;
	p.y = point->y * cos(angle) - point->z * sin(angle);
	p.z = point->y * sin(angle) + point->z * cos(angle);
	return (p);
}

static t_point rotate_y(const t_point *point, const float angle)
{
	t_point p;

	p.x = point->x * cos(angle) + point->z * sin(angle);
	p.y = point->y;
	p.z = point->x * -sin(angle) + point->z * cos(angle);
	return (p);
}

static t_point rotate_z(const t_point *point, const float angle)
{
	t_point p;

	p.x = point->x * cos(angle) + point->y * -sin(angle);
	p.y = point->x * sin(angle) + point->y * cos(angle);
	p.z = point->z;
	return (p);
}

t_point					isometric_projection(const t_point *p)
{
	t_point sp;

	sp = *p;
	sp = rotate_z(&sp, to_rad(45));
	sp = rotate_x(&sp, to_rad(35.264));
	sp.z = 0;
	return (sp);
}

t_point					parallel_projection(const t_point *p)
{
	t_point sp;

	sp = *p;
	sp = rotate_x(&sp, to_rad(45));
	sp = rotate_y(&sp, to_rad(-20));
	//sp = rotate_z(&sp, to_rad(45));
	sp.z = 0;
	return (sp);
}
