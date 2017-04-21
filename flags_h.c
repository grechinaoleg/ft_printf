/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_h.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 08:42:13 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 08:48:18 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		h_flags(char *str, int i, va_list *args, int *index)
{
	if (str[i] == 'h' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
		return (print_hd((short int)va_arg(*args, int), index));
	else if (str[i] == 'h' && (str[i + 1] == 'u'))
		return (print_hu_bg((unsigned short)va_arg(*args, intmax_t), index));
	else if (str[i] == 'h' && (str[i + 1] == 'U' || str[i + 1] == 'D'))
		return (print_lu_bg((unsigned long)va_arg(*args, intmax_t), index));
	else if (str[i] == 'h' && (str[i + 1] == 'o' || str[i + 1] == 'O'))
		return (print_ho((unsigned short)va_arg(*args, intmax_t), 0, 0, 0));
	else if (str[i] == 'h' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
		return (print_hx((unsigned short)va_arg(*args, intmax_t),
					str[i + 1], index, 1));
		return (-1);
}

int		hh_flags(char *str, int i, va_list *args, int *index)
{
	if (str[i + 2] == 'd' || str[i + 2] == 'i' || str[i + 2] == 'D'
			|| str[i + 2] == 'U' || str[i + 2] == 'o'
			|| str[i + 2] == 'O' || str[i + 2] == 'S')
		*index = *index + 2;
	if (str[i] == 'h' && str[i + 1] == 'h' && (str[i + 2] == 'd'
				|| str[i + 2] == 'i'))
		return (print_hhd_i((signed char)va_arg(*args, intmax_t), 1));
	if (str[i] == 'h' && str[i + 1] == 'h' && (str[i + 2] == 'D'))
		return (print_ld((long)va_arg(*args, long int), index + 1));
	else if (str[i] == 'h' && str[i + 1] == 'h' && (str[i + 2] == 'u'))
		return (print_hhu_bg((unsigned char)va_arg(*args, intmax_t), index));
	else if (str[i] == 'h' && str[i + 1] == 'h' && (str[i + 2] == 'U'))
		return (print_u_bg((unsigned int)va_arg(*args, intmax_t)));
	else if (str[i] == 'h' && str[i + 1] == 'h' && (str[i + 2] == 'o'))
		return (print_hho((unsigned char)va_arg(*args, intmax_t), 0, 0, 0));
	else if (str[i] == 'h' && str[i + 1] == 'h' && (str[i + 2] == 'O'))
		return (print_o((unsigned int)va_arg(*args, intmax_t), 0, 0, 0));
	else if (str[i] == 'h' && str[i + 1] == 'h' && str[i + 2] == 'S')
		return (print_ls(va_arg(*args, wchar_t*)));
	else if (str[i] == 'h' && str[i + 1] == 'h' && (str[i + 2] == 'x'
				|| str[i + 2] == 'X'))
		return (print_hhx((unsigned char)va_arg(*args, intmax_t), str[i + 2],
					index, 2));
		return (-1);
}
