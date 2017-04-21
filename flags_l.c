/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 08:50:16 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 08:54:05 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		l_flags(char *str, int i, va_list *args, int *index)
{
	if (str[i + 1] == 'c' || str[i + 1] == 'C' || str[i + 1] == 'o'
			|| str[i + 1] == 'O' || str[i + 1] == 's' || str[i + 1] == 'p')
		*index = *index + 1;
	if (str[i] == 'l' && (str[i + 1] == 'd' || str[i + 1] == 'D'
				|| str[i + 1] == 'i'))
		return (print_ld((long)va_arg(*args, long int), index));
	else if (str[i] == 'l' && (str[i + 1] == 'u' || str[i + 1] == 'U'))
		return (print_lu_bg(va_arg(*args, unsigned long int), index));
	else if (str[i] == 'l' && (str[i + 1] == 'c' || str[i + 1] == 'C'))
		return (print_c(va_arg(*args, int)));
	else if (str[i] == 'l' && (str[i + 1] == 'o' || str[i + 1] == 'O'))
		return (print_lo(va_arg(*args, unsigned long int), 0, 0, 0));
	else if (str[i] == 'l' && (str[i + 1] == 's'))
		return (print_ls(va_arg(*args, wchar_t*)));
	else if (str[i] == 'l' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
		return (print_lx(va_arg(*args, unsigned long), str[i + 1], index, 1));
	else if (str[i] == 'l' && str[i + 1] == 'p')
		return (print_p(va_arg(*args, void *), 'p'));
	return (-1);
}

int		ll_flags(char *str, int i, va_list *args, int *index)
{
	if (str[i] == 'l' && str[i + 1] == 'l' && (str[i + 2] == 'd'
				|| str[i + 2] == 'D' || str[i + 2] == 'i'))
		return (print_lld(va_arg(*args, long long int), index) - 1);
	else if (str[i] == 'l' && str[i + 1] == 'l' && (str[i + 2] == 'u'
				|| str[i + 2] == 'U'))
		return (print_llu_bg(va_arg(*args, unsigned long long int), index));
	else if (str[i] == 'l' && str[i + 1] == 'l' && (str[i + 2] == 'o'
				|| str[i + 2] == 'O'))
	{
		*index = *index + 2;
		return (print_llo(va_arg(*args, unsigned long long int), 0, 0, 0));
	}
	else if (str[i] == 'l' && str[i + 1] == 'l' && (str[i + 2] == 'x'
				|| str[i + 2] == 'X'))
		return (print_llx(va_arg(*args, unsigned long long int), str[i + 2],
					index, 2));
		return (-1);
}
