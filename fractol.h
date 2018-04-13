/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <pkeita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 20:23:46 by pkeita            #+#    #+#             */
/*   Updated: 2017/07/27 11:12:35 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include "libft/include/libft.h"
# define WINDOW_SIZE 400

typedef struct	s_stock
{
	int			fract;
	int			x;
	int			y;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
	int			iter_max;
	int			iter;
	double		zoom_x;
	double		zoom_y;
	int			decalx;
	int			decaly;
	int			img_x;
	int			img_y;
	int			i;
	int			size_line;
	int			bpp;
	int			endian;
	double		zoom;
	int			color;
	int			background_color;
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
}				t_stock;

int				ft_init(t_stock *stock, char *file_name);
void			ft_init_mandelbrot(t_stock *s);
int				ft_fractol(t_stock *s);
void			ft_init_img_color(t_stock *s);
int				ft_event_key(int keycode, void *param);
int				ft_event_mouse(int x, int y, void *param);
void			ft_fractal(t_stock *s);
int				ft_mouse_zoom(int keycode, int x, int y, t_stock *s);
void			ft_douady(t_stock *s);
void			ft_douady_init(t_stock *s);
void			ft_douady_init2(t_stock *s);
void			ft_mandelbrot(t_stock *s);
void			ft_mandelbrot_init(t_stock *s);
void			ft_mandelbrot_init2(t_stock *s);
void			ft_siegel_init(t_stock *s);
void			ft_siegel_init2(t_stock *s);
void			ft_siegel(t_stock *s);
void			ft_julia(t_stock *s);
void			ft_julia_init(t_stock *s);
int				ft_draw_point(t_stock *s);
void			set_image(t_stock *s);
void			ft_pixel_put(int x, int y, int color, t_stock *s);
void			ft_clear_image(t_stock *s);
int				ft_usage(void);
void			fractal_init(t_stock *s);

#endif
