#ifndef FDF_H
# define FDF_H
# include "minilib/mlx.h"
# include "libft/includes/get_next_line.h"
# include <math.h>

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_map
{
	int 		**tab;
	t_point 	size;
}				t_map;

typedef struct	s_line
{
	t_point		src;
	t_point		dst;
}				t_line;

typedef struct	s_vec
{
	t_point		A;
	t_point		B;
}				t_vec;

typedef struct	s_mlx
{
	t_map		*map;
	void		*mlx;
	void		*win;
	void		*img;
}				t_mlx;

// Map
t_map			*create_map(char *file, t_point size);
t_point			get_map_size(char *file);
void			get_map(t_map **map, char *file);

// Utils
int				get_real_size(char *file);
t_point			create_point(int x, int y);
t_line			create_line(t_point src, t_point dst);

// Draw
void			draw_line(t_line line, void *mlx, void *win, int color);
void			draw_map(t_map *map, void *mlx, void *win, int color);

#endif