/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 22:23:52 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 22:23:53 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

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

int main(int ac, char **av)
{
    void *mlx;
	void *window;
    if (!(mlx = mlx_init()))
        return (0);
	t_point size = get_map_size(av[1]);
    if (!(window = mlx_new_window(mlx, 1280, 720, "suce")))
        return (0);
	t_map *map = create_map(av[1], get_map_size(av[1]));
	ft_putstr("\n\n\n");
	print_map(map);
	//draw_map(map, mlx, window, 0xFFFFFF);
	draw_line(create_line(create_point(0, 0), create_point(100, 84)), mlx, window, 0xFFFFFF);
    mlx_loop(mlx);
}
