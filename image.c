/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   image.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 21:26:03 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/13 00:13:09 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void				img_put_pixel(t_fdf *fdf, t_point pos, int color)
{
	if ((pos.x > 0 && pos.x < W) && (pos.y > 0 && pos.y < H))
		fdf->img.image[((int)pos.y * W + (int)pos.x)] = color;
}
