/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:29:06 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/02/18 10:29:08 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_modified(const char *s, t_printf *st)
{
	int i;
	int j;

	i = 0;
	j = st->taille_p;
	while (s[i] && j != 0)
	{
		i++;
		j--;
	}
	return (i);
}

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ps;
	int				i;
	int				limite;

	i = 0;
	limite = n;
	ps = (unsigned char*)s;
	while (i < limite)
	{
		ps[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*ptr;

	total = nmemb * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	return (ft_memset(ptr, 0, total));
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
