/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:29:20 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/02/18 10:29:22 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd_modified(char *s, int fd, t_printf *st)
{
	int i;
	int j;

	i = 0;
	j = st->taille_p;
	while (s[i] && j != 0)
	{
		ft_putchar_fd(s[i], fd);
		i++;
		j--;
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(int n, int fd)
{
	int i;

	i = 0;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + 48, fd);
	}
	else if (n < 10 && n != -2147483648)
		ft_putchar_fd(n + 48, fd);
}

void	ft_putnbr_fd_modified(int n, int fd, t_printf *st)
{
	int i;
	int j;

	i = 0;
	j = st->taille_p + 1;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n >= 10 && j != 0)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + 48, fd);
		j--;
	}
	else if (n < 10 && n != -2147483648 && j != 0)
	{
		ft_putchar_fd(n + 48, fd);
		j--;
	}
}

int		print_zero_prec(int i)
{
	int res;

	res = 0;
	while (i != 0)
	{
		ft_putstr_fd("0", 1);
		i--;
		res++;
	}
	return (res);
}
