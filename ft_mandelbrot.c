/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:40:17 by pkeita            #+#    #+#             */
/*   Updated: 2017/10/20 11:40:19 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot_init(t_stock *s)
{
	s->x1 = -1.960;
	s->x2 = 0.6;
	s->y1 = -1.2;
	s->y2 = 1.2;
	s->iter_max = 250;
	s->zoom_x = 150;
	s->zoom_y = 150;
	s->c_r = s->x / s->zoom_x + s->x1;
	s->c_i = s->y / s->zoom_y + s->y1;
	s->z_r = 0;
	s->z_i = 0;
	s->i = 0;
	s->img_x = WINDOW_SIZE;
	s->img_y = WINDOW_SIZE;
	s->color = 0xFFFFFF;
}

void	ft_mandelbrot_init2(t_stock *s)
{
	s->c_r = (double)s->x / s->zoom_x + s->x1;
	s->c_i = (double)s->y / s->zoom_y + s->y1;
	s->z_r = 0;
	s->z_i = 0;
	s->i = 0;
}

void	ft_mandelbrot(t_stock *s)
{
	s->x = 0;
	while (s->x < s->img_x)
	{
		s->y = 0;
		while (s->y < s->img_y)
		{
			ft_mandelbrot_init2(s);
			while ((s->z_r * s->z_r + s->z_i * s->z_i) < 4 &&
					s->i < s->iter_max)
			{
				s->tmp = s->z_r;
				s->z_r = s->z_r * s->z_r - s->z_i * s->z_i + s->c_r;
				s->z_i = 2 * s->z_i * s->tmp + s->c_i;
				s->i++;
			}
			if (s->i == s->iter_max)
				ft_pixel_put(s->x, s->y, s->color, s);
			else
				ft_pixel_put(s->x, s->y, s->color * s->i / s->iter_max, s);
			s->y++;
		}
		s->x++;
	}
}
