/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:08:03 by pkeita            #+#    #+#             */
/*   Updated: 2017/10/20 15:08:05 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fractal(t_stock *s)
{
	if (s->fract == 1)
		ft_julia(s);
	else if (s->fract == 2)
		ft_mandelbrot(s);
	else if (s->fract == 3)
		ft_douady(s);
	else if (s->fract == 4)
		ft_siegel(s);
}

void	fractal_init(t_stock *s)
{
	if (s->fract == 1)
		ft_julia_init(s);
	else if (s->fract == 2)
		ft_mandelbrot_init(s);
	else if (s->fract == 3)
		ft_douady_init(s);
	else if (s->fract == 4)
		ft_siegel_init(s);
}
