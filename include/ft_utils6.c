/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:29:49 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/02/18 10:29:51 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_zero(t_printf *st)
{
	int res;

	res = 0;
	while (st->taille_m != 0)
	{
		ft_putstr_fd("0", 1);
		st->taille_m--;
		res++;
	}
	st->taille_m = 1;
	return (res);
}

int		print_space_zero(t_printf *st, int res)
{
	if (st->c == '0' && st->taille_m != 0)
		res = print_zero(st) + 1;
	if (st->c == ' ' && st->taille_m != 0)
		res = print_space(st) + 1;
	return (res);
}

int		conv_is_d_minimum(int a, t_printf *st, int len)
{
	st->temp = st->taille_m;
	if (a == -2147483648)
	{
		ft_putstr_fd("-", 1);
		if (st->taille_m > 11)
			len = print_zero_prec(st->taille_m - 11);
		else
			len = 0;
		ft_putstr_fd("2147483648", 1);
		return (11 + len);
	}
	if (st->taille_m > len)
		st->taille_m = st->taille_m - len;
	else
		st->taille_m = 0;
	if (st->c == '0' && st->taille_m != 0)
		len += print_zero(st);
	if (st->c == ' ' && st->taille_m != 0)
		len += print_space(st);
	if (a != -2147483648)
		ft_putnbr_fd(a, 1);
	if (a < 0 && st->signe == 1)
		return (st->temp++);
	else
		return (len);
}
