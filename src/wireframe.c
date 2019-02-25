#include "fdf.h"

t_wireframe	*create_wireframe(t_point *p)
{
	t_wireframe *w;

	if (!p)
		return (NULL);
	if (!(w = (t_wireframe *)malloc(sizeof(t_wireframe))))
		return (NULL);
	w->point = *p;
	w->x_next = NULL;
	w->y_next = NULL;
	return (w);
}

void		join_wireframes(t_wireframe **w1, t_wireframe *w2, const int axis)
{
	t_wireframe *w;

	if (!w1 || !w2)
		return ;
	if (!(*w1))
		*w1 = w2;
	else if (axis == 0)
	{
		w = *w1;
		while (w->x_next)
			w = w->x_next;
		w->x_next = w2;
	}
	else if (axis == 1)
	{
		w = *w1;
		while (w->y_next)
			w = w->y_next;
		while (w && w2)
		{
			w->y_next = w2;
			w = w->x_next;
			w2 = w2->x_next;
		}
	}
}

void		free_wireframe(const t_wireframe *w)
{
	const t_wireframe *n;
	const t_wireframe *o;

	while (w)
	{
		n = w->x_next;
		while (n)
		{
			o = n;
			free((void *)n);
			n = o->x_next;
		}
		n = w->y_next;
		free((void *)w);
		w = n;
	}
}
