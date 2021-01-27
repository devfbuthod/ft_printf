/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:27:23 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/02/18 10:27:28 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv_is_d_precision(int a, t_printf *st, int signe)
{
	int len;
	int temp;

	temp = 0;
	len = ft_strlen_nbr(a, 0);
	if (a == -2147483648 && st->taille_p > 10)
	{
		ft_putstr_fd("-", 1);
		print_zero_prec(st->taille_p - 10);
		ft_putstr_fd("2147483648", 1);
		return ((st->taille_p - 10) + 11);
	}
	if (st->taille_p < 0)
		st->taille_p = ft_strlen_nbr(a, 0);
	if (st->taille_p >= len && st->taille_p != -1)
		temp = st->taille_p - len;
	len += print_zero_prec(temp);
	if (a != 0 || st->taille_p > 0)
		ft_putnbr_fd_modified(a, 1, st);
	else
		len = 0;
	return (len + signe);
}

int		d_space_and_zero_follow2(int a, t_printf *st, int len)
{
	if (a > 0)
	{
		print_zero_prec(st->nb_zero);
		ft_putnbr_fd_modified(a, 1, st);
	}
	else if (a != 0 || st->taille_p != 0)
		ft_putnbr_fd_2(a, 1, st, st->nb_zero);
	else
		len = 0;
	return (len);
}

int		d_space_and_zero_follow(int a, t_printf *st, int len)
{
	if (st->taille_m > st->taille_p)
	{
		if (st->a < 0)
		{
			if (st->taille_m > len && (st->taille_m < st->taille_p + 1
			|| st->taille_p == 0))
				st->nb_espace = st->taille_m - len;
			else if (st->taille_m > len)
				st->nb_espace = st->taille_m - st->taille_p - 1;
		}
		else if ((st->taille_m > st->taille_p) && (st->taille_p > len))
			st->nb_espace = st->taille_m - st->taille_p;
		else if ((st->taille_m > len) && (st->taille_p < len))
			st->nb_espace = st->taille_m - len;
		else if ((st->taille_m > len) && (st->taille_p == len))
			st->nb_espace = st->taille_m - len - st->signe;
	}
	if (a < 0 && st->taille_p > (len - 1))
		st->nb_zero = st->taille_p - (len - 1);
	else if (st->taille_p > len)
		st->nb_zero = st->taille_p - len;
	st->taille_m = st->nb_espace;
	print_space(st);
	len = d_space_and_zero_follow2(a, st, len);
	return (len);
}

int		d_space_and_zero(int a, t_printf *st, int len)
{
	if (a == 2147483647 && st->taille_m <= 10)
	{
		ft_putstr_fd("2147483647", 1);
		return (10);
	}
	else if (a == 2147483647 && st->taille_m > 10)
	{
		print_space_mini(st->taille_m - 10);
		ft_putstr_fd("2147483647", 1);
		return ((st->taille_m - 10) + 10);
	}
	else if (a == 0 && st->taille_m != 0 && ((st->taille_p == -1)
	|| (st->taille_p == 0)))
	{
		len = st->taille_m;
		print_space(st);
		return (len);
	}
	if (st->taille_p < 0)
		st->taille_p = ft_strlen_nbr(a, 0);
	if (st->taille_m < 0)
		st->taille_m = ft_strlen_nbr(a, 0);
	len = d_space_and_zero_follow(a, st, len);
	len = st->nb_zero + st->nb_espace + len;
	return (len);
}

int		conv_is_d(va_list ap, t_printf *st)
{
	int len;

	len = 0;
	st->a = va_arg(ap, int);
	if (st->a < 0 && st->a != -2147483648 && st->c != ' ' && st->c != '1')
	{
		ft_putstr_fd("-", 1);
		st->a = -st->a;
		len += 1;
		st->signe = 1;
	}
	len = ft_strlen_nbr(st->a, len);
	if (st->c == '1')
		len = d_space_and_zero(st->a, st, len);
	else if ((st->taille_m == 0 && st->taille_p == -1) || st->j == -2)
		ft_putnbr_fd(st->a, 1);
	else if ((st->taille_m != 0 && st->taille_p == -1) || st->c == '0')
		len = conv_is_d_minimum(st->a, st, len);
	else if (st->taille_p != -1 && st->taille_m == 0)
		len = conv_is_d_precision(st->a, st, st->signe);
	st->i++;
	ft_init2(st);
	return (len);
}
