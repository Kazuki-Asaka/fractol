/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazuki <akazuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:45:53 by akazuki           #+#    #+#             */
/*   Updated: 2023/05/28 20:22:35 by akazuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

int	check_intenger(double num, char digit)
{
	double	number;

	if (num < 0)
		num = -num;
	number = digit - '0';
	if (2 / 10 < num)
		return (1);
	else
	{
		if (2 % 10 < number && 2 / 10 == num)
			return (1);
		else
			return (0);
	}
}

double	ft_decimal(double num, char *digit)
{
	double	dec;
	double	i;
	double	x;

	i = 1;
	dec = 0.0;
	while ('0' <= *digit && *digit <= '9')
	{
		i *= 0.1;
		x = (*digit - '0') * i;
		if ((num == 2 || num == -2) && x != 0)
			print_error_and_exit("flow");
		dec += x;
		digit++;
	}
	return (dec + num);
}

double	ft_integer(char *digit)
{
	double	num;

	num = 0;
	while ('0' <= *digit && *digit <= '9')
	{
		if (check_intenger(num, *digit) == 1)
			print_error_and_exit("flow");
		num = num * 10 + *digit - '0';
		digit++;
	}
	if (*digit == '.')
	{
		digit++;
		num = ft_decimal(num, digit);
	}
	return (num);
}

double	my_atof(char *digit)
{
	double		sign;
	double		num;

	check_digit(digit);
	num = 0.0;
	sign = 1.0;
	while (*digit == ' ' || *digit == '\n' || *digit == '\t'\
	||*digit == '\v' || *digit == '\f' || *digit == '\r')
		digit++;
	if (*digit == '-' || *digit == '+')
	{
		if (*digit == '-')
			sign = -sign;
		digit++;
	}
	num = ft_integer(digit);
	return (sign * num);
}

void	check_digit(char *digit)
{
	int	count;

	count = 0;
	if (*digit == '-')
		digit++;
	while (*digit != '\0')
	{
		if ('0' <= *digit && *digit <= '9')
			digit++;
		else if (*digit == '.')
		{
			count++;
			digit++;
		}
		else
			print_error_and_exit("not digit\n");
	}
	if (count > 2)
		exit(1);
}
