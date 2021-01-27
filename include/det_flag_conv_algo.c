/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   det_flag_conv_algo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:28:27 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/02/18 10:28:30 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		det_conv(char *flag, va_list ap, t_printf *st)
{
	int len;

	len = 0;
	if (flag[st->i] == 'c')
		len = conv_is_c(ap, st);
	else if (flag[st->i] == 's')
		len = conv_is_s(ap, st);
	else if (flag[st->i] == 'p')
		len = conv_is_p(ap, st);
	else if (flag[st->i] == 'd' || flag[st->i] == 'i')
		len = conv_is_d(ap, st);
	else if (flag[st->i] == 'u')
		len = conv_is_u(ap, st);
	else if (flag[st->i] == 'x')
		len = conv_is_x(ap, st);
	else if (flag[st->i] == 'X')
		len = conv_is_x_maj(ap, st);
	else if (flag[st->i] == '%')
		len = conv_is_pour(st);
	return (len);
}

int		det_flags(char *flag, va_list ap, t_printf *st)
{
	int len;

	len = 0;
	if (ft_isdigit(flag[st->i]) && flag[st->i] != '0')
		len = flag_minimum_field(flag, ap, st);
	else if (flag[st->i] == '-')
		len = flag_dash(flag, ap, st);
	else if (flag[st->i] == '0')
		len = flag_zero(flag, ap, st);
	else if (flag[st->i] == '.')
		len = flag_dot(flag, ap, st);
	else if (flag[st->i] == '*')
		len = flag_star(flag, ap, st);
	return (len);
}

int		ft_algo(char *flag, va_list ap, t_printf *st)
{
	int len;

	len = 0;
	if (flag[st->i] == '-' || flag[st->i] == '0' || flag[st->i] == '.'
	|| flag[st->i] == '*' || ft_isdigit(flag[st->i]))
		len += det_flags(flag, ap, st);
	else
		len += det_conv(flag, ap, st);
	return (len);
}

int		flag_minimum_field(char *flag, va_list ap, t_printf *st)
{
	int temp;
	int len;
	int j;

	temp = 0;
	len = 0;
	j = 0;
	st->c = ' ';
	while (flag[st->i] && ft_isdigit(flag[st->i]))
	{
		if (j > 0)
			st->taille_m = st->taille_m * 10;
		st->taille_m = st->taille_m + (flag[st->i] - 48);
		st->i++;
		j++;
	}
	if (flag[st->i] == '-' || flag[st->i] == '0'
	|| flag[st->i] == '.' || flag[st->i] == '*' || ft_isdigit(flag[st->i]))
		len = det_flags(flag, ap, st);
	else
		len = det_conv(flag, ap, st);
	st->taille_m = 0;
	st->c = 0;
	return (len);
}

int		flag_zero(char *flag, va_list ap, t_printf *st)
{
	int len;

	len = 0;
	st->i++;
	st->c = '0';
	while (flag[st->i] && ft_isdigit(flag[st->i]))
	{
		if (st->taille_m != 0)
			st->taille_m = st->taille_m * 10;
		st->taille_m += ft_isdigit_res(flag[st->i]);
		st->i++;
	}
	if (flag[st->i] == '.')
	{
		st->c = '1';
		st->t = -4;
		len = flag_dot(flag, ap, st);
	}
	else if (flag[st->i] == '-' || flag[st->i] == '0'
	|| flag[st->i] == '.' || flag[st->i] == '*' || ft_isdigit(flag[st->i]))
		len = det_flags(flag, ap, st);
	else
		len = det_conv(flag, ap, st);
	return (len);
}
