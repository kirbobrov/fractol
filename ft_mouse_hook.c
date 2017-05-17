/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:33:55 by kbobrov           #+#    #+#             */
/*   Updated: 2017/04/15 17:33:59 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mouse_zoom(int button, int x, int y, t_fract *w)
{
	double	mx;
	double	my;

	(button == 4) ? (w->f->mult = 1.1) : 0;
	(button == 5) ? (w->f->mult = 0.9) : 0;
	mx = (x * (fabs(MAXR - MINR) / SIZE_X)) + MINR;
	my = (y * (fabs(MAXI - MINI) / SIZE_Y)) + MINI;
	MINR = (MINR * w->f->mult) + (mx * (1 - w->f->mult));
	MAXR = (MAXR * w->f->mult) + (mx * (1 - w->f->mult));
	MINI = (MINI * w->f->mult) + (my * (1 - w->f->mult));
	MAXI = (MAXI * w->f->mult) + (my * (1 - w->f->mult));
	drawfract(w);
	return (0);
}

int	ft_mouse_move(int x, int y, t_fract *w)
{
	if (w->f == &w->pr[1] && x < SIZE_X && y < SIZE_Y && w->f->key != 1)
	{
		OLDI = y * (fabs(MAXI - MINI) / SIZE_Y) + MINI;
		w->f->cr = OLDI;
		OLDR = x * (fabs(MAXR - MINR) / SIZE_X) + MINR;
		w->f->ci = OLDR;
		(w->f == &w->pr[1]) ? ft_julia(w) : 0;
	}
	return (0);
}
