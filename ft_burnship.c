/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burnship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:56:39 by kbobrov           #+#    #+#             */
/*   Updated: 2017/04/13 16:56:41 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	burninit(t_param *b)
{
	b->maxiter = 155;
	b->minr = -2.2;
	b->maxr = 1.5;
	b->mini = -2.2;
	b->maxi = 1.2;
	b->x = 0;
	b->y = 0;
	b->ci = 0;
	b->cr = 0;
	b->iter = 0;
	b->zoom = 1;
	b->i = 1;
	b->fr = 1;
	b->fg = 1;
	b->fb = 1;
	b->cl = 1;
}

static int	burn_iter(t_fract *w)
{
	double	temp;

	ITER = -1;
	NEWR = 0.0;
	NEWI = 0.0;
	while (++ITER < w->f->maxiter && NEWR * NEWR + NEWI * NEWI < 4.0)
	{
		temp = NEWR * NEWR - NEWI * NEWI;
		NEWI = 2 * fabs(NEWR * NEWI) + OLDI;
		NEWR = temp + OLDR;
	}
	return (ITER);
}

void		ft_burnship(t_fract *w)
{
	w->f = &w->pr[2];
	ft_imageinit(w);
	(w->f->i != 1) ? burninit(w->f) : 0;
	Y = -1;
	while (++Y < SIZE_Y)
	{
		X = -1;
		while (++X < SIZE_X)
		{
			OLDI = Y * (fabs(MAXI - MINI) / SIZE_Y) + MINI;
			w->f->ci = OLDI;
			OLDR = X * (fabs(MAXR - MINR) / SIZE_X) + MINR;
			w->f->cr = OLDR;
			ITER = burn_iter(w);
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
