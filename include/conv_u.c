/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:28:07 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/02/18 10:28:11 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv_is_u_minimum(t_printf *st, int len)
{
	if (st->taille_m > len)
		st->taille_m = st->taille_m - len;
	else
		st->taille_m = 0;
	if (st->c == '0' && st->taille_m != 0)
		len += print_zero(st);
	if (st->c == ' ' && st->taille_m != 0)
		len += print_space(st);
	st->taille_p = -1;
	return (len);
}

int		conv_is_u_precision(unsigned int u, t_printf *st, int len)
{
	int temp;

	temp = 0;
	if (st->taille_p > len)
		temp = st->taille_p - len;
	else
		temp = 0;
	len += print_zero_prec(temp);
	if (u != 0 || st->taille_p > 0)
		ft_putnbr_ui_fd(u, 1);
	else
		len = 0;
	return (len);
}

int		u_space_and_zero(unsigned int a, t_printf *st, int len)
{
	if (a == 4294967295 && st->taille_m > 10)
	{
		print_space_mini(st->taille_m - 10);
		ft_putstr_fd("4294967295", 1);
		return ((st->taille_m - 10) + 10);
	}
	if (st->taille_m > st->taille_p)
	{
		if (a == 0 && st->taille_m >= 1)
			st->nb_espace = st->taille_m - st->taille_p;
		else if (st->taille_m < len + st->taille_p)
			st->nb_espace = 0;
		else if (st->taille_m > len)
			st->nb_espace = st->taille_m - len;
	}
	if (st->taille_p > len)
		st->nb_zero = st->taille_p - len;
	st->taille_m = st->nb_espace;
	print_space(st);
	print_zero_prec(st->nb_zero);
	if (a != 0 || st->taille_p != 0)
		ft_putnbr_ui_fd(a, 1);
	else
		len = 0;
	return (st->nb_zero + st->nb_espace + len);
}

int		conv_is_u(va_list ap, t_printf *st)
{
	unsigned int	u;
	int				len;

	len = 0;
	u = va_arg(ap, unsigned int);
	len = ft_strlen_nbr_u(u, len);
	if (st->c == '1')
		len = u_space_and_zero(u, st, len);
	else if (st->taille_m != 0)
		len = conv_is_u_minimum(st, len);
	else if (st->taille_p != -1)
		len = conv_is_u_precision(u, st, len);
	if (st->taille_p == -1)
		ft_putnbr_ui_fd(u, 1);
	st->i++;
	st->taille_m = 0;
	st->taille_p = -1;
	st->c = 0;
	st->j = 0;
	st->t = 0;
	st->signe = 0;
	return (len);
}
