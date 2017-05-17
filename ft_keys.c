/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:51:15 by kbobrov           #+#    #+#             */
/*   Updated: 2017/05/13 17:51:18 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				ft_mouse_exit(void)
{
	exit(77);
}

int				ft_move(t_fract *w, int keycode)
{
	if (keycode == 123)
	{
		w->f->minr -= (0.1 * (MAXR - MINR));
		w->f->maxr -= (0.1 * (MAXR - MINR));
		drawfract(w);
	}
	if (keycode == 124)
	{
		w->f->minr += (0.1 * (MAXR - MINR));
		w->f->maxr += (0.1 * (MAXR - MINR));
		drawfract(w);
	}
	if (keycode == 126)
	{
		w->f->mini -= (0.1 * (MAXI - MINI));
		w->f->maxi -= (0.1 * (MAXI - MINI));
		drawfract(w);
	}
	if (keycode == 125)
	{
		w->f->mini += (0.1 * (MAXI - MINI));
		w->f->maxi += (0.1 * (MAXI - MINI));
		drawfract(w);
	}
	return (0);
}

static int		keyfr(int keycode, t_fract *w)
{
	if (keycode == 26 || keycode == 25 || keycode == 28 || keycode == 29)
	{
		(keycode == 26) ? w->f->cl = 1 : 0;
		(keycode == 28) ? w->f->cl = 2 : 0;
		(keycode == 25) ? w->f->cl = 3 : 0;
		drawfract(w);
	}
	(keycode == 18) ? ft_mandelbrot(w) : 0;
	(keycode == 19) ? ft_julia(w) : 0;
	(keycode == 20) ? ft_burnship(w) : 0;
	(keycode == 21) ? ft_kaleidoscope(w) : 0;
	(keycode == 23) ? ft_newton(w) : 0;
	return (0);
}

int				my_key(int keycode, t_fract *w)
{
	(keycode == 53) ? exit(53) : 0;
	(keycode == 123 || keycode == 124 ||
			keycode == 125 || keycode == 126) ? ft_move(w, keycode) : 0;
	(keycode == 78 || keycode == 69 || keycode == 14 ||
			keycode == 15 || keycode == 3 || keycode == 5 ||
			keycode == 9 || keycode == 11) ? colorchange(keycode, w) : 0;
	if (keycode == 42 || keycode == 44)
	{
		(keycode == 42) ? w->f->maxiter -= 20 : 0;
		(keycode == 44) ? w->f->maxiter += 20 : 0;
		drawfract(w);
	}
	if (keycode == 1)
	{
		(w->f->key != 1) ? (w->f->key = 1) :
		(w->f->key = 0);
	}
	if (keycode == 26 || keycode == 25 || keycode == 28 ||
			keycode == 18 || keycode == 19 ||
			keycode == 20 || keycode == 21 || keycode == 23)
		keyfr(keycode, w);
	return (0);
}
