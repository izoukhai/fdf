/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 22:16:04 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 22:16:05 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static inline int		h_zoom(int key, t_fdf *fdf)
{
	if (key == 4)
	{
		fdf->cam.zoom *= 1.1;
		return (1);
	}
	if (key == 5 && fdf->cam.zoom > 0.2f)
	{
		fdf->cam.zoom *= 0.9;
		return (1);
	}
	return (0);
}

static inline void		h_move(int key, t_fdf *fdf)
{
	if (key == RIGHT)
		fdf->cam.pos.x += 20;
	if (key == LEFT)
		fdf->cam.pos.x -= 20;
	if (key == UP)
		fdf->cam.pos.y -= 20;
	if (key == DOWN)
		fdf->cam.pos.y += 20;
	if (key == 91)
		fdf->map->axes.k_off.y += 0.3;
	if (key == 84)
		fdf->map->axes.k_off.y -= 0.3;
	if (key == 15)
	{
		fdf->cam.pos.x = W / 4;
		fdf->cam.pos.y = H / 4;
	}
}

static inline void		h_color(int key, t_fdf *fdf)
{
	t_index				pos;

	pos.y = -1;
	while (++pos.y < fdf->map->size.y)
	{
		pos.x = -1;
		while (++pos.x < fdf->map->size.x)
		{
			if (key == IN)
				fdf->map->coord[pos.y][pos.x].color += RGB(10, 10, 10);
			if (key == OUT)
				fdf->map->coord[pos.y][pos.x].color -= RGB(10, 10, 10);
		}
	}
}

int						handle_key(int key, t_fdf *fdf)
{
	if (key == 53)
		destroy(fdf);
	if (key == 35)
		fdf->type *= -1;
	h_zoom(key, fdf);
	h_move(key, fdf);
	h_color(key, fdf);
	h_expose(fdf);
	return (0);
}

int						handle_mouse(int key, int x, int y, t_fdf *fdf)
{
	if (x && y)
		;
	h_zoom(key, fdf);
	h_expose(fdf);
	return (0);
}
