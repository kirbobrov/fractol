/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:42:51 by kbobrov           #+#    #+#             */
/*   Updated: 2017/04/10 14:42:53 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_imageinit(t_fract *f)
{
	f->img = mlx_new_image(f->mlx, SIZE_X, SIZE_Y);
	f->bpp = 0;
	f->endl = 0;
	f->sizel = 0;
	f->buf = mlx_get_data_addr(f->img, &f->bpp, &f->sizel, &f->endl);
}

void	ft_imageput(t_fract *f)
{
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_destroy_image(f->mlx, f->img);
}

void	ft_img_color(t_fract *w)
{
	int pix;

	if (w->f->y >= 0 && w->f->x >= 0 && w->f->y < SIZE_Y && w->f->x < SIZE_X)
	{
		pix = w->f->y * w->sizel + (w->f->x * 4);
		if (pix < SIZE_Y * SIZE_X * 4)
		{
			w->buf[pix] = w->f->blue;
			w->buf[pix + 1] = w->f->green;
			w->buf[pix + 2] = w->f->red;
		}
	}
}
