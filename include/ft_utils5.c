/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:29:44 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/02/18 10:29:46 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len_str(char *fmt)
{
	int i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
			return (i);
		i++;
	}
	return (i);
}

int		res_result(const char *nptr, int compt)
{
	int result;
	int nb;
	int i;

	i = compt;
	result = 0;
	nb = 0;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		nb = nptr[i] - 48;
		if (result == 0)
			result = nb;
		else
			result = (result * 10) + nb;
		i++;
	}
	return (result);
}

int		ft_atoi(const char *nptr)
{
	int i;
	int signe;
	int result;

	i = 0;
	signe = 0;
	result = 0;
	while (nptr[i] == '\a' ||
			nptr[i] == '\t' ||
			nptr[i] == '\n' ||
			nptr[i] == '\r' || nptr[i] == '\v'
			|| nptr[i] == '\f' || nptr[i] == ' '
			|| nptr[i] == '+')
		i++;
	if (nptr[i] == 45 && nptr[i - 1] != '+')
	{
		signe = 1;
		i++;
	}
	else if (nptr[i] == 61)
		i++;
	result = res_result(nptr, i);
	if (signe == 1)
		result = result * -1;
	return (result);
}

int		print_space(t_printf *st)
{
	int res;

	res = 0;
	while (st->taille_m != 0)
	{
		ft_putstr_fd(" ", 1);
		st->taille_m--;
		res++;
	}
	st->taille_m = 1;
	return (res);
}

int		print_space_mini(int i)
{
	int res;

	res = 0;
	while (i != 0)
	{
		ft_putstr_fd(" ", 1);
		i--;
		res++;
	}
	return (res);
}
