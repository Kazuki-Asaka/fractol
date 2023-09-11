/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazuki <akazuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:17:46 by akazuki           #+#    #+#             */
/*   Updated: 2023/05/28 20:11:26 by akazuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

double	absolute_check(double real, double imaginary)
{
	return (real * real + imaginary * imaginary);
}

double	real_number(double x, double y)
{
	return (x * x - y * y);
}

double	imaginary_number(double x, double y)
{
	return (2 * x * y);
}
