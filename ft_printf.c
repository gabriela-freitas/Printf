/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:05:33 by gafreita          #+#    #+#             */
/*   Updated: 2022/03/04 22:24:48 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_identifier(char c, va_list args)
{
	char	*aux;

	if (c == 'c')
		write (1, va_arg(args, (char *)), 1); //aqui ele ta um void * e tudo certo
	if (c == 'd' || c == 'i')
		ft_putnbr_fd(1, (va_arg(args, int));
		
}

void	ft_printf(char *str, ...)
{
	char	*index;
	size_t	len;
	size_t	start;
	va_list	arguments;

	va_start(arguments, str);
	/* checar os % coisas */
	/*falta os argumentos fofa*/
	start = 0;
	while (str)
	{
		index = ft_strchar(str, '%');
		if (index == 0)
		{
			write(1, str, ft_strlen(str));
			break ;
		}
		len = size_t(index - str);
		write(1, ft_substr(str, start, len + 1), len);
		start += len; /* isso mesmo? */
		str += len; //ajeitar os indices
		check_identifier(*str++, arguments);
		str++;
	}
	va_end(arguments, str);
}
