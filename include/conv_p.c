/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:27:37 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/02/18 10:27:42 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		p_space_and_zero2(unsigned long long a, t_printf *st, int len)
{
	if (a < 0 && st->taille_p > (len - 1))
		st->nb_zero = st->taille_p - (len - 1);
	else if (st->taille_p > (len + 2))
		st->nb_zero = st->taille_p - (len + 2);
	st->taille_m = st->nb_espace;
	print_space(st);
	if (a > 0)
	{
		print_zero_prec(st->nb_zero);
		len = 0;
	}
	else if (a != 0 && st->taille_p != 0)
		ft_putnbr_fd_2(a, 1, st, st->nb_zero);
	else
		len = -1;
	len = st->nb_zero + st->nb_espace + len;
	return (len);
}

int		p_space_and_zero(unsigned long long a, t_printf *st, int len)
{
	if (st->taille_p < 0)
		st->taille_p = ft_putnbr_base_p_res(a, &len);
	if (st->taille_m < 0)
		st->taille_m = ft_putnbr_base_p_res(a, &len);
	if (st->taille_m > st->taille_p)
	{
		if ((st->taille_m > st->taille_p) && a >= 0)
			st->nb_espace = st->taille_m - st->taille_p;
		else if (st->taille_m < (len + 2) + st->taille_p)
			st->nb_espace = 0;
		else if (st->taille_m > (len + 2))
			st->nb_espace = st->taille_m - (len + 2);
	}
	len = p_space_and_zero2(a, st, len);
	return (len);
}

int		conv_is_p2(t_printf *st, int len, unsigned long long p, int temp)
{
	if (p == 0 && st->taille_m == 0 && st->taille_p == 0)
		len = 0;
	else if (st->c == '0' && st->taille_m != 0)
		len += print_zero(st);
	else if (st->c == ' ' && st->taille_m != 0)
		len += print_space(st);
	else if (st->c == '1')
		len += p_space_and_zero(p, st, len);
	temp = len + 2;
	len = 0;
	ft_putstr_fd("0x", 1);
	if (p != 0 || st->taille_p == -1)
		len = ft_putnbr_base_p(p);
	st->i++;
	st->c = 0;
	st->taille_m = 0;
	st->taille_p = -1;
	return (temp);
}

int		conv_is_p(va_list ap, t_printf *st)
{
	int					temp;
	unsigned long long	p;
	int					len;

	len = 0;
	temp = 0;
	p = va_arg(ap, unsigned long long);
	len = ft_putnbr_base_p_res(p, &len);
	if (st->taille_p == 0 && p == 0 && st->taille_m > (len + 2))
		st->taille_m = st->taille_m - 2;
	else if (st->taille_m > (len + 2))
		st->taille_m = st->taille_m - len - 2;
	else
		st->taille_m = 0;
	temp = conv_is_p2(st, len, p, temp);
	return (temp);
}
