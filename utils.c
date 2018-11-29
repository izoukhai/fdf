#include "fdf.h"

int				get_real_size(char *file)
{
	int			fd;
	char		*line;
	int			res;

	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	res = ft_strlen(line);
	while (*line++)
		if (*line == ' ')
			res--;
	close(fd);
	return (res);
}

t_point			create_point(int x, int y)
{
	t_point		res;

	res.x = x;
	res.y = y;
	return (res);
}

t_line			create_line(t_point src, t_point dst)
{
	t_line		res;

	res.src = src;
	res.dst = dst;
	return (res);
}

t_line			to_point(t_line line)
{
	t_line new;

}