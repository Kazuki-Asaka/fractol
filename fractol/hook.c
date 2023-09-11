/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazuki <akazuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:16:30 by akazuki           #+#    #+#             */
/*   Updated: 2023/05/28 20:13:10 by akazuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

void	put_pxcel_zoom_j(t_data *data, int x, int y, int button)
{
	double	x_press;
	double	y_press;
	double	count1;

	count1 = data -> zoom -> count;
	if (button == 4)
	{
		x_press = ((4.0 / ((double)WIN_WIDTH)) * (double)x * \
		ZOOM_IN * count1) - (2.0 * ZOOM_IN * count1);
		y_press = ((4.0 / ((double)WIN_HEIGHT)) * (double)y * \
		ZOOM_IN * count1) - (2.0 * ZOOM_IN * count1);
	}
	else if (button == 5)
	{
		x_press = ((4.0 / ((double)WIN_WIDTH)) * (double)x * \
		ZOOM_OUT * count1) - (2.0 * ZOOM_OUT * count1);
		y_press = ((4.0 / ((double)WIN_HEIGHT)) * (double)y * \
		ZOOM_OUT * count1) - (2.0 * ZOOM_OUT * count1);
	}
	else
		return ;
	my_mlx_pixel_put(x, y, \
	julia_divergence_check(data, x_press, y_press), data);
}

void	ft_zoom_j(int point_x, int point_y, t_data *data, int button)
{
	int	x;
	int	y;

	(void)point_x;
	(void)point_y;
	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			put_pxcel_zoom_j(data, x, y, button);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
	data->picture ->img, 0, 0);
}

void	put_pxcel_zoom_m(t_data *data, int x, int y, int button)
{
	double	x_press;
	double	y_press;
	double	count1;

	count1 = data -> zoom -> count;
	if (button == 4)
	{
		x_press = ((4.0 / ((double)WIN_WIDTH)) * \
		(double)x * ZOOM_IN * count1) - (2.0 * ZOOM_IN * count1);
		y_press = ((4.0 / ((double)WIN_HEIGHT)) * \
		(double)y * ZOOM_IN * count1) - (2.0 * ZOOM_IN * count1);
	}
	else if (button == 5)
	{
		x_press = ((4.0 / ((double)WIN_WIDTH)) * \
		(double)x * ZOOM_OUT * count1) - (2.0 * ZOOM_OUT * count1);
		y_press = ((4.0 / ((double)WIN_HEIGHT)) * \
		(double)y * ZOOM_OUT * count1) - (2.0 * ZOOM_OUT * count1);
	}
	else
		return ;
	my_mlx_pixel_put(x, y, \
	mandelbrot_divergence_check(x_press, y_press), data);
}

void	ft_zoom_m(int point_x, int point_y, t_data *data, int button)
{
	int	x;
	int	y;

	(void)point_x;
	(void)point_y;
	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			put_pxcel_zoom_m(data, x, y, button);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data -> mlx, data -> mlx_win, \
	data -> picture -> img, 0, 0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	if (check_count(data -> zoom -> count, button) == 1)
	{
		if (*(data -> name) == 'J')
		{
			ft_zoom_j(x, y, data, button);
			if (button == 4)
				data -> zoom -> count += 1.0;
			else if (button == 5)
				data -> zoom -> count *= 0.8;
		}
		else
		{
			ft_zoom_m(x, y, data, button);
			if (button == 4)
				data -> zoom -> count += 1.0;
			else if (button == 5)
				data -> zoom -> count *= 0.8;
		}
	}
	else
		ft_putendl_fd("not zoom", 2);
	return (1);
}
