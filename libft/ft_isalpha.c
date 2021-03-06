/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:05:18 by gafreita          #+#    #+#             */
/*   Updated: 2022/03/03 21:05:32 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (!(c >= 'A' && c <= 'Z')
		&& !(c >= 'a' && c <= 'z'))
		return (0);
	return (1);
}
