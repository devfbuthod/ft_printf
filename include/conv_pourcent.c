/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_pourcent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:27:48 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/02/18 10:27:51 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pour_space_and_zero(t_printf *st)
{
	int temp;
	int len;

	len = 1;
	temp = st->taille_m;
	while (temp != 0)
	{
		ft_putchar_fd(' ', 1);
		temp--;
		len++;
	}
	return (len);
}

int		conv_is_pour(t_printf *st)
{
	int len;

	len = st->taille_m;
	if (st->taille_m == 0)
		len = 1;
	else
		st->taille_m = st->taille_m - 1;
	if (st->c == '0' || st->t == -4)
		len = print_zero(st) + 1;
	else if (st->c == ' ')
		len = print_space(st) + 1;
	else if (st->c == '1')
		len = pour_space_and_zero(st);
	ft_putchar_fd('%', 1);
	st->i++;
	st->taille_m = 0;
	st->taille_p = -1;
	st->c = 0;
	return (len);
}
