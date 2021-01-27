/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:28:33 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/02/18 10:28:36 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_dot(char *flag, va_list ap, t_printf *st)
{
	int len;

	len = 0;
	st->i++;
	st->taille_p = 0;
	st->j = -1;
	while (flag[st->i] && ft_isdigit(flag[st->i]))
	{
		if (st->taille_p != 0)
			st->taille_p = st->taille_p * 10;
		st->taille_p += ft_isdigit_res(flag[st->i]);
		st->i++;
	}
	if (st->c == ' ' || st->c == '0')
		st->c = '1';
	if (flag[st->i] == '-' || flag[st->i] == '0' || flag[st->i] == '.'
	|| flag[st->i] == '*' || ft_isdigit(flag[st->i]))
		len = det_flags(flag, ap, st);
	else
		len = det_conv(flag, ap, st);
	return (len);
}

int		flag_dash_follow(char *flag, va_list ap, t_printf *st)
{
	if (flag[st->i] == '-' || flag[st->i] == '0'
	|| flag[st->i] == '.' || ft_isdigit(flag[st->i]))
		st->len = det_flags(flag, ap, st);
	else
		st->len = det_conv(flag, ap, st);
	st->temp -= st->len;
	if (st->temp <= 0)
		st->temp = 0;
	st->len += st->taille_m;
	if (st->taille_m != 0)
		print_space(st);
	else
	{
		while (st->temp != 0)
		{
			ft_putstr_fd(" ", 1);
			st->temp--;
			st->len++;
		}
	}
	return (0);
}

int		flag_dash(char *flag, va_list ap, t_printf *st)
{
	st->j = -2;
	st->temp = st->taille_m;
	st->len = 0;
	st->i++;
	if (st->j != -3)
		st->taille_m = 0;
	while (flag[st->i] && ft_isdigit(flag[st->i]))
	{
		if (st->temp != 0)
			st->temp = st->temp * 10;
		st->temp += ft_isdigit_res(flag[st->i]);
		st->i++;
	}
	if (flag[st->i] == '*')
	{
		st->temp = va_arg(ap, int);
		if (st->temp < 0)
			st->temp = -st->temp;
		st->t = -1;
		st->i++;
	}
	flag_dash_follow(flag, ap, st);
	st->c = 0;
	return (st->len);
}

int		flag_star_follow(char *flag, va_list ap, t_printf *st, int len)
{
	if (st->taille_m < 0)
	{
		st->taille_m = -st->taille_m;
		if (flag[st->i] == '.')
			st->j = -3;
		st->i--;
		len = flag_dash(flag, ap, st);
	}
	else if (flag[st->i] == '-' || flag[st->i] == '0'
	|| flag[st->i] == '.' || flag[st->i] == '*' || ft_isdigit(flag[st->i]))
		len += det_flags(flag, ap, st);
	else
		len += det_conv(flag, ap, st);
	return (len);
}

int		flag_star(char *flag, va_list ap, t_printf *st)
{
	int len;

	len = 0;
	st->i++;
	if (st->j == -1)
		st->taille_p = va_arg(ap, int);
	else if (st->c == '0')
		st->taille_m = va_arg(ap, int);
	else if (st->taille_m == 0 && st->t != -1)
	{
		st->c = ' ';
		st->taille_m = va_arg(ap, int);
	}
	else
		st->taille_m = va_arg(ap, int);
	len = flag_star_follow(flag, ap, st, len);
	return (len);
}
