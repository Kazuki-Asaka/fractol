/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazuki <akazuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:17:58 by akazuki           #+#    #+#             */
/*   Updated: 2023/05/28 19:59:22 by akazuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

int	win_close(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data -> mlx, data->mlx_win);
		exit(0);
	}
	else
		return (1);
}

int	destroy(t_data *data)
{
	mlx_destroy_window(data -> mlx, data -> mlx_win);
	free(data -> zoom);
	free(data -> picture);
	free(data);
	exit(0);
	return (1);
}
