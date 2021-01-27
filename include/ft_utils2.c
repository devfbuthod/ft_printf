/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:29:25 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/02/18 10:29:27 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd_2(int n, int fd, t_printf *st, int nb_zero)
{
	int i;
	int j;

	i = 0;
	j = st->taille_p + 1;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	print_zero_prec(nb_zero);
	if (n >= 10 && j != 0)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + 48, fd);
		j--;
	}
	else if (n < 10 && n != -2147483648 && j != 0)
	{
		ft_putchar_fd(n + 48, fd);
		j--;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*new_chaine;

	j = 0;
	if (s == NULL || (start > ft_strlen(s)) || len == 0)
		return (ft_calloc(1, 1));
	if (!(new_chaine = malloc((len + 1) * sizeof(char))))
		return (0);
	while (s[start] && j <= (len - 1))
		new_chaine[j++] = s[start++];
	new_chaine[j] = 0;
	return (new_chaine);
}

int		ft_strlen_nbr(int n, int i)
{
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	if (n < 10 && n != -2147483648)
		i++;
	return (i);
}

int		ft_strlen_nbr_modified(int n, int i, t_printf *st)
{
	int j;

	j = st->taille_p;
	if (n == -2147483648)
		return (11);
	if (n < 0 && j != 0)
	{
		n = -n;
		i++;
		j--;
	}
	while (n >= 10 && j != 0)
	{
		n = n / 10;
		i++;
		j--;
	}
	if (n < 10 && n != -2147483648 && j != 0)
	{
		i++;
		j--;
	}
	return (i);
}

int		ft_isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	return (0);
}
