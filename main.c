/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/08 03:16:36 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/08 03:39:15 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int					check_error(int ac, char *file)
{
	int				fd;
	char			buf[1];

	if (ac != 2)
	{
		ft_putstr("usage: ./fdf [valid_map]\n");
		return (0);
	}
	if ((fd = open(file, O_RDONLY)) < 0)
	{
		ft_putstr("invalid file\n");
		return (0);
	}
	if ((read(fd, buf, 0)) < 0)
	{
		ft_putstr("invalid file\n");
		return (0);
	}
	close(fd);
	return (1);
}

int					h_expose(t_fdf *fdf)
{
	init_axes(fdf);
	ft_bzero(fdf->img.image, W * H * 4);
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.ptr, 0, 0);
	return (0);
}

int					main(int ac, char **av)
{
	t_fdf			fdf;

	(void)fdf;
	if (!check_error(ac, av[1]))
		return (0);
	if (!(fdf.mlx = mlx_init()))
		return (0);
	if (!(fdf.win = mlx_new_window(fdf.mlx, W, H, "izoukhai le bg dla street")))
		return (0);
	init_fdf(&fdf, av[1]);
	render(&fdf);
	mlx_hook(fdf.win, 2, (1L << 0), handle_key, &fdf);
	mlx_mouse_hook(fdf.win, handle_mouse, &fdf);
	mlx_expose_hook(fdf.win, h_expose, &fdf);
	mlx_loop(fdf.mlx);
}
