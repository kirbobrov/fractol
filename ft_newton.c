/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:53:18 by kbobrov           #+#    #+#             */
/*   Updated: 2017/04/13 15:53:22 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	newtoninit(t_param *n)
{
	n->maxiter = 155;
	n->ci = 0;
	n->cr = 0;
	n->iter = 0;
	n->i = 2;
	n->zoom = 1;
	n->maxi = 1;
	n->maxr = 1;
	n->mini = -1;
	n->minr = -1;
	n->col = 0.09;
	n->fr = 0;
	n->fg = 1;
	n->fb = 0;
	n->cl = 2;
	n->movex = 0;
	n->movey = 0;
}

static int	newtoniter(t_fract *w)
{
	double	tmp;

	OLDI = Y * (fabs(MAXI - MINI) / SIZE_Y) + MINI;
	OLDR = X * (fabs(MAXR - MINR) / SIZE_X) + MINR;
	tmp = 1.0;
	ITER = 0;
	while (tmp > 0.0000001 && ++ITER < w->f->maxiter)
	{
		NEWR = OLDR;
		NEWI = OLDI;
		tmp = (OLDR * OLDR + OLDI * OLDI) * (OLDR * OLDR + OLDI * OLDI);
		OLDR = (2 * OLDR * tmp + OLDR * OLDR - OLDI * OLDI) / (3.0 * tmp);
		OLDI = (2 * OLDI * (tmp - NEWR)) / (3.0 * tmp);
		tmp = (OLDR - NEWR) * (OLDR - NEWR) + (OLDI - NEWI) * (OLDI - NEWI);
	}
	return (ITER);
}

void		ft_newton(t_fract *w)
{
	w->f = &w->pr[4];
	ft_imageinit(w);
	(w->f->i != 2) ? newtoninit(w->f) : 0;
	Y = -1;
	while (++Y < SIZE_Y)
	{
		X = -1;
		while (++X < SIZE_X)
		{
			ITER = newtoniter(w);
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
