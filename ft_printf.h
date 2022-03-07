/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:41:23 by gafreita          #+#    #+#             */
/*   Updated: 2022/03/07 20:54:25 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	int_count(long long int n, int len);
int	unsigned_count(unsigned long n, int len);
int	ft_u_add(uintptr_t n, char *base);

#endif
