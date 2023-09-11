/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazuki <akazuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:54:47 by akazuki           #+#    #+#             */
/*   Updated: 2023/05/29 17:02:27 by akazuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

void	check_arg(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "Mandelbrot", ft_strlen("Mandelbrot")) != 0)
			exit (1);
		else if (ft_strncmp("Mandelbrot", argv[1], ft_strlen(argv[1])) != 0)
			exit (1);
	}
	else if (argc == 4)
	{
		check_digit(argv[2]);
		check_digit(argv[3]);
		if (ft_strncmp(argv[1], "Julia", ft_strlen("Julia")) != 0)
			exit(1);
		else if (ft_strncmp("Julia", argv[1], ft_strlen(argv[1])) != 0)
			exit(1);
		my_atof(argv[2]);
		my_atof(argv[3]);
	}
	else
		exit(1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc <= 1)
		return (0);
	else
	{
		check_arg(argc, argv);
		data = init("fractol");
		data -> name = argv[1];
		make_picture(data);
		if (argc == 2)
			my_mandelbrot(data);
		else
		{
			data -> zoom -> init_x = my_atof(argv[2]);
			data -> zoom -> init_y = my_atof(argv[3]);
			julia(data);
		}
		mlx_mouse_hook(data-> mlx_win, mouse_hook, data);
		mlx_hook(data -> mlx_win, 2, 1L << 4, win_close, data);
		mlx_hook(data -> mlx_win, 17, 1L << 4, destroy, data);
		mlx_loop(data -> mlx);
	}
	return (0);
}
