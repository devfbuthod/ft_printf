/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:19:39 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/02/18 14:19:43 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_printf *st)
{
	st->i = 0;
	st->len = 0;
	st->res = 0;
	st->j = 0;
	st->taille_p = -1;
	st->taille_m = 0;
	st->t = 0;
	st->c = 0;
	st->temp = 0;
	st->nb_espace = 0;
	st->nb_zero = 0;
	st->temp = 0;
	st->len = 0;
	st->signe = 0;
	st->a = 0;
}

void	ft_init2(t_printf *st)
{
	st->taille_m = 0;
	st->taille_p = -1;
	st->c = 0;
	st->j = 0;
	st->t = 0;
	st->signe = 0;
}

int		ft_printf(const char *fmt, ...)
{
	int			len;
	va_list		ap;
	t_printf	st[1];

	ft_init(st);
	va_start(ap, fmt);
	len = 0;
	while (fmt[st->i])
	{
		if (fmt[st->i] != '%')
		{
			ft_putchar_fd(fmt[st->i], 1);
			st->i++;
			len++;
		}
		else if (fmt[st->i] == '%')
		{
			st->i++;
			len += ft_algo((char *)fmt, ap, st);
		}
	}
	return (len);
}
