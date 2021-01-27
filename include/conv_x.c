/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:28:14 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/02/18 10:28:16 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv_is_x_minimum(t_printf *st, int len)
{
	if (st->taille_m > len)
		st->taille_m = st->taille_m - len;
	else
		st->taille_m = 0;
	if (st->c == '0' && st->taille_m != 0)
		len += print_zero(st);
	if (st->c == ' ' && st->taille_m != 0)
		len += print_space(st);
	return (len);
}

int		conv_is_x_precision(int x, t_printf *st, int len)
{
	int temp;

	temp = 0;
	if (st->taille_p > len)
		temp = st->taille_p - len;
	else
		temp = 0;
	len += print_zero_prec(temp);
	if (x != 0 || st->taille_p > 0)
		ft_putnbr_base(x);
	else
		len = 0;
	return (len);
}

int		x_space_and_zero_follow(unsigned int a, t_printf *st, int len)
{
	if (a == 0 && st->taille_m != 0 && ((st->taille_p == -1)
	|| (st->taille_p == 0)))
	{
		len = print_space(st);
		return (len);
	}
	if (st->taille_m > st->taille_p)
	{
		if ((st->taille_m > st->taille_p) && (st->taille_p > len))
			st->nb_espace = st->taille_m - st->taille_p;
		else if ((st->taille_m > len) && (st->taille_p < len))
			st->nb_espace = st->taille_m - len;
		else if ((st->taille_m > len) && (st->taille_p == len))
			st->nb_espace = st->taille_m - len - st->signe;
	}
	if (st->taille_p > len)
		st->nb_zero = st->taille_p - len;
	st->taille_m = st->nb_espace;
	print_space(st);
	print_zero_prec(st->nb_zero);
	if (a != 0 || st->taille_p != 0)
		ft_putnbr_base(a);
	else
		len = 0;
	return (len);
}

int		x_space_and_zero(unsigned int a, t_printf *st, int len)
{
	if (a == 4294967295 && st->taille_m > 8)
	{
		if (st->taille_p > 8)
			st->nb_zero = st->taille_p - 8;
		if (st->taille_p > st->taille_m)
			st->nb_espace = 0;
		else
			st->nb_espace = st->taille_m - 8 - st->nb_zero;
		print_space_mini(st->nb_espace);
		print_zero_prec(st->nb_zero);
		ft_putstr_fd("ffffffff", 1);
		return (st->nb_espace + st->nb_zero + 8);
	}
	else if (a == 4294967295 && st->taille_p > 8)
	{
		print_zero_prec(st->taille_p - 8);
		ft_putstr_fd("ffffffff", 1);
		return ((st->taille_p - 8) + 8);
	}
	len = x_space_and_zero_follow(a, st, len);
	len = st->nb_zero + st->nb_espace + len;
	return (len);
}

int		conv_is_x(va_list ap, t_printf *st)
{
	int x;
	int len;

	len = 0;
	x = va_arg(ap, int);
	len = ft_putnbr_base_res(x, &len);
	if (st->c == '1')
		len = x_space_and_zero(x, st, len);
	else if (st->taille_m != 0)
		len = conv_is_x_minimum(st, len);
	else if (st->taille_p != -1)
		len = conv_is_x_precision(x, st, len);
	if (st->taille_p == -1)
		ft_putnbr_base(x);
	st->i++;
	st->taille_m = 0;
	st->c = 0;
	return (len);
}
