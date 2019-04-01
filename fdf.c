/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/08 03:16:15 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/08 03:16:18 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		init_fdf(t_fdf *fdf, char *file)
{
	fdf->type = 1;
	fdf->file = file;
	fdf->max_z = 0;
	fdf->min_z = 0;
	fdf->img.ptr = mlx_new_image(fdf->mlx, W, H);
	fdf->img.image = (int*)mlx_get_data_addr(fdf->img.ptr, &fdf->img.bpp,
		&fdf->img.szl, &fdf->img.endian);
	init_map(fdf, fdf->file);
}

void		init_map(t_fdf *fdf, char *file)
{
	if (file)
		;
	fdf->map = (t_map*)malloc(sizeof(t_map));
	fdf->map->size = get_map_size(fdf);
	init_cam(fdf);
	set_offsets(fdf);
	init_axes(fdf);
	init_coord(fdf);
	get_z(fdf);
	get_color(fdf);
}

void		destroy(t_fdf *fdf)
{
	t_index	pos;

	pos.y = -1;
	while (++pos.y < fdf->map->size.y)
	{
		pos.x = 1;
		free(fdf->map->coord[pos.y]);
	}
	free(fdf->map->coord);
	free(fdf->map);
	mlx_destroy_image(fdf->mlx, fdf->img.ptr);
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
}

void		render(t_fdf *fdf)
{
	init_axes(fdf);
	ft_bzero(fdf->img.image, W * H * 4);
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.ptr, 0, 0);
}

void		new_point(t_point *pos, t_point src, int i, t_point step)
{
	(*pos).x = src.x + i * step.x;
	(*pos).y = src.y + i * step.y;
}
