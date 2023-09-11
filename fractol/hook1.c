/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazuki <akazuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:12:51 by akazuki           #+#    #+#             */
/*   Updated: 2023/05/28 20:13:27 by akazuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

int	check_count(double count, int button)
{
	if (button == 4)
	{
		if (count > 300)
			return (0);
	}
	else if (button == 5)
	{
		if (count < 0.000001)
			return (0);
	}
	return (1);
}
