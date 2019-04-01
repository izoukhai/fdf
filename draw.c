/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/08 03:16:22 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/08 03:23:15 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static inline void	set_line(t_point *step, t_point *src, t_point *dst)
{
	(*step).x = (*dst).x - (*src).x;
	(*step).y = (*dst).y - (*src).y;
}

void				draw_line(t_fdf *fdf, t_point src, t_point dst, int color)
{
	t_point			step;
	int				n;
	int				i;
	t_point			pos;

	i = -1;
	set_line(&step, &src, &dst);
	if (ABS(step.x) > ABS(step.y))
	{
		n = ABS(step.x);
		step.y /= ABS(step.x);
		step.x /= ABS(step.x);
	}
	else
	{
		n = ABS(step.y);
		step.x /= ABS(step.y);
		step.y /= ABS(step.y);
	}
	while (++i < n)
	{
		new_point(&pos, src, i, step);
		if ((pos.x >= 0 && pos.x <= W) && (pos.y >= 0 && pos.y <= H))
			img_put_pixel(fdf, pos, color);
	}
}

inline static void	draw_connex(t_fdf *fdf, t_index pos)
{
	if (pos.x < fdf->map->size.x - 1)
	{
		draw_line(fdf, fdf->map->coord[pos.y][pos.x],
				fdf->map->coord[pos.y][pos.x + 1],
					fdf->map->coord[pos.y][pos.x].color);
	}
	if (pos.y < fdf->map->size.y - 1)
	{
		draw_line(fdf, fdf->map->coord[pos.y][pos.x],
				fdf->map->coord[pos.y + 1][pos.x],
					fdf->map->coord[pos.y][pos.x].color);
	}
}

void				draw_map(t_fdf *fdf)
{
	t_index			pos;

	pos.y = -1;
	fdf->type < 0 ? pa_project(fdf) : project(fdf);
	while (++pos.y < fdf->map->size.y)
	{
		pos.x = -1;
		while (++pos.x < fdf->map->size.x)
			draw_connex(fdf, pos);
	}
}
