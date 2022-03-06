/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:05:33 by gafreita          #+#    #+#             */
/*   Updated: 2022/03/06 17:51:54 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base(long long int n, char *base);
static int	print_addres(void *ptr);
static int	check_identifier(const char c, va_list args);
static int	ft_putchar_str(va_list args, const char c);

int	ft_printf(const char *s, ...)
{
	char	*index;
	size_t	len;
	int		count;
	va_list	arguments;

	va_start(arguments, s);
	count = 0;
	while (s)
	{
		index = ft_strchr(s, '%');
		if (index == 0)
		{
			count += write(1, s, ft_strlen(s));
			break ;
		}
		len = (size_t)index - (size_t)s;
		index = ft_substr(s, 0, len + 1);
		count += write(1, index, len);
		s += len;
		count += check_identifier(*(++s), arguments);
		s++;
		free (index);
	}
	va_end(arguments);
	return (count);
}

static int	ft_putnbr_base(long long int n, char *base)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count += write(1, "-", 1);
		n *= -1;
	}
	if (n >= (long long int)ft_strlen(base))
	{
		ft_putnbr_base(n / ft_strlen(base), base);
		ft_putnbr_base(n % ft_strlen(base), base);
	}
	else
		count += write(1, &base[n], 1);
	return (count);
}

static int	print_addres(void *ptr)
{
	char		hex[12];
	int			i;
	int			count;
	uintptr_t	num;

	num = (uintptr_t) ptr;
	count = write (1, "0x", 2);
	i = 12;
	while (--i >= 0)
	{
		hex[i] = "0123456789abcdef"[num % 16];
		num = num / 16;
	}
	count += write(1, hex, 12);
	return (count);
}

static int	ft_putchar_str(va_list args, const char c)
{
	int		count;
	char	aux;
	char	*str;

	if (c == 'c')
	{
		aux = va_arg(args, int);
		count = write (1, &aux, 1);
	}
	else
	{
		str = va_arg(args, char *);
		count = write (1, str, ft_strlen(str));
	}
	return (count);
}

static int	check_identifier(const char c, va_list args)
{
	int		count;

	if (c == 'd' || c == 'i')
		count = ft_putnbr_base(va_arg(args, int), "0123456789");
	if (c == 'u')
		count = ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	if (c == 'x')
		count = ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
	if (c == 'X')
		count = ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
	if (c == '%')
		count = write(1, "%%", 1);
	if (c == 'p')
		count = print_addres(va_arg(args, void *));
	if (c == 's' || c == 'c')
		count = ft_putchar_str(args, c);
	return (count);
}
