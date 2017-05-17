/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 17:39:38 by kbobrov           #+#    #+#             */
/*   Updated: 2017/05/02 17:39:40 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color2(t_fract *w)
{
	double smooth;

	smooth = ITER + 1 - (log(log(4)) / log(2));
	w->f->red = (unsigned char)(sin(w->f->col * smooth + 1) * 127.5 + 127.5);
	w->f->green = (unsigned char)(sin(w->f->col * smooth + 2) * 127.5 + 127.5);
	w->f->blue = (unsigned char)(sin(w->f->col * smooth + 4) * 127.5 + 127.5);
}

void	color1(t_fract *w)
{
	if (ITER == w->f->maxiter)
	{
		w->f->red = 0;
		w->f->green = 0;
		w->f->blue = 0;
	}
	else
	{
		w->f->red = ITER + 1 - (FORM) / log(2)) * FR;
		w->f->green = (ITER * ITER / 2 % 256) * FG;
		w->f->blue = (12 * ITER % 256) * FB;
	}
}

void	color3(t_fract *w)
{
	if (ITER == w->f->maxiter)
	{
		R = 255;
		G = 255;
		B = 155;
	}
	else
	{
		w->f->red = (10 * ITER % 256);
		w->f->green = (ITER % 256) * (ITER < w->f->maxiter);
		w->f->blue = 255 * (w->f->iter < w->f->maxiter);
	}
}

void	color(t_fract *w)
{
	(w->f->cl == 1) ? (color1(w)) : 0;
	(w->f->cl == 2) ? (color2(w)) : 0;
	(w->f->cl == 3) ? (color3(w)) : 0;
}

void	colorchange(int keycode, t_fract *w)
{
	(keycode == 78) ? w->f->col -= 0.01 : 0;
	(keycode == 69) ? w->f->col += 0.01 : 0;
	(keycode == 14) ? FR -= 0.02 : 0;
	(keycode == 15) ? FR += 0.02 : 0;
	(keycode == 3) ? FG -= 0.02 : 0;
	(keycode == 5) ? FG += 0.02 : 0;
	(keycode == 9) ? FB -= 0.02 : 0;
	(keycode == 11) ? FB += 0.02 : 0;
	drawfract(w);
}
