/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <pkeita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 02:49:26 by pkeita            #+#    #+#             */
/*   Updated: 2017/07/26 06:32:54 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				ft_event_mouse(int x, int y, void *param)
{
	t_stock		*s;

	s = param;
	if (x < WINDOW_SIZE && x > 0 && y < WINDOW_SIZE && y > 0)
	{
		s->c_r = (double)(x + 400 - WINDOW_SIZE) / 500;
		s->c_i = (double)(y + 400 - WINDOW_SIZE) / 500;
	}
	set_image(s);
	return (0);
}

int				ft_mouse_zoom(int keycode, int x, int y, t_stock *s)
{
	double		tmpx;
	double		tmpy;

	tmpx = x / s->zoom_x + s->x1;
	tmpy = y / s->zoom_y + s->y1;
	if (keycode == 5)
	{
		s->zoom_x /= 1.1;
		s->zoom_y /= 1.1;
	}
	else if (keycode == 4)
	{
		s->zoom_x *= 1.1;
		s->zoom_y *= 1.1;
	}
	s->x1 = tmpx - (x / s->zoom_x);
	s->y1 = tmpy - (y / s->zoom_y);
	set_image(s);
	return (0);
}

int				ft_event_key(int keycode, void *param)
{
	t_stock		*s;

	s = param;
	if (keycode == 124)
		s->x1 -= (10 / s->zoom_x);
	else if (keycode == 123)
		s->x1 += 10 / s->zoom_x;
	else if (keycode == 126)
		s->y1 += 10 / s->zoom_y;
	else if (keycode == 125)
		s->y1 -= 10 / s->zoom_y;
	else if (keycode == 15)
		fractal_init(s);
	else if (keycode == 3)
	{
		if (s->fract == 4)
			s->fract = 1;
		else
			s->fract++;
		fractal_init(s);
	}
	else if (keycode == 53)
		exit(1);
	set_image(s);
	return (0);
}

void			ft_clear_image(t_stock *s)
{
	int			x;
	int			y;
	int			index;

	x = 0;
	y = 0;
	while (y < WINDOW_SIZE)
	{
		x = 0;
		while (x < WINDOW_SIZE)
		{
			index = x * s->bpp / 8 + y * s->size_line;
			s->data[index] = 0;
			s->data[++index] = 0;
			s->data[++index] = 0;
			x++;
		}
		y++;
	}
}
