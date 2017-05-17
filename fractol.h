/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 13:23:02 by kbobrov           #+#    #+#             */
/*   Updated: 2017/05/13 18:35:30 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"
# define SIZE_Y 600
# define SIZE_X 800
# define X w->f->x
# define Y w->f->y
# define ITER w->f->iter
# define R w->f->red
# define G w->f->green
# define B w->f->blue
# define NEWR w->f->newr
# define NEWI w->f->newi
# define OLDR w->f->oldr
# define OLDI w->f->oldi
# define MINI w->f->mini
# define MAXI w->f->maxi
# define MINR w->f->minr
# define MAXR w->f->maxr
# define CR w->f->cr
# define CI w->f->ci
# define FR w->f->fr
# define FG w->f->fg
# define FB w->f->fb
# define FORM log((log(sqrt(CR * CR + CI * CI)) / 2) / log(2)

typedef struct	s_param
{
	int		maxiter;
	int		iter;
	double	minr;
	double	maxr;
	double	mini;
	double	maxi;
	double	zoom;
	double	ci;
	double	cr;
	double	movex;
	double	movey;
	int		x;
	int		y;
	int		red;
	int		green;
	int		blue;
	int		i;
	double	newr;
	double	newi;
	double	oldr;
	double	oldi;
	int		key;
	double	mult;
	double	col;
	int		cl;
	double	fr;
	double	fg;
	double	fb;
}				t_param;

typedef struct	s_fract
{
	t_param	*f;
	t_param	pr[6];
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	int		bpp;
	int		endl;
	int		sizel;
}				t_fract;

int				my_key(int keycode, t_fract *f);
int				ft_mouse_exit(void);
void			ft_mandelbrot(t_fract *w);
void			ft_img_color(t_fract *w);
void			ft_julia(t_fract *w);
void			ft_kaleidoscope(t_fract *w);
void			ft_newton(t_fract *w);
void			ft_burnship(t_fract *w);
void			ft_imageinit(t_fract *w);
void			ft_imageput(t_fract *w);
int				ft_mouse_move(int x, int y, t_fract *w);
int				ft_mouse_zoom(int button, int x, int y, t_fract *w);
void			drawfract(t_fract *w);
void			color(t_fract *w);
void			color1(t_fract *w);
void			color2(t_fract *w);
void			colorchange(int	keycode, t_fract *w);

#endif
