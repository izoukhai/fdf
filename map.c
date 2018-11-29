#include "fdf.h"

static void print_map(t_map *map)
{
	int i = -1, j = -1;
	while (++i < map->size.y)
	{
		j = -1;
		while (++j < map->size.x)
		{
			ft_putnbr(map->tab[i][j]);
			if (map->tab[i][j] == 10)
				ft_putchar(' ');
			else
				ft_putstr("  ");
		}
		ft_putstr("\n");
	}
}

t_map			*create_map(char *file, t_point size)
{
	t_map		*map;
	int			i;
	int			j;

	i = -1;
	map = (t_map*)malloc(sizeof(t_map));
	map->size = size;
	map->tab = (int**)malloc(sizeof(int*) * map->size.y);
	while (++i < map->size.y)
	{
		j = -1;
		map->tab[i] = (int*)malloc(sizeof(int) * map->size.x);
		while (++j < map->size.x)
			map->tab[i][j] = 0;
	}
	print_map(map);
	get_map(&map, file);
	return (map);
}

t_point			get_map_size(char *file)
{
	int			fd;
	char		*line;
	t_point		res;

	fd = open(file, O_RDONLY);
	res.y = 0;
	res.x = get_real_size(file);
	while ((get_next_line(fd, &line)))
		res.y++;
	close(fd);
	return (res);
}

void			get_map(t_map **map, char *file)
{
	int			i;
	int			j;
	int			fd;
	char		*line;
	char		**tmp;

	fd = open(file, O_RDONLY);
	j = 0;
	while ((get_next_line(fd, &line)) == 1)
	{
		i = -1;
		tmp = ft_strsplit(line, ' ');
		while (tmp[++i])
		{
			(*map)->tab[j][i] = ft_atoi(tmp[i]);
		}
		free(tmp);
		j++;
	}
	close(fd);
}