/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:29:30 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/02/18 10:29:33 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_isdigit_res(int c)
{
	if ((c >= 48) && (c <= 57))
		return (c - 48);
	return (0);
}

int		ft_strlen_nbr_u(unsigned int n, int i)
{
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	if (n < 10)
		i++;
	return (i);
}

int		ft_strlen_nbr_x(unsigned int n, int i)
{
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	if (n < 10)
		i++;
	return (i);
}

int		ft_putnbr_ui_fd(unsigned int n, int fd)
{
	int i;

	i = 0;
	if (n >= 10)
	{
		ft_putnbr_ui_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + 48, fd);
		i++;
	}
	else if (n < 10)
	{
		ft_putchar_fd(n + 48, fd);
		i++;
	}
	return (i);
}

int		ft_putnbr_base(long n)
{
	long res;

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
			ft_putnbr_base(n / 16);
		if (n % 16 < 10)
			ft_putchar_fd((n % 16) + 48, 1);
		else
			ft_putchar_fd((n % 16) + 87, 1);
		res++;
	}
	return (res);
}
