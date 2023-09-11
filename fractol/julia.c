/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazuki <akazuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:45:18 by akazuki           #+#    #+#             */
/*   Updated: 2023/05/28 19:58:59 by akazuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

void	julia_my_mlx_pixel_put(int x, int y, int count, t_data *data)
{
	int		add;
	char	*dst;

	add = (ONE_BYTE * 100 / LOOP_SIZE_JULIA) * (count);
	add <<= 16;
	if (add >= 200)
		add = 0x00FFFFFF;
	dst = data -> picture -> addr + ((int)y * data -> picture-> line_length + \
	(int)x * (data -> picture->bits_per_pixel / 8));
	*(unsigned int *)dst = add;
}

int	julia_divergence_check(t_data *data, double x_press, double y_press)
{
	int		count;
	double	n;
	double	i;

	count = 1;
	n = data -> zoom -> init_x;
	i = data -> zoom -> init_y;
	while (count <= LOOP_SIZE_JULIA)
	{
		n = real_number(x_press, y_press) + data -> zoom -> init_x;
		i = imaginary_number(x_press, y_press) + data -> zoom -> init_y;
		if (absolute_check(n, i) > 4.0)
			return (count);
		else
		{
			count++;
			x_press = n;
			y_press = i;
		}
	}
	return (0);
}

void	julia_put_pxcel(t_data *data, int x, int y)
{
	double	x_press;
	double	y_press;
	int		count;

	x_press = ((4.0 / ((double)WIN_WIDTH))) * (double)x - 2.0;
	y_press = ((4.0 / ((double)WIN_HEIGHT))) * (double)y - 2.0;
	count = julia_divergence_check(data, x_press, y_press);
	my_mlx_pixel_put(x, y, count, data);
}

void	julia(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			julia_put_pxcel(data, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data -> mlx, data -> mlx_win, \
	data -> picture -> img, 0, 0);
}
