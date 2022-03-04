/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:05:33 by gafreita          #+#    #+#             */
/*   Updated: 2022/03/04 21:56:15 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf(char *str, ...)
{
	char	*index;
	size_t	len;
	size_t	start;

	/* checar os % coisas */
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
		check_identifier(*str);
		str++;
	}
}
