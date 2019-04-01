/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/08 03:16:11 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/08 08:07:07 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilib/mlx.h"
# include "libft/includes/get_next_line.h"
# include "math.h"
# define W 2560
# define H 1440
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define IN 69
# define OUT 78
# define RGB(r,g,b) (r) * 65536 + (g) * 256 + (b)

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	int				color;
}					t_point;

typedef struct		s_index
{
	int				x;
	int				y;
}					t_index;

typedef struct		s_vec
{
	t_point			i;
	t_point			j;
	t_point			k;
	t_point			i_off;
	t_point			j_off;
	t_point			k_off;
}					t_vec;

typedef struct		s_cam
{
	t_point			pos;
	float			zoom;
}					t_cam;

typedef struct		s_map
{
	t_point			**coord;
	t_index			size;
	t_vec			axes;
}					t_map;

typedef struct		s_img
{
	void			*ptr;
	int				*image;
	int				szl;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_map			*map;
	t_cam			cam;
	int				fd;
	char			*file;
	int				type;
	int				max_z;
	int				min_z;
}					t_fdf;

int					check_error(int ac, char *file);
void				init_fdf(t_fdf *fdf, char *file);
void				init_map(t_fdf *fdf, char *file);
void				init_coord(t_fdf *fdf);
void				init_cam(t_fdf *fdf);
void				init_axes(t_fdf *fdf);
void				render(t_fdf *fdf);
void				destroy(t_fdf *fdf);

t_index				get_map_size(t_fdf *fdf);
void				get_z(t_fdf *fdf);
void				set_offsets(t_fdf *fdf);

void				project(t_fdf *fdf);
void				pa_project(t_fdf *fdf);
void				draw_map(t_fdf *fdf);
void				draw_line(t_fdf *fdf, t_point src, t_point dst, int color);

int					handle_key(int key, t_fdf *fdf);
int					handle_mouse(int key, int x, int y, t_fdf *fdf);
int					h_expose(t_fdf *fdf);
void				get_color(t_fdf *fdf);

void				new_point(t_point *pos, t_point src, int i, t_point step);
void				clear_image(t_fdf *fdf);
void				img_put_pixel(t_fdf *fdf, t_point pos, int color);
void				img_put_line(t_fdf *fdf, t_point src, t_point dst,
					int color);

#endif
