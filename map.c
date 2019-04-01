/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/08 03:16:46 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/08 03:16:47 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_index				get_map_size(t_fdf *fdf)
{
	t_index			res;
	t_index			pos;
	char			*line;
	char			**tmp;

	res.y = 0;
	fdf->fd = open(fdf->file, O_RDONLY);
	while ((get_next_line(fdf->fd, &line)) == 1)
	{
		pos.x = -1;
		tmp = ft_strsplit(line, ' ');
		if (*tmp == NULL)
			break ;
		res.x = 0;
		while (tmp[++pos.x])
		{
			res.x++;
			free(tmp[pos.x]);
		}
		res.y++;
		free(tmp);
		free(line);
	}
	close(fdf->fd);
	return (res);
}

void				init_coord(t_fdf *fdf)
{
	t_index			pos;

	pos.y = -1;
	fdf->map->coord = (t_point**)malloc(sizeof(t_point*) * fdf->map->size.y);
	while (++pos.y < fdf->map->size.y)
	{
		pos.x = -1;
		fdf->map->coord[pos.y] = (t_point*)malloc(sizeof(t_point) *
			fdf->map->size.x);
		while (++pos.x < fdf->map->size.x)
			fdf->map->coord[pos.y][pos.x].color = RGB(134, 59, 134);
	}
}

void				get_z(t_fdf *fdf)
{
	t_index			pos;
	char			*line;
	char			**tmp;

	pos.y = -1;
	fdf->fd = open(fdf->file, O_RDONLY);
	while ((get_next_line(fdf->fd, &line)) == 1 && ++pos.y < fdf->map->size.y)
	{
		pos.x = -1;
		tmp = ft_strsplit(line, ' ');
		while (tmp[++pos.x])
		{
			fdf->map->coord[pos.y][pos.x].z = ft_atoi(tmp[pos.x]);
			fdf->map->coord[pos.y][pos.x].z > fdf->max_z ? fdf->max_z =
				fdf->map->coord[pos.y][pos.x].z : 0;
			if (fdf->map->coord[pos.y][pos.x].z < 0)
				fdf->map->coord[pos.y][pos.x].z < fdf->min_z ? fdf->min_z =
					fdf->map->coord[pos.y][pos.x].z : 0;
			free(tmp[pos.x]);
		}
		free(tmp);
		free(line);
	}
	close(fdf->fd);
}

void				get_color(t_fdf *fdf)
{
	t_index			pos;
	int				z;

	pos.y = -1;
	while (++pos.y < fdf->map->size.y)
	{
		pos.x = -1;
		while (++pos.x < fdf->map->size.x)
		{
			z = fdf->map->coord[pos.y][pos.x].z;
			z == 0 ? z++ : 0;
			fdf->max_z == 0 ? fdf->max_z++ : 0;
			fdf->min_z == 0 ? fdf->min_z-- : 0;
			if (z < 0)
				fdf->map->coord[pos.y][pos.x].color =
					RGB(0, 199 - (154 * z / fdf->min_z), 230 -
					(154 * z / fdf->min_z));
			else
				fdf->map->coord[pos.y][pos.x].color =
					RGB((254 * z / fdf->max_z), 177 - (99 * z / fdf->max_z),
					(99 * z / fdf->max_z));
		}
	}
}
