/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazuki <akazuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:42:53 by akazuki           #+#    #+#             */
/*   Updated: 2023/08/16 14:58:57 by akazuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include "libft.h"

typedef struct zoom{
	double	count;
	double	init_x;
	double	init_y;
}	t_zoom;

typedef struct picture{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_picture;

typedef struct data{
	void		*mlx;
	void		*mlx_win;
	t_zoom		*zoom;
	char		*name;
	t_picture	*picture;
}	t_data;

# define LOOP_SIZE_MANDELBLOT 30
# define LOOP_SIZE_JULIA 500
# define WIN_WIDTH 1080
# define WIN_HEIGHT 1080
# define ONE_BYTE	255
# define ZOOM_IN	0.8
# define ZOOM_OUT	1.5

double	my_atof(char *digit);
void	print_error_and_exit(char *message);

t_data	*init(char *name);
void	make_picture(t_data *data);

double	real_number(double x, double y);
double	imaginary_number(double x, double y);
double	absolute_check(double real, double imaginary);

void	my_mlx_pixel_put(int x, int y, int count, t_data *data);
int		mandelbrot_divergence_check(double x, double y);
void	mandelbrot_put_pxcel(t_data *data, int x, int y);
void	my_mandelbrot(t_data *data);

int		julia_divergence_check(t_data *data, double x_press, double y_press);
void	julia_put_pxcel(t_data *data, int x, int y);
void	julia(t_data *data);
void	julia_my_mlx_pixel_put(int x, int y, int count, t_data *data);

int		mouse_hook(int button, int x, int y, t_data *data);
void	ft_zoom_j(int point_x, int point_y, t_data *data, int button);
void	put_pxcel_zoom_j(t_data *data, int x, int y, int button);
void	ft_zoom_m(int point_x, int point_y, t_data *data, int button);
void	put_pxcel_zoom_m(t_data *data, int x, int y, int button);

int		win_close(int keycode, t_data *data);
int		destroy(t_data *data);
void	check_digit(char *digit);

int		check_count(double count, int button);

#endif