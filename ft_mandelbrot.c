/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findmandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 13:45:37 by kbobrov           #+#    #+#             */
/*   Updated: 2017/04/07 13:45:39 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mandinit(t_param *m)
{
	m->maxiter = 155;
	m->x = 0;
	m->y = 0;
	m->ci = 0;
	m->cr = 0;
	m->iter = 0;
	m->i = 1;
	m->zoom = 1;
	m->mult = 1;
	m->maxi = 1;
	m->maxr = 1;
	m->mini = -1;
	m->minr = -2;
	m->fr = 1;
	m->fg = 1;
	m->fb = 1;
	m->cl = 1;
}

static int	mandelbrot(t_fract *w)
{
	ITER = -1;
	while (++ITER < w->f->maxiter && (OLDR * OLDR + OLDI * OLDI) < 4.0)
	{
		NEWR = OLDR * OLDR - OLDI * OLDI;
		NEWI = 2 * OLDR * OLDI;
		OLDR = NEWR + w->f->cr + w->f->movex;
		OLDI = NEWI + w->f->ci + w->f->movey;
	}
	return (ITER);
}

void		ft_mandelbrot(t_fract *w)
{
	w->f = &w->pr[0];
	ft_imageinit(w);
	(w->f->i != 1) ? mandinit(w->f) : 0;
	w->f->y = -1;
	while (++w->f->y < SIZE_Y)
	{
		w->f->x = -1;
		while (++w->f->x < SIZE_X)
		{
			OLDI = Y * (fabs(MAXI - MINI) / SIZE_Y) + MINI;
			w->f->ci = OLDI;
			OLDR = X * (fabs(MAXR - MINR) / SIZE_X) + MINR;
			w->f->cr = OLDR;
			w->f->iter = mandelbrot(w);
			color(w);
			ft_img_color(w);
		}
	}
	ft_imageput(w);
	mlx_hook(w->win, 17, 0L, ft_mouse_exit, w);
	mlx_hook(w->win, 4, 0, ft_mouse_zoom, w);
	mlx_hook(w->win, 2, 5, my_key, w);
	mlx_loop(w->mlx);
}
