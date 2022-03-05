/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:05:33 by gafreita          #+#    #+#             */
/*   Updated: 2022/03/05 23:06:21 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_putnbr_base(long long int n, char *base);
static int	print_addres(void *ptr);
static int	check_identifier(const char c, va_list args);

int	ft_printf(char *str, ...)
{
	char	*index;
	size_t	len;
	size_t	start;
	int		count;
	va_list	arguments;

	va_start(arguments, str);
	start = 0;
	count = 0;
	while (str)
	{
		index = ft_strchr(str, '%');
		//printf("\nindex: %s", index);
		if (index == 0)
		{
			count += write(1, str, ft_strlen(str));
			break ;
		}
		len = (size_t)index - (size_t)str;
		//printf("\nlen: %zu\nstart: %zu", len, start);
		count += write(1, ft_substr(str, start, len + 1), len);
		start += len + 2;
		str += len;
		count += check_identifier(*(++str), arguments);
		str++;
		//str++;
		//printf("\nchar: %c\n", *str);
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
	if (n >= ft_strlen(base))
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

static int	check_identifier(const char c, va_list args)
{
	char	*aux;
	int		count;

	if (c == 'c')
		count = write (1, va_arg(args, char *), 1); //aqui ele ta um void * e tudo certo
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
	if (c == 's')
	{
		aux = va_arg(args, char *);
		count = write (1, aux, ft_strlen(aux));
	}
	return (count);
}

int main ()
{
	int a = 12;
	int b = 348389;
	//ft_printf("Hello World!\n");
	ft_printf("Here is a number: %d*And dont worry, another number: %d*", a, b);
}
