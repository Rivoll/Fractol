/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <pkeita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 19:08:46 by pkeita            #+#    #+#             */
/*   Updated: 2017/07/26 06:34:42 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set_image(t_stock *s)
{
	s->img = mlx_new_image(s->mlx, WINDOW_SIZE, WINDOW_SIZE);
	s->data = mlx_get_data_addr(s->img, &s->bpp,
	&s->size_line, &s->endian);
	ft_fractal(s);
	mlx_clear_window(s->mlx, s->win);
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	mlx_string_put(s->mlx, s->win, 1, 310, 0xFFFFFF, "PRESS R: RESET");
	mlx_string_put(s->mlx, s->win, 1, 330, 0xFFFFFF,
		"USE SCROLL WHEEL: ZOOM");
	mlx_string_put(s->mlx, s->win, 1, 350, 0xFFFFFF,
	"PRESS ARROW KEYS: MOVE");
	mlx_string_put(s->mlx, s->win, 1, 370, 0xFFFFFF,
		"PRESS F: CHANGE FRACTAL");
	mlx_destroy_image(s->mlx, s->img);
}

int			ft_usage(void)
{
	ft_putstr("Usage : ./fractol\n1 julia\n2 mandelbrot\n3 Dadouy\n4 Siegel\n");
	return (0);
}

void		ft_pixel_put(int x, int y, int color, t_stock *s)
{
	int		index;

	if (x < WINDOW_SIZE && x >= 0 && y >= 0 && y < WINDOW_SIZE)
	{
		index = s->x * s->bpp / 8 + y * s->size_line;
		s->data[index] = color & 0xff;
		s->data[++index] = color >> 8 & 0xff;
		s->data[++index] = color >> 16;
	}
}

int			main(int argc, char **argv)
{
	t_stock s;

	if (argc != 2 || (ft_strcmp(argv[1], "1") && ft_strcmp(argv[1], "2") &&
	ft_strcmp(argv[1], "3") && ft_strcmp(argv[1], "4")))
		return (ft_usage());
	s.img_x = WINDOW_SIZE;
	s.img_y = WINDOW_SIZE;
	if (!(s.mlx = mlx_init()))
		return (0);
	if (!(s.win = mlx_new_window(s.mlx, WINDOW_SIZE, WINDOW_SIZE, "Fractol")))
		return (0);
	s.fract = ft_atoi(argv[1]);
	fractal_init(&s);
	set_image(&s);
	mlx_hook(s.win, 2, 3, ft_event_key, &s);
	mlx_hook(s.win, 6, 1, ft_event_mouse, &s);
	mlx_mouse_hook(s.win, ft_mouse_zoom, &s);
	mlx_loop(s.mlx);
}
