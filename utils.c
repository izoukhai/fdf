/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/08 03:17:02 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/08 03:17:03 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void				set_offsets(t_fdf *fdf)
{
	fdf->map->axes.i_off.x = 10;
	fdf->map->axes.i_off.y = 10;
	fdf->map->axes.j_off.x = -10;
	fdf->map->axes.j_off.y = 7;
	fdf->map->axes.k_off.x = 0;
	fdf->map->axes.k_off.y = 1;
}

void				init_cam(t_fdf *fdf)
{
	fdf->cam.zoom = 1;
	fdf->cam.pos.x = (W / 4);
	fdf->cam.pos.y = (H / 4);
}

void				init_axes(t_fdf *fdf)
{
	fdf->map->axes.i.x = fdf->map->axes.i_off.x *
		fdf->cam.zoom;
	fdf->map->axes.i.y = fdf->map->axes.i_off.y *
		fdf->cam.zoom;
	fdf->map->axes.j.x = fdf->map->axes.j_off.x *
		fdf->cam.zoom;
	fdf->map->axes.j.y = fdf->map->axes.j_off.y *
		fdf->cam.zoom;
	fdf->map->axes.k.x = fdf->map->axes.k_off.x *
		fdf->cam.zoom;
	fdf->map->axes.k.y = fdf->map->axes.k_off.y *
		fdf->cam.zoom;
}

void				pa_project(t_fdf *fdf)
{
	t_index			pos;

	pos.y = -1;
	while (++pos.y < fdf->map->size.y)
	{
		pos.x = -1;
		while (++pos.x < fdf->map->size.x)
		{
			fdf->map->coord[pos.y][pos.x].x =
				fdf->map->axes.i.x * pos.x + ((1 / 2) *
					fdf->map->coord[pos.y][pos.x].z * cos(M_PI)) +
						(fdf->map->axes.k.x * -fdf->map->coord[pos.y][pos.x].z)
							+ fdf->cam.pos.x;
			fdf->map->coord[pos.y][pos.x].y =
				fdf->map->axes.i.y * pos.y + ((1 / 2) *
					fdf->map->coord[pos.y][pos.x].z * sin(M_PI)) +
						(fdf->map->axes.k.y * -fdf->map->coord[pos.y][pos.x].z)
							+ fdf->cam.pos.y;
		}
	}
}

void				project(t_fdf *fdf)
{
	t_index			pos;

	pos.y = -1;
	while (++pos.y < fdf->map->size.y)
	{
		pos.x = -1;
		while (++pos.x < fdf->map->size.x)
		{
			fdf->map->coord[pos.y][pos.x].x = fdf->map->axes.i.x *
				pos.x + fdf->map->axes.j.x * pos.y + fdf->map->axes.k.x *
					fdf->map->coord[pos.y][pos.x].z + fdf->cam.pos.x;
			fdf->map->coord[pos.y][pos.x].y = fdf->map->axes.i.y *
				pos.x + fdf->map->axes.j.y * pos.y + fdf->map->axes.k.y *
					(fdf->map->coord[pos.y][pos.x].z * -1) + fdf->cam.pos.y;
		}
	}
}
