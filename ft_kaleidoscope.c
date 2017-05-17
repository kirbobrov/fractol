/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kaleidoscope.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 19:55:23 by kbobrov           #+#    #+#             */
/*   Updated: 2017/04/15 19:55:27 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	kalinit(t_param *k)
{
	k->maxiter = 155;
	k->minr = -2.0;
	k->maxr = 0.8;
	k->mini = -1;
	k->maxi = 1;
	k->x = 0;
	k->y = 0;
	k->ci = 0;
	k->cr = 0;
	k->iter = 0;
	k->i = 1;
	k->zoom = 1;
	k->fr = 0;
	k->fg = 1;
	k->fb = 0;
	k->cl = 1;
}

static int	kaleidoscope(t_fract *w)
{
	ITER = -1;
	OLDR = cos(OLDR);
	OLDI = sin(OLDI);
	while (++ITER < w->f->maxiter && (OLDR * OLDR + OLDI * OLDI) < 4.0)
	{
		NEWR = OLDR * OLDR - OLDI * OLDI;
		NEWI = 2 * OLDR * OLDI;
		OLDR = NEWR + w->f->cr + w->f->movex;
		OLDI = NEWI + w->f->ci + w->f->movey;
	}
	return (ITER);
}

void		ft_kaleidoscope(t_fract *w)
{
	w->f = &w->pr[3];
	ft_imageinit(w);
	(w->f->i != 1) ? kalinit(w->f) : 0;
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
			ITER = kaleidoscope(w);
			color(w);
			ft_img_color(w);
		}
	}
	ft_imageput(w);
	mlx_hook(w->win, 17, 0L, ft_mouse_exit, w);
	mlx_hook(w->win, 2, 5, my_key, w);
	mlx_loop(w->mlx);
}
