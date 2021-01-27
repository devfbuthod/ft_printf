/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:27:04 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/02/18 10:27:10 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv_is_c(va_list ap, t_printf *st)
{
	char	c;
	int		res;

	c = va_arg(ap, int);
	res = st->taille_m;
	if (st->taille_m == 0)
		res = 1;
	else
		st->taille_m = st->taille_m - 1;
	res = print_space_zero(st, res);
	ft_putchar_fd(c, 1);
	st->i++;
	st->taille_m = 0;
	st->taille_p = -1;
	st->c = 0;
	return (res);
}
