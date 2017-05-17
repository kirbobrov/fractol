/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:29:52 by kbobrov           #+#    #+#             */
/*   Updated: 2017/04/11 17:29:54 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	juliainit(t_param *j)
{
	j->maxiter = 155;
	j->cr = -0.7;
	j->ci = 0.47015;
	j->zoom = 1;
	j->movex = 0;
	j->movey = 0;
	j->i = 1;
	j->mult = 1;
	j->cl = 3;
	j->maxi = 1.7;
	j->maxr = 2;
	j->mini = -1.7;
	j->minr = -2;
	j->fr = 0;
	j->fg = 1;
	j->fb = 0;
}

static int	julia(t_fract *w)
{
	ITER = -1;
	while (++ITER < w->f->maxiter && (OLDR * OLDR + OLDI * OLDI) < 4)
	{
		NEWR = OLDR * OLDR - OLDI * OLDI;
		NEWI = 2 * OLDR * OLDI;
		OLDR = NEWR + w->f->cr + w->f->movex;
		OLDI = NEWI + w->f->ci + w->f->movey;
	}
	return (ITER);
}

void		ft_julia(t_fract *w)
{
	w->f = &w->pr[1];
	ft_imageinit(w);
	(w->f->i != 1) ? juliainit(w->f) : 0;
	Y = -1;
	while (++Y < SIZE_Y)
	{
		X = -1;
		while (++X < SIZE_X)
		{
			OLDI = Y * (fabs(MAXI - MINI) / SIZE_Y) + MINI;
			OLDR = X * (fabs(MAXR - MINR) / SIZE_X) + MINR;
			ITER = julia(w);
			color(w);
			ft_img_color(w);
		}
	}
	ft_imageput(w);
	mlx_hook(w->win, 17, 0L, ft_mouse_exit, w);
	mlx_hook(w->win, 6, 0, ft_mouse_move, w);
	mlx_hook(w->win, 4, 0, ft_mouse_zoom, w);
	mlx_hook(w->win, 2, 5, my_key, w);
	mlx_loop(w->mlx);
}
