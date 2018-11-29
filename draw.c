#include "fdf.h"

/*void			draw_line(t_line line, void *mlx, void *win, int color)
{
	t_point		step;
    int			n;
	int			i;

	i = -1;
	step.x = line.dst.x - line.src.x;
	step.y = line.dst.y - line.src.y;
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
		mlx_pixel_put(mlx, win, line.src.x + i * step.x, line.src.x + i  * step.y, color);
}*/

void			draw_line(t_line line, void *mlx, void *win, int color)
{
	t_line		res;
	int			err;
	int			e;

	res.dst.x = ABS(line.dst.x - line.src.x);
	res.src.x = line.src.x < line.dst.x ? 1 : -1;
	res.dst.y = ABS(line.dst.y - line.src.y);
	res.src.y = line.src.y < line.dst.y ? 1 : -1;
	err = res.dst.x + res.dst.y;
	while (1)
	{
		mlx_pixel_put(mlx, win, line.src.x, line.src.y, color);
		if (line.src.x == line.dst.x && line.src.y == line.dst.y)
			break;
		e = 2 * err;
		if (e >= res.dst.y)
		{
			err += res.dst.y;
			line.src.x += res.src.x;
		}
		if (e <= res.dst.x)
		{
			err += res.dst.x;
			line.src.y += res.src.y;
		}
	}
}

void			draw_map(t_map *map, void *mlx, void *win, int color)
{
	t_point		pos;
	t_point		save;

	pos = create_point(1, 1);
	save = pos;
	while (++pos.y < map->size.y + 100)
	{
		pos.x = 1;
		while (++pos.x < map->size.x + 100)
		{
			draw_line(create_line(pos, create_point(100, 0)), mlx, win, color);
			draw_line(create_line(pos, create_point(0, 100)), mlx, win, color);
			draw_line(create_line(create_point(0, 100), create_point(100, 100)), mlx, win, color);
			draw_line(create_line(create_point(100, 100), create_point(100, 0)), mlx, win, color);
			pos.x += 100;
		}
		pos.y += 100;
	}
	ft_putstr("hej\n");
}