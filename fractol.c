/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 13:22:53 by kbobrov           #+#    #+#             */
/*   Updated: 2017/04/07 13:22:55 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		drawfract(t_fract *w)
{
	(w->f == &w->pr[0]) ? ft_mandelbrot(w) : 0;
	(w->f == &w->pr[1]) ? ft_julia(w) : 0;
	(w->f == &w->pr[2]) ? ft_burnship(w) : 0;
	(w->f == &w->pr[3]) ? ft_kaleidoscope(w) : 0;
	(w->f == &w->pr[4]) ? ft_newton(w) : 0;
}

static void	ft_init(t_fract *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, SIZE_X, SIZE_Y, "fract'ol by kbobrov");
}

static void	ft_usage(void)
{
	write(1, "Usage : ./fractol <number from 1 to 5>\n", 39);
	write(1, "\t\t1. Mandelbrot\n", 16);
	write(1, "\t\t2. Julia\n", 11);
	write(1, "\t\t3. Burnship\n", 14);
	write(1, "\t\t4. Kaleidoscope\n", 18);
	write(1, "\t\t5. Newton\n", 12);
	write(1, "\t\t6. Biomorph\n", 14);
	exit(5);
}

void		fractol(char *av)
{
	t_fract w;

	ft_init(&w);
	(av[0] == '1') ? ft_mandelbrot(&w) : 0;
	(av[0] == '2') ? ft_julia(&w) : 0;
	(av[0] == '3') ? ft_burnship(&w) : 0;
	(av[0] == '4') ? ft_kaleidoscope(&w) : 0;
	(av[0] == '5') ? ft_newton(&w) : 0;
}

int			main(int ac, char **av)
{
	int		i;
	pid_t	pid;

	pid = 0;
	i = 0;
	(ac == 1) ? ft_usage() : 0;
	if (ac > 1)
	{
		while (++i < (ac - 1))
			if ((pid = fork()) == 0)
				break ;
		fractol(av[i]);
	}
	else
		ft_usage();
	return (0);
}
