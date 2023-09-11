/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazuki <akazuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:14:19 by akazuki           #+#    #+#             */
/*   Updated: 2023/05/28 19:51:07 by akazuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

t_data	*init(char *name)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data) * 1);
	data -> mlx = mlx_init();
	if (data->mlx == NULL)
		print_error_and_exit("mlx_error\n");
	data->mlx_win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, name);
	if (data->mlx_win == NULL)
		print_error_and_exit("mlx_error\n");
	return (data);
}

void	make_picture(t_data *data)
{
	data -> picture = (t_picture *)malloc(sizeof(t_picture) * 1);
	if (data -> picture == NULL)
		print_error_and_exit("malloc_error\n");
	data-> picture -> img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (data -> picture -> img == NULL)
		print_error_and_exit("picture_error\n");
	data-> picture -> addr = mlx_get_data_addr(data-> picture -> img, \
	&data->picture ->bits_per_pixel, &data->picture ->line_length, \
	&data->picture -> endian);
	if (data -> picture -> addr == NULL)
		print_error_and_exit("picture_error\n");
	data->zoom = (t_zoom *)malloc(sizeof(t_zoom) * 1);
	if (data -> zoom == NULL)
		print_error_and_exit("malloc_error\n");
	data-> zoom -> count = 1.0;
}
