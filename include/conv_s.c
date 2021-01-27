/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:27:55 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/02/18 10:28:01 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv_is_s_minimum(char *str, t_printf *st, int len)
{
	if (st->taille_m > len)
		st->taille_m = st->taille_m - len;
	else
		st->taille_m = 0;
	if (st->c == '0' && st->taille_m != 0)
		len += print_zero(st);
	if (st->c == ' ' && st->taille_m != 0)
		len += print_space(st);
	ft_putstr_fd(str, 1);
	return (len);
}

int		conv_is_s_precision(char *str, t_printf *st, int len)
{
	if (st->taille_p != -1)
		len = ft_strlen_modified(str, st);
	if (st->taille_p != -1)
		ft_putstr_fd_modified(str, 1, st);
	else
		ft_putstr_fd(str, 1);
	return (len);
}

int		s_space_and_zero(char *str, t_printf *st)
{
	int taille_str;
	int nb_espace;
	int len;

	taille_str = 0;
	nb_espace = 0;
	len = 0;
	if ((int)ft_strlen(str) > st->taille_p)
		taille_str = st->taille_p;
	else
		taille_str = ft_strlen(str);
	if (st->taille_m > taille_str)
		nb_espace = st->taille_m - taille_str;
	st->taille_m = nb_espace;
	print_space(st);
	ft_putstr_fd_modified(str, 1, st);
	len = nb_espace + taille_str;
	return (len);
}

int		conv_is_s(va_list ap, t_printf *st)
{
	char	*str;
	int		len;

	len = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (st->taille_p < -1)
		st->taille_p = ft_strlen(str);
	if (st->taille_m < 0)
		st->taille_m = 0;
	if (st->c == '1')
		len = s_space_and_zero(str, st);
	else if (st->taille_p != -1)
		len = conv_is_s_precision(str, st, len);
	else if (st->taille_m != 0)
		len = conv_is_s_minimum(str, st, len);
	else
		ft_putstr_fd(str, 1);
	st->i++;
	st->taille_m = 0;
	st->taille_p = -1;
	st->c = 0;
	return (len);
}
