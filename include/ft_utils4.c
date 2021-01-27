/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:29:37 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/02/18 10:29:40 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_base_res(long n, int *res)
{
	if (n < 0)
		n = 4294967295 + n + 1;
	if (n == 0)
		*res = *res + 1;
	else
	{
		if (n >= 16)
			ft_putnbr_base_res(n / 16, res);
		if (n % 16 < 10)
			*res = *res + 1;
		else
			*res = *res + 1;
	}
	return (*res);
}

int		ft_putnbr_base_maj(long n)
{
	int res;

	res = 0;
	if (n < 0)
		n = 4294967295 + n + 1;
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		res = res + 1;
	}
	else
	{
		if (n >= 16)
			ft_putnbr_base_maj(n / 16);
		if (n % 16 < 10)
			ft_putchar_fd((n % 16) + 48, 1);
		else
			ft_putchar_fd((n % 16) + 55, 1);
		res++;
	}
	return (res);
}

int		ft_putnbr_base_maj_res(long n, int *res)
{
	if (n < 0)
		n = 4294967295 + n + 1;
	if (n == 0)
		*res = *res + 1;
	else
	{
		if (n >= 16)
			ft_putnbr_base_maj_res(n / 16, res);
		if (n % 16 < 10)
			*res = *res + 1;
		else
			*res = *res + 1;
	}
	return (*res);
}

int		ft_putnbr_base_p(unsigned long long n)
{
	int res;

	res = 0;
	if (n < 0)
		n = 9223372036854775807 + n + 1;
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		res = res + 1;
	}
	else
	{
		if (n >= 16)
			ft_putnbr_base_p(n / 16);
		if (n % 16 < 10)
			ft_putchar_fd((n % 16) + 48, 1);
		else
			ft_putchar_fd((n % 16) + 87, 1);
		res++;
	}
	return (res);
}

int		ft_putnbr_base_p_res(unsigned long long n, int *res)
{
	if (n < 0)
		n = 9223372036854775807 + n + 1;
	if (n == 0)
		*res = *res + 1;
	else
	{
		if (n >= 16)
			ft_putnbr_base_p_res(n / 16, res);
		if (n % 16 < 10)
			*res = *res + 1;
		else
			*res = *res + 1;
	}
	return (*res);
}
