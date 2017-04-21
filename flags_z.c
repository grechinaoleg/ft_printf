/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_z.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 08:54:29 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 08:55:20 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		z_flags(char *str, int i, va_list *args, int *index)
{
	if (str[i] == 'z' && (str[i + 1] == 'd' || str[i + 1] == 'D'
				|| str[i + 1] == 'i'))
		return (print_zd((size_t)va_arg(*args, size_t), index));
	else if (str[i] == 'z' && (str[i + 1] == 'u' || str[i + 1] == 'U'))
		return (print_zu(va_arg(*args, intmax_t), index));
	else if (str[i] == 'z' && (str[i + 1] == 'o' || str[i + 1] == 'O'))
		return (print_lo((size_t)va_arg(*args, size_t), index + 1, 1, 0));
	else if (str[i] == 'z' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
		return (print_lx((size_t)va_arg(*args, size_t), str[i + 1], index, 1));
	return (-1);
}
