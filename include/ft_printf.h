/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:28:52 by fbuthod-          #+#    #+#             */
/*   Updated: 2020/02/18 14:29:57 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef	struct	s_printf
{
	int		i;
	int		len;
	int		res;
	int		j;
	int		taille_p;
	int		taille_m;
	char	c;
	int		t;
	int		temp;
	int		nb_espace;
	int		nb_zero;
	int		signe;
	int		a;
}				t_printf;

int				ft_printf(const char *fmt, ...);

void			ft_putchar_fd(char c, int fd);

int				flag_dot(char *flag, va_list ap, t_printf *st);

int				flag_dash(char *flag, va_list ap, t_printf *st);

int				flag_star(char *flag, va_list ap, t_printf *st);

int				flag_minimum_field(char *flag, va_list ap, t_printf *st);

int				flag_zero(char *flag, va_list ap, t_printf *st);

int				conv_is_c(va_list ap, t_printf *st);

int				conv_is_d_minimum(int a, t_printf *st, int len);

int				conv_is_d_precision(int a, t_printf *st, int signe);

int				d_space_and_zero(int a, t_printf *st, int len);

int				conv_is_d(va_list ap, t_printf *st);

int				conv_is_p(va_list ap, t_printf *st);

int				pour_space_and_zero(t_printf *st);

int				conv_is_pour(t_printf *st);

int				conv_is_s_minimum(char *str, t_printf *st, int len);

int				conv_is_s_precision(char *str, t_printf *st, int len);

int				s_space_and_zero(char *str, t_printf *st);

int				conv_is_s(va_list ap, t_printf *st);

int				conv_is_u_minimum(t_printf *st, int len);

int				conv_is_u_precision(unsigned int u, t_printf *st, int len);

int				u_space_and_zero(unsigned int a, t_printf *st, int len);

int				conv_is_u(va_list ap, t_printf *st);

int				conv_is_x_maj_minimum(t_printf *st, int len);

int				conv_is_x_maj_precision(int x, t_printf *st, int len);

int				x_maj_space_and_zero(unsigned int a, t_printf *st, int len);

int				conv_is_x_maj(va_list ap, t_printf *st);

int				conv_is_x_minimum(t_printf *st, int len);

int				conv_is_x_precision(int x, t_printf *st, int len);

int				x_space_and_zero(unsigned int a, t_printf *st, int len);

int				conv_is_x(va_list ap, t_printf *st);

int				det_conv(char *flag, va_list ap, t_printf *st);

int				det_flags(char *flag, va_list ap, t_printf *st);

int				ft_algo(char *flag, va_list ap, t_printf *st);

int				flag_dot(char *flag, va_list ap, t_printf *st);

int				flag_dash(char *flag, va_list ap, t_printf *st);

int				flag_star(char *flag, va_list ap, t_printf *st);

int				flag_minimum_field(char *flag, va_list ap, t_printf *st);

int				flag_zero(char *flag, va_list ap, t_printf *st);

void			ft_init(t_printf *st);

size_t			ft_strlen_modified(const char *s, t_printf *st);

size_t			ft_strlen(const char *s);

void			*ft_memset(void *s, int c, size_t n);

void			*ft_calloc(size_t nmemb, size_t size);

void			ft_putstr_fd_modified(char *s, int fd, t_printf *st);

void			ft_putstr_fd(char *s, int fd);

void			ft_putnbr_fd(int n, int fd);

void			ft_putnbr_fd_modified(int n, int fd, t_printf *st);

int				print_zero_prec(int i);

void			ft_putnbr_fd_2(int n, int fd, t_printf *st, int nb_zero);

char			*ft_substr(char const *s, unsigned int start, size_t len);

int				ft_strlen_nbr(int n, int i);

int				ft_strlen_nbr_modified(int n, int i, t_printf *st);

int				ft_isdigit(int c);

char			ft_isdigit_res(int c);

int				ft_strlen_nbr_u(unsigned int n, int i);

int				ft_strlen_nbr_x(unsigned int n, int i);

int				ft_putnbr_ui_fd(unsigned int n, int fd);

int				ft_putnbr_base(long n);

int				ft_putnbr_base_res(long n, int *res);

int				ft_putnbr_base_maj(long n);

int				ft_putnbr_base_maj_res(long n, int *res);

int				ft_putnbr_base_p(unsigned long long n);

int				ft_putnbr_base_p_res(unsigned long long n, int *res);

int				len_str(char *fmt);

int				res_result(const char *nptr, int compt);

int				ft_atoi(const char *nptr);

int				print_space(t_printf *st);

int				print_space_mini(int i);

int				print_zero(t_printf *st);

int				print_space_zero(t_printf *st, int res);

void			ft_init2(t_printf *st);

#endif
