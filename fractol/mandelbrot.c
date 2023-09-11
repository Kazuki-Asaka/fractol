/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazuki <akazuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:26:33 by akazuki           #+#    #+#             */
/*   Updated: 2023/05/28 19:54:31 by akazuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

void	my_mlx_pixel_put(int x, int y, int count, t_data *data)
{
	int		add;
	char	*dst;

	add = (ONE_BYTE / LOOP_SIZE_MANDELBLOT) * (count * 1.5);
	if (add >= 200)
		add = 0x00FFFFFF;
	dst = data -> picture -> addr + ((int)y * data -> picture->line_length + \
	(int)x * (data -> picture->bits_per_pixel / 8));
	*(unsigned int *)dst = add;
}

int	mandelbrot_divergence_check(double x, double y)
{
	int		count;
	double	n;
	double	i;
	double	tmp_x;
	double	tmp_y;

	count = 1;
	tmp_x = x;
	tmp_y = y;
	while (count <= LOOP_SIZE_MANDELBLOT)
	{
		n = real_number(x, y) + tmp_x;
		i = imaginary_number(x, y) + tmp_y;
		if (absolute_check(n, i) > 4.0)
			return (count);
		else
			count++;
		x = n;
		y = i;
	}
	return (0);
}

void	mandelbrot_put_pxcel(t_data *data, int x, int y)
{
	double	x_press;
	double	y_press;
	int		count;

	x_press = (4.0 / ((double)WIN_WIDTH)) * (double)x - 2.0;
	y_press = (4.0 / ((double)WIN_HEIGHT)) * (double)y - 2.0;
	count = mandelbrot_divergence_check(x_press, y_press);
	if (count != 0)
		my_mlx_pixel_put(x, y, count, data);
}

void	my_mandelbrot(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data -> zoom -> init_x = 0;
	data -> zoom -> init_y = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			mandelbrot_put_pxcel(data, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data -> mlx, \
	data -> mlx_win, data -> picture -> img, 0, 0);
}
